#include<stdio.h>


int main() {
	int a, b, c, p = -1;
	FILE* fin;
	fopen_s(&fin, "in2.txt", "rt");
	printf("Get numbers from in2.txt\n");
	if (fin != NULL) {
		fscanf_s(fin, "%d%d%d", &a, &b, &c);
		p = a * b * c;
		printf("Output product 3 numbers: %d\n", p);
	}
	else {
		printf("file in2.txt not exists\n");
		return 0;
	}

	fopen_s(&fin, "out2.txt", "wt");
	if (fin != NULL) {
		fprintf(fin, "%d", p);
		printf("Saved result to out2.txt: ");
	}
	else {
		printf("file out2.txt not exists\n");
		return 0;
	}
	return 0;
}