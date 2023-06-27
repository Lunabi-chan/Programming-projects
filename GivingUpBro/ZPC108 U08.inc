typedef enum { kus=1,kg } Jednotka;
typedef union { int kus; float kg; } Mnozstvi;
typedef enum { rohlik,chleb,brambory,sirup,merunky,cukr,cokolada,salam,mleko,kava,pivo,mouka,maso,sul,kmin,fazole,meloun } Potravina;
typedef struct { Potravina potr; Jednotka jedn; Mnozstvi mnoz; } Pohyb;

const Pohyb pohyb[]={{chleb,kg,{.kg=20}},{cukr,kg,{.kg=10}},{rohlik,kus,{.kus=70}},{cokolada,kus,{.kus=15}},{kava,kg,{.kg=2}},{mouka,kg,{.kg=5}},
                     {salam,kg,{.kg=6.5}},{mleko,kus,{.kus=30}},{brambory,kg,{.kg=40}},{merunky,kg,{.kg=8}},{sirup,kus,{.kus=18}},{mouka,kg,{.kg=5}},
                     {cukr,kg,{.kg=-1.5}},{cokolada,kus,{.kus=-2}},{brambory,kg,{.kg=-5}},{rohlik,kus,{.kus=-10}},{pivo,kus,{.kus=10}},
					 {kmin,kg,{.kg=.06}},{fazole,kg,{.kg=5}},{chleb,kg,{.kg=-1}},{mleko,kus,{.kus=-2}},{sirup,kus,{.kus=-1}},{pivo,kus,{.kus=25}},
					 {kava,kg,{.kg=6.5}},{mouka,kg,{.kg=-4}},{fazole,kg,{.kg=-.5}},{cukr,kg,{.kg=-2}},{cokolada,kus,{.kus=-3}},{sul,kg,{.kg=6}},
					 {brambory,kg,{.kg=-3.5}},{merunky,kg,{.kg=-.5}},{sirup,kus,{.kus=-3}},{mouka,kg,{.kg=5}},{pivo,kus,{.kus=-1}},
					 {mouka,kg,{.kg=-2}},{maso,kg,{.kg=10}},{maso,kg,{.kg=5.5}},{rohlik,kus,{.kus=-4}},{chleb,kg,{.kg=-3}},{rohlik,kus,{.kus=-35}},
					 {sirup,kus,{.kus=5}},{cokolada,kus,{.kus=-2}},{salam,kg,{.kg=-.3}},{merunky,kg,{.kg=-3}},{maso,kg,{.kg=-.5}},{maso,kg,{.kg=-.8}},
					 {meloun,kg,{.kg=22.5}},{meloun,kg,{.kg=-3.2}},{chleb,kg,{.kg=-.5}},{sirup,kus,{.kus=-1}},{mleko,kus,{.kus=-4}},{sul,kg,{.kg=-1}},
					 {rohlik,kus,{.kus=20}},{maso,kg,{.kg=-1.5}},{pivo,kus,{.kus=-8}}};

const unsigned POHYB=sizeof pohyb/sizeof *pohyb;

const char *nazev[]={"rohlik","chleb","brambory","sirup","merunky","cukr","cokolada","salam","mleko","kava","pivo","mouka","maso","sul","kmin","fazole","meloun"};
