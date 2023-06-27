#include <stdio.h>

void sort(int array[], int size) {
	int pom;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				pom = array[j];
				array[j] = array[j + 1];
				array[j + 1] = pom;
			}
		}
	}
}


// 1. vraci index hledaneho prvku nebo vrati -1
int sequence_search(int array[], int size, int element) {
	for (int i = 0; i < size; i++) {
		if (array[i] == element) {
			return i;
		}
	}

	return -1;
}

// 1. vraci index hledaneho prvku ve setrizenem poli nebo vrati -1
int binary_search(int array[], int size, int element) {
	int left = 0, right = size - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		
		if (array[mid] == element) {
			return mid;
		}
		if (array[mid] > element) {
			right = mid - 1;
		}
		if (array[mid] < element) {
			left = mid + 1;
		}

	}

	return -1;
}

int interpolation_search(int array[], int size, int element) {
	int left = 0, 
		right = size - 1, 
		mid, 
		y = array[right];

	float x = array[left],
		  z = (element - x) / (y - x);

	while (left <= element && element <= right) {
		mid = left + (right - left) * z;

		if (array[mid] == element) {
			return mid;
		}
		if (array[mid] > element) {
			right = mid + 1;
		}
		if (array[mid] < element) {
			left = mid + 1;
		}
	}
	
	return -1;
}


void main() {
	int array[20], rad, help;
	int size = sizeof array / sizeof array[0];

	// 1 7 14 0 9
	for (int i = 0; i < size; i++) {
		rad = rand() % 20;
		array[i] = rad;
		printf("%d ", array[i]);
	}

	help = sequence_search(array, size, 11);

	if (help == -1) {
		printf("\nSequence: The array doesn't contain the element %d\n", help);
	}
	else {
		printf("\nSequence: The array contains the element on index %d\n", help);
	}

	sort(array, size);
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}


	help = binary_search(array, size, 11);

	if (help == -1) {
		printf("\nBinary: The array doesn't contain the element\n");
	}
	else {
		printf("\nBinary: The array contains the element on index %d\n", help);
	}


	help = interpolation_search(array, size, 11);

	if (help == -1) {
		printf("Interpolation: The array doesn't contain the element\n");
	}
	else {
		printf("Interpolation: The array contains the element on index %d\n", help);
	}
}

