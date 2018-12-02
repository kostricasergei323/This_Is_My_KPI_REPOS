#include <cstdio>

#define COLUMN_WIDTH 10

void printHeader();
void printFooter();

// Початок таблицi
void printHeader() {
	printf("%c", (char)213);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)209);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)209);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c\n", (char)184);
}

// Шаблон комiрки
void printPatern(float x, float val, float rand) {
	printf("%c", (char)179);
	printf("%-*.2f", COLUMN_WIDTH, x);
	printf("%c", (char)179);
	printf("%-*.3f", COLUMN_WIDTH, val);
	printf("%c", (char)179);
	printf("%-*.3f", COLUMN_WIDTH, rand);
	printf("%c\n", (char)179);

	printf("%c", (char)195);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)196);
	}
	printf("%c", (char)197);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)196);
	}
	printf("%c", (char)197);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)196);
	}
	printf("%c\n", (char)180);
}

// Тiло таблицi
void printTable(float x, float *val, float *rand, float step, int size) {
	printf("\n");
	printHeader();

	printf("%c", (char)179);
	printf("x%*c", COLUMN_WIDTH - 1, ' ');
	printf("%c", (char)179);
	printf("f(x)%*c", COLUMN_WIDTH - 4, ' ');
	printf("%c", (char)179);
	printf("rand%*c", COLUMN_WIDTH - 4, ' ');
	printf("%c\n", (char)179);

	printf("%c", (char)198);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)216);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)216);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c\n", (char)181);

	for (int i = 0; i < size - 1; i++) {
		printPatern(x, val[i], rand[i]);
		x += step;
	}
	printf("%c", (char)179);
	printf("%-*.2f", COLUMN_WIDTH, x);
	printf("%c", (char)179);
	printf("%-*.3f", COLUMN_WIDTH, val[size - 1]);
	printf("%c", (char)179);
	printf("%-*.3f", COLUMN_WIDTH, rand[size - 1]);
	printf("%c\n", (char)179);

	printFooter();
}

// Кiнець таблицi
void printFooter() {
	printf("%c", (char)212);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)207);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)207);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c\n\n\n", (char)190);
}

// Вивiд таблицi середнiх значень
void printSpecs(float aver, float sum) {
	printf("%c", (char)213);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)209);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c\n", (char)184);

	printf("%c", (char)179);
	printf("aver%*c", COLUMN_WIDTH - 4, ' ');
	printf("%c", (char)179);
	printf("sum%*c", COLUMN_WIDTH - 3, ' ');
	printf("%c\n", (char)179);

	printf("%c", (char)179);
	printf("%-*.4f", COLUMN_WIDTH, aver);
	printf("%c", (char)179);
	printf("%-*.3f", COLUMN_WIDTH, sum);
	printf("%c\n", (char)179);

	printf("%c", (char)212);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)207);
	for (int i = 0; i < COLUMN_WIDTH; i++) {
		printf("%c", (char)205);
	}
	printf("%c\n\n\n", (char)190);
}