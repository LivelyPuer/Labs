#include<stdio.h>

#define ARRAY_COUNT 65536
#define INPUT "in.txt"
#define OUTPUT "out.txt"

int array[ARRAY_COUNT];

int length = 0;
#pragma region Lab 16
void keyboard_input() {
	printf("array length = ");
	scanf_s("%d", &length);
	printf("input array: ");
	int num;
	for (int i = 0; i < length; i++) {
		scanf_s("%d", &array[i]);
	}
}

void x10_odd_elements() {
	for (int i = 0; i < length; i++) {
		if (array[i] % 2 != 0) {
			array[i] *= 10;
		}
	}
	printf("\n<Ready>");

}

int find_min() {
	int min = _CRT_INT_MAX;
	if (length == 0) {
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}



int count_more_10() {
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] > 10) {
			cnt++;
		}
	}
	return cnt;
}

int count_even_index_less_min() {
	int cnt = 0;
	bool can_cnt = false;
	int min = find_min();
	printf("min element: %d\n", min);
	for (int i = length - 1; i >= 0; i--) {
		if (can_cnt && array[i] % 2 == 0) {
			cnt++;
		}
		else if (!can_cnt && array[i] == min) {
			can_cnt = true;
		}
	}
	return cnt;
}

void x10_odd_index_over_min() {
	bool can_x10 = false;
	int min = find_min();
	printf("min element: %d\n", min);
	for (int i = 0; i < length; i++) {
		if (can_x10 && array[i] % 2 != 0) {
			array[i] *= 10;
		}
		else if (!can_x10 && array[i] == min) {
			can_x10 = true;
		}
	}
}

void x2_last_even() {
	for (int i = length - 1; i >= 0; i--) {
		if (array[i] % 2 == 0) {
			array[i] *= 2;
			break;
		}
	}
}

void show_array() {
	printf("Array content: <");
	for (int i = 0; i < length; i++) {
		printf(" %d", array[i]);
	}
	printf(" >\n");
}
#pragma endregion

void delete_elem(int index) {
	for (int i = index; i < length - 1; i++) {
		array[i] = array[i + 1];
	}
	length--;
}
void case_delete_elem() {
	printf("delete elem by index = ");
	int ind;
	scanf_s("%d", &ind);
	delete_elem(ind);
	printf("<Ready>\n");
}

void add_elem(int index, int value) {
	int tmp1 = array[index], tmp2;
	array[index] = value;
	for (int i = index + 1; i < length + 1; i++) {
		tmp2 = array[i];
		array[i] = tmp1;
		tmp1 = tmp2;
	}
	length++;
}
void case_add_elem() {
	printf("add elem after index = ");
	int ind, val;
	scanf_s("%d", &ind);
	printf("elem value = ");
	scanf_s("%d", &val);
	add_elem(ind, val);
	printf("<Ready>\n");
}
int find_index_min() {
	int min = _CRT_INT_MAX;
	int ind = 0;
	if (length == 0) {
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (array[i] < min) {
			min = array[i];
			ind = i;
		}
	}
	return ind;
}
void delete_min() {
	delete_elem(find_index_min());
	printf("<Ready>\n");
}

void add_zero_min() {
	add_elem(find_index_min() + 1, 0);
	printf("<Ready>\n");
}

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

void show_instaruction() {
	show_array();
	printf("Select operation on array:\n");
	printf("1: input array on keyboard\n");
	printf("2: x10 for odd-elements\n");
	printf("3: find minimal element\n");
	printf("4: count elements more than 10\n");
	printf("5: x2 last even-element\n");
	printf("6: count even-element have less index than minimal element\n");
	printf("7: x10 for odd-elements have over index than minimal element\n");
	printf("   ----> Lab 17 <----\n");
	printf("11: delete element\n");
	printf("12: add element\n");
	printf("13: delete minimal element\n");
	printf("14: add ZERO after minimal element\n");
	printf("   ----> Lab 18 <----\n");
	printf("21: open from file\n");
	printf("22: save to file\n");
	printf("\n");
	printf("0: Quit on application\n");
	printf("Selected operation >>>>>>> ");
}

int main() {
	int command, tmp;
	bool loop = true;
	while (loop) {
		show_instaruction();
		scanf_s("%d", &command);
		switch (command) {
		case 0:
			loop = false;
			break;
		case 1:
			keyboard_input();
			break;
		case 2:
			x10_odd_elements();
			break;
		case 3:
			tmp = find_min();
			printf("min = %d\n", tmp);
			break;
		case 4:
			tmp = count_more_10();
			printf("cnt = %d\n", tmp);
			break;
		case 5:
			x2_last_even();
			break;
		case 6:
			tmp = count_even_index_less_min();
			printf("count even-element have less index than minimal element: %d\n", tmp);
			break;
		case 7:
			x10_odd_index_over_min();
			break;
		case 11:
			case_delete_elem();
			break;
		case 12:
			case_add_elem();
			break;
		case 13:
			delete_min();
			break;
		case 14:
			add_zero_min();
			break;
		case 21:
			open_array(INPUT);
			break;
		case 22:
			save_array(OUTPUT);
			break;
		}
		printf("\n========================\n\n");
	}
	return 0;
}
