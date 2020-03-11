#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>

int getRandomNum(int min = 1, int max = 9) {
	return rand() % (max - min + 1) + min;
}

template <typename T> void collectionInit(T* collection, int size, int min = 1, int max = 9) {
	char type = ' ';
	if (typeid(T).name() == typeid(type).name()) {
		for (int iter = 0; iter < size; iter++) {
			collection[iter] = '+';
		}
	} else {
		for (int iter = 0; iter < size; iter++) {
			collection[iter] = getRandomNum(min, max);
		}
	}
}

template <typename T> void collectionInit(T** collection, int rows, int cols, int min = 1, int max = 9) {
	for (int row = 0; row < rows; row++) {
		collectionInit(collection[row], cols, min, max);
	}
}

template <typename T> void collectionInit(T*** collection, int layers, int rows, int cols, int min = 1, int max =  9) {
	for (int layer = 0; layer < layers; layer++) {
		collectionInit(collection[layer], rows, cols, min, max);
	}
}

template <typename T> void collectionRemove(T* collection) {
	delete[] collection;
}

template <typename T> void collectionRemove(T** collection, int rows) {
	for (int row = 0; row < rows; row++) {
		delete[] collection[row];
	}
	delete[] collection;
}

template <typename T> void collectionRemove(T*** collection, int layers, int rows) {
	for (int layer = 0; layer < layers; layer++) {
		for (int row = 0; row < rows; row++) {
			delete[] collection[layer][row];
		}
		delete[] collection[layer];
	}
	delete[] collection;
}

template <typename T> void collectionShow(T* collection, int size) {
	for (int iter = 0; iter < size; iter++) {
		std::cout << collection[iter] << ' ';
	}
}

template <typename T> void collectionShow(T** collection, int rows, int cols) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			std::cout << collection[row][col] << ' ';
		}
		std::cout << '\n';
	}
}

template <typename T> void collectionShow(T*** collection, int layers, int rows, int cols) {
	for (int layer = 0; layer < layers; layer++) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				std::cout << collection[layer][row][col] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
}

// определение максимального элемента на главной диагонали матрицы
template <typename T> T collectionMaxElemMainDiagonal(T** collection, int rows, int cols) {
	T maxElem = collection[0][0];

	for (int iter = 0; iter < rows; iter++) {
		if (collection[iter][iter] > maxElem) {
			maxElem = collection[iter][iter];
		}
	}

	return maxElem;
}

// определение минимального элемента на главной диагонали матрицы
template <typename T> T collectionMinElemMainDiagonal(T** collection, int rows, int cols) {
	T minElem = collection[0][0];

	for (int iter = 0; iter < rows; iter++) {
		if (collection[iter][iter] < minElem) {
			minElem = collection[iter][iter];
		}
	}

	return minElem;
}

template <typename T> T collectionMaxElem(T* collection, int size) {
	T maxElem = collection[0];

	for (int iter = 0; iter < size; iter++) {
		if (collection[iter] > maxElem) {
			maxElem = collection[iter];
		}
	}

	return maxElem;
}

template <typename T> T collectionMaxElem(T** collection, int rows, int cols) {
	T maxElem = collection[0][0];

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (collection[row][col] > maxElem) {
				maxElem = collection[row][col];
			}
		}
	}

	return maxElem;
}

template <typename T> T collectionMaxElem(T*** collection, int layers, int rows, int cols) {
	T maxElem = collection[0][0][0];

	for (int layer = 0; layer < layers; layer++) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (collection[layer][row][col] > maxElem) {
					maxElem = collection[layer][row][col];
				}
			}
		}
	}

	return maxElem;
}

template <typename T> void swap(T& elem1, T& elem2) {
	T interim = elem1;
	elem1 = std::move(elem2);
	elem2 = std::move(interim);
}

template <typename T> void collectionSelectionSort(T* collection, int size) {
	for (int iter = 0; iter < size; iter++) {
		for (int count = iter; count < size; count++) {
			if (collection[count] < collection[iter]) {
				swap(collection[count], collection[iter]);
			}
		}
	}
}

// для 12 задания
template <typename T> void collectionInsertionSort(T* collection, int size) {
	for (int iter = 1; iter < size; iter++) {
		int index = iter;
		T elem = collection[iter];

		while (index > 0 && collection[index - 1] > elem) {
			collection[index] = collection[index - 1];
			index--;
		}

		collection[index] = elem;
	}
}

// для 11 задания
template <typename T> void collectionBubbleSort(T* collection, int size) {
	bool sorted = false;

	while (!sorted) {
		sorted = true;

		for (int iter = 1; iter < size; iter++) {
			if (collection[iter] < collection[iter - 1]) {
				swap(collection[iter], collection[iter - 1]);
				sorted = false;
			}
		}
	}
}

double toFixed(double num, int sign) {
	int numOfDigits = pow(10, sign);

	return round(num * numOfDigits) / numOfDigits;
}

template <typename T> double collectionGetAvg(T* collection, int size) {
	double sumElems = 0;

	for (int iter = 0; iter < size; iter++) {
		sumElems = sumElems + collection[iter];
	}

	return toFixed(sumElems / size, 2);
}

template <typename T> double collectionGetAvg(T** collection, int rows, int cols) {
	double sumElems = 0;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			sumElems = sumElems + collection[row][col];
		}
	}

	return sumElems / (rows * cols);
}

template <typename T> double collectionGetAvg(T*** collection, int layers, int rows, int cols) {
	double sumElems = 0;

	for (int layer = 0; layer < layers; layer++) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				sumElems = sumElems + collection[layer][row][col];
			}
		}
	}

	return sumElems / (layers * rows * cols);
}

template <typename T> void getRootSquareEquation(T coefA, T coefB) {
	double x = (double)-coefB / (double)coefA;
	std::cout << "x: " << toFixed(x, 2);
}

template <typename T> void getRootSquareEquation(T coefA, T coefB, T coefC) {
	double disc = pow(coefB, 2) - 4 * (double)coefA * (double)coefC;

	if (disc < 0) {
		std::cout << "Корней нет.";
	} else if (disc == 0) {
		double x = (-coefB + sqrt(disc) / (2 * (double)coefA));
		std::cout << "Один корень: " << x;
	} else {
		double
			x1 = (-coefB + sqrt(disc) / (2 * (double)coefA)),
			x2 = (-coefB - sqrt(disc) / (2 * (double)coefA));
		std::cout << "x1: " << x1 << "\tx2: " << x2;
	}
}

void collectionSort(int* collection, int size, int rev = 1) {
	switch (rev) {
		case 1:
			for (int iter = 0; iter < size; iter++) {
				for (int count = iter; count < size; count++) {
					if (collection[count] < collection[iter]) {
						swap(collection[count], collection[iter]);
					}
				}
			}

			break;
		case 0:
			for (int iter = 0; iter < size; iter++) {
				for (int count = iter; count < size; count++) {
					if (collection[count] > collection[iter]) {
						swap(collection[count], collection[iter]);
					}
				}
			}

			break;
	}
}

int posFirstNegativeElem(int* collection, int size) {
	for (int iter = 0; iter < size; iter++) {
		if (collection[iter] < 0) {
			return iter;
		}
	}

	return -1;
}

int posLastNegativeElem(int* collection, int size) {
	for (int iter = size - 1; iter > 0; iter--) {
		if (collection[iter] < 0) {
			return iter;
		}
	}

	return -1;
}

void collectionSortOfRange(int* collection, int size, int firstIndex, int lastIndex) {
	for (int iter = firstIndex + 1; iter < lastIndex; iter++) {
		for (int count = iter; count < lastIndex; count++) {
			if (collection[count] < collection[iter]) {
				swap(collection[iter], collection[count]);
			}
		}
	}
}

void collectionSortOfRange(int* collection, int size, int firstIndex, int lastIndex, int rev) {
	switch (rev) {
		case 0:
			for (int iter = firstIndex + 1; iter < lastIndex; iter++) {
				for (int count = iter; count < lastIndex; count++) {
					if (collection[count] < collection[iter]) {
						swap(collection[iter], collection[count]);
					}
				}
			}

			break;
		case 1:
			for (int iter = firstIndex; iter < lastIndex; iter++) {
				for (int count = iter; count < lastIndex; count++) {
					if (collection[iter] < collection[count]) {
						swap(collection[iter], collection[count]);
					}
				}
			}

			break;
	}
}

void collectionSortOfRange() {
	const int SIZE = 10;
	int collection[SIZE] { 0 };

	collectionInit(collection, SIZE, -20, 20);
	collectionShow(collection, SIZE);
	std::cout << '\n';

	int
		firstIndex = posFirstNegativeElem(collection, SIZE),
		lastIndex = posLastNegativeElem(collection, SIZE);
	collectionSortOfRange(collection, SIZE, firstIndex, lastIndex);
	collectionShow(collection, SIZE);
}

void collectionShuffle(int* collection, int size) {
	for (int iter = 0; iter < size; iter++) {
		swap(collection[getRandomNum(0, size - 1)], collection[getRandomNum(0, size - 1)]);
	}
}

int collectionSearchElem(int* collection, int size, int searchNum) {
	for (int iter = 0; iter < size; iter++) {
		if (collection[iter] == searchNum) {
			return iter;
		}
	}

	return -1;
}

// задача 10
void task10() {
	const int SIZE { 10 };
	int collection[SIZE] { 0 };

	collectionInit(collection, SIZE);
	collectionShow(collection, SIZE);
	std::cout << '\n';
	collectionShuffle(collection, SIZE);
	collectionShow(collection, SIZE);
	std::cout << '\n';

	int searchNum = getRandomNum(0, SIZE - 1);
	int posSearchNum = collectionSearchElem(collection, SIZE, searchNum);
	std::cout << "Случайное число: " << searchNum << '\n';
	std::cout << "Позиция числа: " << posSearchNum;
	std::cout << '\n';

	if (posSearchNum != -1) {
		collectionSortOfRange(collection, SIZE, 0, posSearchNum, 1);
		collectionSortOfRange(collection, SIZE, posSearchNum, SIZE, 0);
		collectionShow(collection, SIZE);
		std::cout << '\n';
	} else {
		std::cout << "Загаданного числа нет в массиве.";
	}
}

enum Operation : int {
	show = 1,
	retake,
	avg,
	out
};

// задача 13
void academicPerformance() {
	const int SIZE { 10 };
	int collection[SIZE];

	for (int iter = 0; iter < SIZE; iter++) {
		std::cout << "Введите оценку: ";
		std::cin >> collection[iter];
	}

	bool isExit = true;
	int code_operation;

	std::cout << "Меню:\n\t1. Вывести оценки\t2. Пересдать предмет\n\t3. Расчитать средний балл\t4. Выйти\n";

	while (isExit) {
		std::cout << "Ввести код операции: ";
		std::cin >> code_operation;

		if (code_operation > 0 && code_operation < 5) {
			switch (code_operation) {
				case Operation::show:
					collectionShow(collection, SIZE);
					std::cout << '\n';
					break;
				case Operation::retake:
					int
						index,
						estimation;
					std::cout << "Введите номер оценки от 1 до 10 и оценку через пробел: ";
					std::cin >> index >> estimation;

					if (index - 1 >= 0 && index - 1 < SIZE && estimation > 0 && estimation < 6) {
						collection[index - 1] = estimation;
					} else {
						std::cout << "Неверные данные для изменения оценкию.";
					}

					break;
				case Operation::avg:
					std::cout << "Avg оценок: " << collectionGetAvg(collection, SIZE) << '\n';
					break;
				case Operation::out:
					isExit = false;
					break;
			}
		}
	}

}

void task14() {
	const int SIZE { 9 };
	int collection[SIZE] { 0 };

	collectionInit(collection, SIZE);
	collectionShow(collection, SIZE);
	std::cout << '\n';
	double avg = collectionGetAvg(collection, SIZE);
	
	if (avg > 0) {
		int lastIndex = SIZE - SIZE / 3;

		for (int iter = 0; iter < lastIndex; iter++) {
			for (int count = iter; count < lastIndex; count++) {
				if (collection[count] < collection[iter]) {
					swap(collection[iter], collection[count]);
				}
			}
		}
	} else {
		int lastIndex = SIZE / 3;

		for (int iter = 0; iter < lastIndex; iter++) {
			for (int count = iter; count < lastIndex; count++) {
				if (collection[count] < collection[iter]) {
					swap(collection[iter], collection[count]);
				}
			}
		}
	}

	collectionShow(collection, SIZE);
	std::cout << '\n';
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(NULL));

	/*
	// задание 1, пункты 1 и 2, инициализация и вывод квадратной матрицы на экран
	int
		layers = 2,
		rows = 3,
		cols = 4;
	char*** collection = new char** [layers];

	for (int layer = 0; layer < layers; layer++) {
		collection[layer] = new char* [rows];
		for (int row = 0; row < rows; row++) {
			collection[layer][row] = new char[cols];
		}
	}

	collectionInit(collection, layers, rows, cols);
	collectionShow(collection, layers, rows, cols);
	collectionRemove(collection, layers, rows);
	*/


	/*
	// задание 1, 4 пункт
	const int SIZE { 10 };
	int collection[SIZE] { 0 };
	collectionSelectionSort(collection, SIZE);
	collectionInit(collection, SIZE);
	collectionShow(collection, SIZE);
	std::cout << '\n';
	collectionSelectionSort(collection, SIZE);   // сортировка выбором
	//collectionInsertionSort(collection, SIZE); // сортировка вставками
	//collectionBubbleSort(collection, SIZE);    // сортировка пузырьком
	collectionShow(collection, SIZE);
	*/


	// задание 2, пункт 1, 2 и 3

	/*
	// пункт 1
	const int SIZE { 10 };
	int collection[SIZE] { 0 };

	collectionInit(collection, SIZE);
	collectionShow(collection, SIZE);
	std::wcout << '\n';
	std::cout << collectionMaxElem(collection, SIZE);
	*/

	/*
	// пункт 2
	int
		rows = 3,
		cols = 4;
	int** collection = new int* [rows];

	for (int row = 0; row < rows; row++) {
		collection[row] = new int [cols] { 0 };
	}

	collectionInit(collection, rows, cols);
	collectionShow(collection, rows, cols);
	std::cout << collectionMaxElem(collection, rows, cols);
	collectionRemove(collection, rows);
	*/

	/*
	// пункт 3
	int
		layers = 2,
		rows = 3,
		cols = 5;
	int*** collection = new int** [layers];

	for (int layer = 0; layer < layers; layer++) {
		collection[layer] = new int* [rows];

		for (int row = 0; row < rows; row++) {
			collection[layer][row] = new int[cols];
		}
	}

	collectionInit(collection, layers, rows, cols);
	collectionShow(collection, layers, rows, cols);
	std::cout << collectionMaxElem(collection, layers, rows, cols);
	//std::cout << collectionGetAvg(collection, layers, rows, cols); // проверка задания 5
	collectionRemove(collection, layers, rows);
	*/

	// задание 7, округление до указанного количества знаков после запятой
	//std::cout << toFixed(2.5554, 0);

	// задание 6
	//getRootSquareEquation(3, -3);
	//getRootSquareEquation(1, 2, -3);


	/*
	// задание 8
	const int SIZE { 10 };
	int collection[SIZE] { 0 };

	collectionInit(collection, SIZE);
	collectionShow(collection, SIZE);
	std::cout << '\n';
	collectionSort(collection, SIZE, 1);
	collectionShow(collection, SIZE);
	*/

	//collectionSortOfRange(); // задание 9

	//task10(); // задание 10

	//academicPerformance(); // задача 13

	//task14(); // задача 14

	return 0;
}