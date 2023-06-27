#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_OF_STRING 100

//----------STRUKTURY HASHOVACI TABULKY (RETEZENI)----------

//struktuta pro uzel
typedef struct node{
    char data[MAX_LENGTH_OF_STRING];    //ulozeni retezce znaku
    struct node* next;                  //poineter na dalsi uzel v retezci
} node;

//struktura pro tabulku
typedef struct chaining_table{
    int size;               //velikost tabulky
    int (*hash)(char*);     //pointer na hashovaci funkci
    node** array;           //pole ukazatelu na uzly
} chaining_table;

//----------HASHOVACI FUNKCE----------
int crc32b(char* str) {
    /*int i, j;
    unsigned int byte, crc, mask;

    i = 0;
    crc = 0xFFFFFFFF;
    while (str[i] != 0){
        byte = str[i];
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--){
            mask =  -(crc & 1);
            crc = (crc >> 1)^(0xEDB88320 & mask);
        }
        i = i + 1;
    }
    return ~crc;*/
    int ret = str[0] % 8;
    return ret;
}

//----------FUNKCE PRO HASHOVACI TABULKY NAD RETEZCI S RESENIM KOLIZI RETEZENIM----------

//funkce, ktera vytvari novou hashovaci tabulku
//se specifikovanou velikosti a hashovaci funkci
chaining_table* create_chaining_table(int size, int (*hash)(char*)){
    chaining_table* table = (chaining_table*)malloc(sizeof(chaining_table));
    if (table == NULL){
        printf("Failed to allocate memory\n");
        return NULL;
    }
    table->size = size;
    table->hash = hash;

    table->array = (node**)calloc(size, sizeof(node*));
    if (table->array == NULL){
        printf("Failed to allocate memory\n");
        free(table->array);
        free(table);
        return NULL;
    }

    return table;
}

//funkce pridava novy uzel do hashovaci tabulky pro zadany retezec
int add_ct(char* data, chaining_table* table){

    //vypocet hodnoty hash pro retezec a urci index v poli poinetru na uzly
    //na zaklade hodnoty hash  a velikosti tabulky a prida novy uzel

    int key = table->hash(data) % table->size;

    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL){
        printf("Failed to allocate memory\n");
        return 0;
    }
    strcpy(new_node->data, data);
    new_node->next = table->array[key];
    table->array[key] = new_node;

    return 1;
}

//funkce, ktera odebere uzel hashovaci tabulky pro zadany retezec
int remove_ct(char* data, chaining_table* table){

    //vypocet hodnoty hash pro retezec a urci index v poli poinetru na uzly
    //na zaklade hodnoty hash  a velikosti tabulky a iteruje retezec na tomto indexu
    //pokud je uzel nalezen, je odstrane z retezece a je uvolnena pamet

    int key = table->hash(data) % table->size;
    node* current_node = table->array[key];
    node* previous_node = NULL;

    while (current_node != NULL){
        if (strcmp(current_node->data, data) == 0){
            if (previous_node == NULL){
                table->array[key] = current_node->next;
            }else{
                previous_node->next = current_node->next;
            }
            free(current_node);
            return 1;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    return 0;
}

//funkce, ktera kontroluje, zda v hashovaci tabulce existuje uzel se zadanym retezecem
int contains_ct(char* data, chaining_table* table){

    //vypocita hodnotu hash pro retezec a urci index v poli pointeru na uzly
    //na zaklade hodnoty hash a velikosti tabulky a iteruje retezec na tomto indexu
    //pokud je uzel nalezen vrati 1, pokud ne vrati 0

    int key = table->hash(data) % table->size;
    node* current_node = table->array[key];

    while (current_node != NULL){
        if (strcmp(current_node->data, data) == 0){
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

//----------STRUKTURY HASHOVACI TABULKY (OTEVRENE HASHOVANI)----------

//struktura pro vstup (zaznam) hashovaci tabulky
typedef struct oa_entry {
    char* data;
    int deleted; //hodnota, ktera eviduje, jestli byl zaznam smazan
} oa_entry;

//struktura pro hashovaci tabulku
typedef struct oa_table{
    oa_entry* entries;              //pole zaznamu
    int size;                       //velikost tabulky
    int (*hash)(char*);             //pointer na hashovaci funkci
    int (*probe)(int, int, int);    //pointer na pruzkumnou funkci
} oa_table;

//----------FUNKCE PRO HASHOVACI TABULKY NAD RETEZCI S RESENIM KOLIZI OTEVRENYM ADRESOVANIM----------

//lienarni pruzkumna funkce
int linear_probe(int index, int attempt, int size){
    return (index + attempt) % size;
}

//kvadraticka pruzkumna funkce
int quadratic_probe(int index, int attempt, int size){
    return (index + attempt * attempt) % size;
}

//funkce, ktera vytvori novou hashovaci tabulku s otevrenym adresovanim
oa_table* create_oa_table(int size, int (*hash)(char*), int (*probe)(int, int, int)){

    oa_table* table = (oa_table*) malloc(sizeof(oa_table));
    if (table == NULL){
        printf("Failed to allocate memory\n");
        return NULL;
    }
    table->entries = (oa_entry*) calloc(size, sizeof(oa_entry));
    if (table->entries == NULL){
        printf("Failed to allocate memory\n");
        return NULL;
    }
    table->size = size;
    table->hash = hash;
    table->probe = probe;

    return table;
}

//funkce, ktera pridava novy uzel do hashovaci tabulky pro zadany retezec
int add_oat(char* data, oa_table* table){

    //vypocita se hodnota hash pro retezec a pomoci pruzkumne funkce najde
    //index v hashovaci tabulce, kam vlozit zaznam
    int index = table->hash(data) % table->size;
    int attempt = 0;
    while (attempt < table->size){
        if (table->entries[index].data == NULL || table->entries[index].deleted) {
            if (table->entries[index].deleted) {
                free(table->entries[index].data);
            }

            //pokud funkce najde volne misto, ulozi zaznam na toto misto
            table->entries[index].data = strdup(data);

            //nastavi hodnotu deleted na false (0)
            table->entries[index].deleted = 0;
            return 1;

        //pokud je polozka se stejnym zaznamem uz v tabulce
        }else if (strcmp(table->entries[index].data, data) == 0){
            return 0; //funkce vrati 0 bez provedeni jakychkoli zmen

        }else{
            index = table->probe(index, ++attempt, table->size);
        }
    }
    return 0; //pokud je tabulka plna, funkce vrati 0
}

//funkce, ktera odebere uzel hashovaci tabulky pro zadany retezec
int remove_oat(char* data, oa_table* table){

    //vypocita se hodnota hash pro retezec a pomoci pruzkumne funkce najde
    //zaznam s temito daty

    int index = table->hash(data) % table->size;
    int attempt = 0;
    while (attempt < table->size){
        if (table->entries[index].data != NULL && !table->entries[index].deleted &&
            strcmp(table->entries[index].data, data) == 0){
            free(table->entries[index].data);

            //pokud je zaznam nalezen funkce uvolni pamet pridelenou pro dana data
            table->entries[index].data = NULL;

            //nastavi hodnotu deleted na true (1)
            table->entries[index].deleted = 1;
            return 1;

        }else{
            index = table->probe(index, ++attempt, table->size);
        }
    }
    return 0; //pokud polozka neni nalezena, funkce vrati 0
}

//funkce, ktera kontroluje, zda v hashovaci tabulce existuje uzel se zadanym retezecem
int contains_oat(char* data, oa_table* table){

    //vypocita se hodnota hash pro retezec a pomoci pruzkumne funkce najde
    //zaznam s temito daty

    int index = table->hash(data) % table->size;
    int attempt = 0;
    while (attempt < table->size) {
        if (table->entries[index].data != NULL && !table->entries[index].deleted &&
            strcmp(table->entries[index].data, data) == 0){
            return 1; //pokud je zaznam nalezen, funkce vrati 1
        } else {
            index = table->probe(index, ++attempt, table->size);
        }
    }
    return 0; //pokud neni zaznma nalezen, funkce vrati 0
}


int main() {

//PRIKLADY POUZITI FUNKCI PRO HASHOVACI TABULKY NAD RETEZCI S RESENIM KOLIZI RETEZENIM

    chaining_table* table = create_chaining_table(100, crc32b);
/*
    //pridani zaznamu do hashovaci tabulky
    add_ct("tyranosaurus", table);
    add_ct("triceratops", table);
    add_ct("stegosaurus", table);

    //kontrola, jestli hashovaci tabulka obsahuje zaznam
    printf("%i\n", contains_ct("tyranosaurus", table)); //1
    printf("%i\n", contains_ct("triceratops", table));  //1
    printf("%i\n", contains_ct("velociraptor", table)); //0

    //odstraneni zaznamu z hashovaci tabulky
    remove_ct("triceratops", table);

    //kontrola, jestli hashovaci tabulka stale obsahuje vymazany zaznam
    printf("%i\n", contains_ct("triceratops", table));  //0
    */

//PRIKLADY POUZITI FUNKCI PRO HASHOVACI TABULKY NAD RETEZCI S RESENIM KOLIZI OTEVRENYM ADRESOVANIM

//vytvoreni hashovaci tabulky s linearni pruzkumnou funkci
    oa_table* table_linear = create_oa_table(10, crc32b, linear_probe);

    //pridani zaznamu do hashovaci tabulky
    add_oat("velociraptor", table_linear);
    add_oat("allosaurus", table_linear);
    add_oat("diplodocus", table_linear);

    //odstraneni zaznamu z hashovaci tabulky
    remove_oat("allosaurus", table_linear);

    //kontrola, jestli hashovaci tabulka stale obsahuje vymazany zaznam
    printf("%i\n", contains_oat("velociraptor", table_linear)); //1
    printf("%i\n", contains_oat("allosaurus", table_linear));   //0


//vytvoreni hashovaci tabulky s kvadratickou pruzkumnou funkci
    oa_table* table_quadratic = create_oa_table(10, crc32b, quadratic_probe);

    //pridani zaznamu do hashovaci tabulky
    add_oat("velociraptor", table_quadratic);
    add_oat("brachiosaurus", table_quadratic);
    add_oat("pterodactylus", table_quadratic);

    //odstraneni zaznamu z hashovaci tabulky
    remove_oat("brachiosaurus", table_quadratic);

    //kontrola, jestli hashovaci tabulka stale obsahuje vymazany zaznam
    printf("%i\n", contains_oat("pterodactylus", table_quadratic)); //1
    printf("%i\n", contains_oat("brachiosaurus", table_quadratic)); //0

    free(table);
    free(table_linear);
    free(table_quadratic);
    return 0;
}
