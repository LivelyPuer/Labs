#include<stdio.h>

#define INPUT "in5.txt"
#define OUTPUT "out5.txt"
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
int middle_from_array() {
	int s = 0;
	for (int i = 0; i < length; i++) {
		s += array[i];
	}
	return s / length;
}
void x10_all_more_than(int m) {
	for (int i = 0; i < length; i++) {
		if (array[i] > m) {
			array[i] *= 10;
		}
	}
}

int main() {
	open_array(INPUT);
	x10_all_more_than(middle_from_array());
	save_array(OUTPUT);
	printf("Ready");
	return 0;
}