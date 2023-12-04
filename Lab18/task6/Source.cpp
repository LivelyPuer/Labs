#include<stdio.h>

#define INPUT "in6.txt"
#define OUTPUT "out6.txt"
int array[65536];
int length = 0;

bool open_array(const char* file_name) {
	FILE* fin;
	fopen_s(&fin, file_name, "rt");
	if (fin == NULL) {
		printf("file %s not exists\n", file_name);
		return false;
	}
	fscanf_s(fin, "%d", &length);
	for (int i = 0; i < length; i++) {
		fscanf_s(fin, "%d", &array[i]);
	}
	fclose(fin);
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
	return true;
}
float middle_from_array() {
	int s = 0;
	for (int i = 0; i < length; i++) {
		s += array[i];
	}
	return (float)s / (float)length;
}
void x10_all_more_than(float m) {
	for (int i = 0; i < length; i++) {
		if ((float)array[i] > m) {
			array[i] *= 10;
		}
	}
}
void _all_even_less_than(float m, int coef) {
	for (int i = 0; i < length; i++) {
		if ((float)array[i] < m){
			if (array[i] % 2 == 0) {
				array[i] /= coef;
			}
		}
		
	}
}

int main() {
	if (!open_array(INPUT)) {
		return -1;
	}
	_all_even_less_than(middle_from_array(), 2);
	if (!save_array(OUTPUT)) {
		return -1;
	}
	printf("Ready");
	return 0;
}