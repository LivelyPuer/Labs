#include<stdio.h>

#define INPUT "in4.txt"
#define OUTPUT "out4.txt"

int main() {
	int a, b, c, d, e, p = -1;
	FILE* fin;
	fopen_s(&fin, INPUT, "rt");
	printf("Get numbers from %s\n", INPUT);
	if (fin != NULL) {
		fscanf_s(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
		p = a + b +c + d + e;
		printf("Output product 3 numbers: %d\n", p);
	}
	else {
		printf("file %s not exists\n", INPUT);
		return 0 ;
	}
	fclose(fin);


	fopen_s(&fin, OUTPUT, "wt");
	if (fin != NULL) {
		fprintf(fin, "%d", p);
		printf("Saved result to %s\n", OUTPUT);
	}
	else {
		printf("file %s not exists\n", OUTPUT);
		return 0;
	}
	fclose(fin);
	return 0;
}