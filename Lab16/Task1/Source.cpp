#include<stdio.h>

#define ARRAY_COUNT 65536
int array[ARRAY_COUNT];

int length = 0;

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
		}
		printf("\n========================\n\n");
	}
	return 0;
}