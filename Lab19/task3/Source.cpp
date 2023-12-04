#include<stdio.h>
#include <malloc.h>
int* array;
int length;
#define INPUT "inp3.txt"
#define OUTPUT "out3.txt"

bool open_array(const char* file_name) {
	FILE* fin;
	fopen_s(&fin, file_name, "rt");
	if (fin == NULL) {
		printf("file %s not exists\n", file_name);
		return false;
	}
	fscanf_s(fin, "%d", &length);
	array = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		fscanf_s(fin, "%d", &array[i]);
	}
	fclose(fin);
	printf("seccessful opened %s\n", file_name);
	return true;
}

bool save_array(const char* file_name) {
	FILE* fin;
	fopen_s(&fin, file_name, "wt");
	if (fin == NULL) {
		printf("file %s not exists\n", file_name);
		return false;
	}
	fprintf(fin, "%d\n", length);
	for (int i = 0; i < length; i++) {
		fprintf(fin, "%d ", array[i]);
	}
	fclose(fin);
	printf("seccessful saved %s\n", file_name);
	return true;
}

void delete_elem(int index) {
	for (int i = index; i < length - 1; i++) {
		array[i] = array[i + 1];
	}
	length--;
}
float middle() {
	float s = 0;
	for (int i = 0; i < length; i++) {
		s += array[i];
	}
	return s / (float)length;
}

int main() {
	open_array(INPUT);
	float m = middle();
	int i = 0;
	while (i < length) {
		if (array[i] < 0 or array[i] > m) {
			delete_elem(i);
			continue;
		}
		i++;
	}
	save_array(OUTPUT);
	return 0;
}