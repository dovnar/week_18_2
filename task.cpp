#include <iostream>
using namespace std;

int** initializationAndFillArray(int& countLine, int& size);
void printArray(int** arr, int countLine, int size);
void printArray(int* arr, int size);
void deleteArray(int** arr, int countLine, int size);
void createArrayBasicValuesForABC(int** a, int countLineA, int sizeA,
	int** b,	int countLineB, int sizeB, int** c, int countLineC, int sizeC);
void createArrayUniqueValuesForABC(int** a, int countLineA, int sizeA,
	int** b, int countLineB, int sizeB, int** c, int countLineC, int sizeC);
void createArrayBasicValuesForAC(int** a, int countLineA, int sizeA,
	int** c, int countLineC, int sizeC);
void createArrayNegativeValuesForABC(int** a, int countLineA, int sizeA,
	int** b, int countLineB, int sizeB, int** c, int countLineC, int sizeC);

int main()
{
	int countLineA, sizeA;
	int** a = initializationAndFillArray(countLineA, sizeA);
	int countLineB, sizeB;
	int** b = initializationAndFillArray(countLineB, sizeB);
	int countLineC, sizeC;
	int** c = initializationAndFillArray(countLineC, sizeC);;
	
	printArray(a, countLineA, sizeA);
	printArray(b, countLineB, sizeB);
	printArray(c, countLineC, sizeC);

	createArrayBasicValuesForABC(a, countLineA, sizeA, b, countLineB, sizeB, c, countLineC, sizeC);
	createArrayUniqueValuesForABC(a, countLineA, sizeA, b, countLineB, sizeB, c, countLineC, sizeC);
	createArrayBasicValuesForAC(a, countLineA, sizeA, c, countLineC, sizeC);
	createArrayNegativeValuesForABC(a, countLineA, sizeA, b,  countLineB, sizeB, c, countLineC, sizeC);

	deleteArray(a,  countLineA, sizeA);
	deleteArray(b,  countLineB, sizeB);
	deleteArray(c, countLineC, sizeC);
}

int** initializationAndFillArray(int& countLine, int& size)
{
	cout << "enter line: ";
	cin >> countLine;
	cout << "enter size: ";
	cin >> size;
	int** arr = new int*[countLine];
	for (int i = 0; i < countLine; i++)
	{
		(arr[i]) = new int[size];
		for (int j = 0; j < size; j++)
		{
			cout << "enter number: ";
			cin >> arr[i][j];
		}
	}
	return arr;
}

void printArray(int** arr,  int countLine, int size)
{
	for (int i = 0; i < countLine; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void createArrayBasicValuesForABC(int** a,  int countLineA, int sizeA, 
	int** b,  	int countLineB, int sizeB, int** c,  int countLineC, int sizeC)
{
	int* arr = new int[1]{ NULL };
	int size = 0;
	for (int lineA = 0; lineA < countLineA; lineA++)
	{
		for (int iA = 0; iA < sizeA; iA++)
		{
			for (int lineB = 0; lineB < countLineB; lineB++)
			{
				for (int iB = 0; iB < sizeB; iB++)
				{
					if (a[lineA][iA] == b[lineB][iB])
					{
						for (int lineC = 0; lineC < countLineC; lineC++)
						{
							for (int iC = 0; iC < sizeC; iC++)
							{
								if (a[lineA][iA] == c[lineC][iC])
								{
									size++;
									arr = new int[size];
									arr[size-1] = a[lineA][iA];
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "print basic values for A, B, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void createArrayUniqueValuesForABC(int** a,  int countLineA, int sizeA, 
	int** b, int countLineB, int sizeB, int** c, int countLineC, int sizeC)
{
	int* arr = new int[1]{ NULL };
	int size = 0;
	int matches;
	for (int lineA = 0; lineA < countLineA; lineA++)
	{
		for (int iA = 0; iA < sizeA; iA++)
		{
			matches = 0;
				for (int lineB = 0; lineB < countLineB; lineB++)
				{
					for (int iB = 0; iB < sizeB; iB++)
					{
						if (a[lineA][iA] == b[lineB][iB])
						{
							matches++;
						}
					}
				}
			if (matches == 0)
			{
					for (int lineC = 0; lineC < countLineC; lineC++)
					{
						for (int iC = 0; iC < sizeC; iC++)
						{
							if (a[lineA][iA] == c[lineC][iC])
							{
								matches++;
							}
						}
					}
				}
			if (matches == 0)
			{
				size++;
				arr = new int[size];
				arr[size - 1] = a[lineA][iA];
			}
		}
	}
	for (int lineB = 0; lineB < countLineB; lineB++)
	{
		for (int iB = 0; iB < sizeB; iB++)
		{
			matches = 0;
			for (int lineA = 0; lineA < countLineA; lineA++)
			{
				for (int iA = 0; iA < sizeA; iA++)
				{
					if (a[lineA][iA] == b[lineB][iB])
					{
						matches++;
					}
				}
			}
			if (matches == 0)
			{
				for (int lineC = 0; lineC < countLineC; lineC++)
				{
					for (int iC = 0; iC < sizeC; iC++)
					{
						if (b[lineB][iB] == c[lineC][iC])
						{
							matches++;
						}
					}
				}
			}
			if (matches == 0)
			{
				size++;
				arr = new int[size];
				arr[size - 1] = b[lineB][iB];
			}
		}
	}
	for (int lineC = 0; lineC < countLineC; lineC++)
	{
		for (int iC = 0; iC < sizeC; iC++)
		{
			matches = 0;
			if (matches == 0)
			{
				for (int lineA = 0; lineA < countLineA; lineA++)
				{
					for (int iA = 0; iA < sizeA; iA++)
					{
						if (a[lineA][iA] == c[lineC][iC])
						{
							matches++;
						}
					}
				}
			}
			if (matches == 0)
			{
				size++;
				arr = new int[size];
				arr[size - 1] = c[lineC][iC];
			}
		}
	}
	cout << "print the unique values for A, B, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void createArrayBasicValuesForAC(int** a, int countLineA, int sizeA, 
	int** c, int countLineC, int sizeC)
{
	int* arr = new int[1]{ NULL };
	int size = 0;
	
	for (int lineA = 0; lineA < countLineA; lineA++)
	{
		for (int iA = 0; iA < sizeA; iA++)
		{
			for (int lineC = 0; lineC < countLineC; lineC++)
			{
				for (int iC = 0; iC < sizeC; iC++)
				{
					if (a[lineA][iA] == c[lineC][iC])
					{
						size++;
						arr = new int[size];
						arr[size - 1] = a[lineA][iA];
					}
				}
			}
		}
	}
	cout << "print basic values for A, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void createArrayNegativeValuesForABC(int** a, int countLineA, int sizeA, 
	int** b, int countLineB, int sizeB, int** c, int countLineC, int sizeC)
{
	int* arr = new int[1]{ NULL };
	int size = 1;
	int matches;
	
	for (int line = 0; line < countLineA; line++)
	{
		for (int i = 0; i < sizeA; i++)
		{
			matches = 0;
			if (a[line][i] < 0)
			{
				for (int j = 0; j < size; j++)
				{
					if (a[line][i] == arr[j])
					{
						matches++;
					}
				}
				if (matches == 0)
				{
					size++;
					arr = new int[size];
					arr[size - 1] = a[line][i];
				}
			}
		}
	}
	for (int line = 0; line < countLineB; line++)
	{
		for (int i = 0; i < sizeB; i++)
		{
			matches = 0;
			if (b[line][i] < 0)
			{
				for (int j = 0; j < size; j++)
				{
					if (b[line][i] == arr[j])
					{
						matches++;
					}
				}
				if (matches == 0)
				{
					size++;
					arr = new int[size];
					arr[size - 1] = b[line][i];
				}
			}
		}
	}
	for (int line = 0; line < countLineC; line++)
	{
		for (int i = 0; i < sizeC; i++)
		{
			matches = 0;
			if (c[line][i] < 0)
			{
				for (int j = 0; j < size; j++)
				{
					if (c[line][i] == arr[j])
					{
						matches++;
					}
				}
				if (matches == 0)
				{
					size++;
					arr = new int[size];
					arr[size - 1] = c[line][i];
				}
			}
		}
	}
	cout << "print array it contains negative values for A, B, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void deleteArray(int** arr, int countLine, int size)
{
	for (int line = 0; line < countLine; line++)
	{
		delete[] arr[line];
	}
	delete[] arr;
}


/*Есть 3 двумерных массива A, B, C. Количество строк и столбцов для них вводит пользователь с клавиатуры для каждого из них. Реализуйте 
Создайте одномерный массив, который содержит общие значения для A, B, C 
Создайте одномерный массив, который содержит уникальные значения для A, B, C 
Создайте одномерный массив, который содержит общие значения для A и C 
Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений */