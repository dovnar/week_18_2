#include <iostream>
using namespace std;

void initializationAndFillArray(int*** arr, int& countTab, int& countLine, int& size);
void printArray(int*** arr, int& countTab, int& countLine, int& size);
void printArray(int* arr, int size);
void deleteArray(int*** arr, int countTab, int countLine, int size);
void createArrayBasicValuesForABC(int*** a, int countTabA, int countLineA, int sizeA,
	int*** b,	int countTabB, int countLineB, int sizeB, int*** c, int countTabC, int countLineC, int sizeC);
void createArrayUniqueValuesForABC(int*** a, int countTabA, int countLineA, int sizeA,
	int*** b, int countTabB, int countLineB, int sizeB, int*** c, int countTabC, int countLineC, int sizeC);
void createArrayBasicValuesForAC(int*** a, int countTabA, int countLineA, int sizeA,
	int *** c, int countTabC, int countLineC, int sizeC);
void createArrayNegativeValuesForABC(int*** a, int countTabA, int countLineA, int sizeA,
	int*** b, int countTabB, int countLineB, int sizeB, int*** c, int countTabC, int countLineC, int sizeC);

int main()
{
	int*** a;
	int countTabA;
	int countLineA;
	int sizeA;
	int*** b;
	int countTabB;
	int countLineB;
	int sizeB;
	int*** c;
	int countTabC;
	int countLineC;
	int sizeC;

	initializationAndFillArray(a, countTabA, countLineA, sizeA);
	initializationAndFillArray(b, countTabB, countLineB, sizeB);
	initializationAndFillArray(c, countTabC, countLineC, sizeC);

	printArray(a, countTabA, countLineA, sizeA);
	printArray(b, countTabB, countLineB, sizeB);
	printArray(c, countTabC, countLineC, sizeC);

	createArrayBasicValuesForABC(a, countTabA, countLineA, sizeA, b, countTabB, countLineB, sizeB, c, countTabC, countLineC, sizeC);
	createArrayUniqueValuesForABC(a, countTabA, countLineA, sizeA, b, countTabB, countLineB, sizeB, c, countTabC, countLineC, sizeC);
	createArrayBasicValuesForAC(a, countTabA, countLineA, sizeA, c, countTabC, countLineC, sizeC);
	createArrayNegativeValuesForABC(a, countTabA, countLineA, sizeA, b, countTabB, countLineB, sizeB, c, countTabC, countLineC, sizeC);

	deleteArray(a, countTabA, countLineA, sizeA);
	deleteArray(b, countTabB, countLineB, sizeB);
	deleteArray(c, countTabC, countLineC, sizeC);
}

void initializationAndFillArray(int *** arr, int & countTab, int & countLine, int & size)
{
	cout << "enter tab: ";
	cin >> countTab;
	cout << "enter line: ";
	cin >> countLine;
	cout << "enter size: ";
	cin >> size;
	arr = new int**[countTab];
	for (int i = 0; i < countTab; i++)
	{
		(arr[i]) = new int*[countLine];
		for (int j = 0; j < countLine; j++)
		{
			(arr[i][j]) = new int[size];
			for (int l = 0; l < size; l++)
			{
				cout << "enter number: ";
				cin >> arr[i][j][l];
			}
		}
	}
}

void printArray(int *** arr, int & countTab, int & countLine, int & size)
{
	for (int i = 0; i < countTab; i++)
	{
		for (int j = 0; j < countLine; j++)
		{
			for (int l = 0; l < size; l++)
			{
				cout << arr[i][j][l] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl << endl;
}

void createArrayBasicValuesForABC(int *** a, int countTabA, int countLineA, int sizeA, 
	int *** b, int countTabB, 	int countLineB, int sizeB, int *** c, int countTabC, int countLineC, int sizeC)
{
	int* arr;
	int size = 0;
	for (int tabA = 0; tabA < countTabA; tabA++)
	{
		for (int lineA = 0; lineA < countLineA; lineA++)
		{
			for (int iA = 0; iA < sizeA; iA++)
			{
				for (int tabB = 0; tabB < countTabB; tabB++)
				{
					for (int lineB = 0; lineB < countLineB; lineB++)
					{
						for (int iB = 0; iB < sizeB; iB++)
						{
							if (a[tabA][lineA][iA] == b[tabB][lineB][iB])
							{
								for (int tabC = 0; tabC < countTabC; tabC++)
								{
									for (int lineC = 0; lineC < countLineC; lineC++)
									{
										for (int iC = 0; iC < sizeC; iC++)
										{
											if (a[tabA][lineA][iA] == c[tabC][lineC][iC])
											{
												size++;
												arr = new int[size];
												arr[size-1] = a[tabA][lineA][iA];
											}
										}
									}
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

void createArrayUniqueValuesForABC(int *** a, int countTabA, int countLineA, int sizeA, 
	int *** b, int countTabB, int countLineB, int sizeB, int *** c, int countTabC, int countLineC, int sizeC)
{
	int* arr;
	int size = 0;
	int matches;
	for (int tabA = 0; tabA < countTabA; tabA++)
	{
		for (int lineA = 0; lineA < countLineA; lineA++)
		{
			for (int iA = 0; iA < sizeA; iA++)
			{
				matches = 0;
				for (int tabB = 0; tabB < countTabB; tabB++)
				{
					for (int lineB = 0; lineB < countLineB; lineB++)
					{
						for (int iB = 0; iB < sizeB; iB++)
						{
							if (a[tabA][lineA][iA] == b[tabB][lineB][iB])
							{
								matches++;
							}
						}
					}
				}
				if (matches == 0)
				{
					for (int tabC = 0; tabC < countTabC; tabC++)
					{
						for (int lineC = 0; lineC < countLineC; lineC++)
						{
							for (int iC = 0; iC < sizeC; iC++)
							{
								if (a[tabA][lineA][iA] == c[tabC][lineC][iC])
								{
									matches++;
								}
							}
						}
					}
				}
				if (matches == 0)
				{
					size++;
					arr = new int[size];
					arr[size - 1] = a[tabA][lineA][iA];
				}
			}
		}
	}
	for (int tabB = 0; tabB < countTabB; tabB++)
	{
		for (int lineB = 0; lineB < countLineB; lineB++)
		{
			for (int iB = 0; iB < sizeB; iB++)
			{
				matches = 0;
				for (int tabA = 0; tabA < countTabA; tabA++)
				{
					for (int lineA = 0; lineA < countLineA; lineA++)
					{
						for (int iA = 0; iA < sizeA; iA++)
						{
							if (a[tabA][lineA][iA] == b[tabB][lineB][iB])
							{
								matches++;
							}
						}
					}
				}
				if (matches == 0)
				{
					for (int tabC = 0; tabC < countTabC; tabC++)
					{
						for (int lineC = 0; lineC < countLineC; lineC++)
						{
							for (int iC = 0; iC < sizeC; iC++)
							{
								if (b[tabB][lineB][iB] == c[tabC][lineC][iC])
								{
									matches++;
								}
							}
						}
					}
				}
				if (matches == 0)
				{
					size++;
					arr = new int[size];
					arr[size - 1] = b[tabB][lineB][iB];
				}
			}
		}
	}
	for (int tabC = 0; tabC < countTabC; tabC++)
	{
		for (int lineC = 0; lineC < countLineC; lineC++)
		{
			for (int iC = 0; iC < sizeC; iC++)
			{
				matches = 0;
				for (int tabB = 0; tabB < countTabB; tabB++)
				{
					for (int lineB = 0; lineB < countLineB; lineB++)
					{
						for (int iB = 0; iB < sizeB; iB++)
						{
							if (b[tabB][lineB][iB] == c[tabC][lineC][iC])
							{
								matches++;
							}
						}
					}
				}
				if (matches == 0)
				{
					for (int tabA = 0; tabA < countTabA; tabA++)
					{
						for (int lineA = 0; lineA < countLineA; lineA++)
						{
							for (int iA = 0; iA < sizeA; iA++)
							{
								if (a[tabA][lineA][iA] == c[tabC][lineC][iC])
								{
									matches++;
								}
							}
						}
					}
				}
				if (matches == 0)
				{
					size++;
					arr = new int[size];
					arr[size - 1] = c[tabC][lineC][iC];
				}
			}
		}
	}
	cout << "print the unique values for A, B, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void createArrayBasicValuesForAC(int *** a, int countTabA, int countLineA, int sizeA, 
	int *** c, int countTabC, int countLineC, int sizeC)
{
	int* arr;
	int size = 0;
	for (int tabA = 0; tabA < countTabA; tabA++)
	{
		for (int lineA = 0; lineA < countLineA; lineA++)
		{
			for (int iA = 0; iA < sizeA; iA++)
			{
				for (int tabC = 0; tabC < countTabC; tabC++)
				{
					for (int lineC = 0; lineC < countLineC; lineC++)
					{
						for (int iC = 0; iC < sizeC; iC++)
						{
							if (a[tabA][lineA][iA] == c[tabC][lineC][iC])
							{
								size++;
								arr = new int[size];
								arr[size - 1] = a[tabA][lineA][iA];
							}
						}
					}
				}
			}
		}
	}
	cout << "print basic values for A, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void createArrayNegativeValuesForABC(int *** a, int countTabA, int countLineA, int sizeA, 
	int *** b, int countTabB, int countLineB, int sizeB, int *** c, int countTabC, int countLineC, int sizeC)
{
	int* arr;
	int size = 1;
	int matches;
	for (int tab = 0; tab < countTabA; tab++)
	{
		for (int line = 0; line < countLineA; line++)
		{
			for (int i = 0; i < sizeA; i++)
			{
				matches = 0;
				if (a[tab][line][i] < 0)
				{
					for (int j = 0; j < size; j++)
					{
						if (a[tab][line][i] == arr[j])
						{
							matches++;
						}
					}
					if (matches == 0)
					{
						size++;
						arr = new int[size];
						arr[size - 1] = a[tab][line][i];
					}
				}
			}
		}
	}
	for (int tab = 0; tab < countTabB; tab++)
	{
		for (int line = 0; line < countLineB; line++)
		{
			for (int i = 0; i < sizeB; i++)
			{
				matches = 0;
				if (b[tab][line][i] < 0)
				{
					for (int j = 0; j < size; j++)
					{
						if (b[tab][line][i] == arr[j])
						{
							matches++;
						}
					}
					if (matches == 0)
					{
						size++;
						arr = new int[size];
						arr[size - 1] = b[tab][line][i];
					}
				}
			}
		}
	}
	for (int tab = 0; tab < countTabC; tab++)
	{
		for (int line = 0; line < countLineC; line++)
		{
			for (int i = 0; i < sizeC; i++)
			{
				matches = 0;
				if (c[tab][line][i] < 0)
				{
					for (int j = 0; j < size; j++)
					{
						if (c[tab][line][i] == arr[j])
						{
							matches++;
						}
					}
					if (matches == 0)
					{
						size++;
						arr = new int[size];
						arr[size - 1] = c[tab][line][i];
					}
				}
			}
		}
	}
	cout << "print array it contains negative values for A, B, C: " << endl;
	printArray(arr, size);
	delete[] arr;
}

void printArray(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void deleteArray(int *** arr, int countTab, int countLine, int size)
{
	for (int tab = 0; tab < countTab; tab++)
	{
		for (int line = 0; line < countLine; line++)
		{
			delete[] arr[tab][line];
		}
		delete[] arr[tab];
	}
	delete[] arr;
}


/*Есть 3 двумерных массива A, B, C. Количество строк и столбцов для них вводит пользователь с клавиатуры для каждого из них. Реализуйте 
Создайте одномерный массив, который содержит общие значения для A, B, C 
Создайте одномерный массив, который содержит уникальные значения для A, B, C 
Создайте одномерный массив, который содержит общие значения для A и C 
Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений */