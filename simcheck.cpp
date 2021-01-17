#include <iostream>
#include <fstream>
using namespace std;

void Read1();
void Read2();
void Read3();
void Comparison(float & Percentage1, float & Percentage2, float & Percentage3);
void RemoveNonAlphabets(char Text[]);
void ConvertWordToLowerCase(char Word[]);
void MakeSubstrings(char SubStrings[][6], char Text[]);
void SaveStringNumbers(char SubStrings[][6], int StringNumbers[]);
void Write(int StringNumbers[], int Num[][2], int y);
void WriteFile1(int Num[][2]);
void WriteFile2(int Num[][2]);
void WriteFile3(int Num[][2]);
void ClearText(char word[]);

int main()
{
	float Percentage1 = 0, Percentage2 = 0, Percentage3 = 0;
	int i = 0;

	ofstream fout;
	fout.open("file1.txt", ios::out);
	fout.close();
	fout.open("file2.txt", ios::out);
	fout.close();
	fout.open("file3.txt", ios::out);
	fout.close();
	Read1();
	Read2();
	Read3();
	Comparison(Percentage1, Percentage2, Percentage3);

	cout << "The simalirity of the files 1 and 2 is " << Percentage1 << "%" << endl;
	cout << "The simalirity of the files 2 and 3 is " << Percentage2 << "%" << endl;
	cout << "The simalirity of the files 1 and 3 is " << Percentage3 << "%" << endl;

	system("pause");
}

int Read1()
{
	char Text[1400] = { '\0' };
	char SubStrings[1200][6] = { '\0' };
	int StringNumbers[2000] = { 0 };
	int Num[2][2] = { 0 };
	int i = 0;

	ifstream fin;
	fin.open("data1.txt", ios::in);
	while (fin >> Text[i])
	{
		if (fin.eof())
		{
			break;
		}
		i++;
	}
	i = 0;
	fin.close();

	RemoveNonAlphabets(Text);
	int z = strlen(Text);
	ConvertWordToLowerCase(Text);
	MakeSubstrings(SubStrings, Text);
	SaveStringNumbers(SubStrings, StringNumbers);
	Write(StringNumbers, Num, i);
}

void Read2()
{
	char Text[1400] = { '\0' };
	char SubStrings[1200][6] = { '\0' };
	int StringNumbers[2000] = { 0 };
	int Num[2][2] = { 0 };
	int i = 0;

	ifstream fin;
	fin.open("data2.txt", ios::in);
	while (fin >> Text[i])
	{
		if (fin.eof())
		{
			break;
		}
		i++;
	}
	i = 1;
	fin.close();

	RemoveNonAlphabets(Text);
	int z = strlen(Text);
	ConvertWordToLowerCase(Text);
	MakeSubstrings(SubStrings, Text);
	SaveStringNumbers(SubStrings, StringNumbers);
	Write(StringNumbers, Num, i);
}

void Read3()
{
	char Text[1400] = { '\0' };
	char SubStrings[1200][6] = { '\0' };
	int StringNumbers[2000] = { 0 };
	int Num[2][2] = { 0 };
	int i = 0;

	ifstream fin;
	fin.open("data3.txt", ios::in);
	while (fin >> Text[i])
	{
		if (fin.eof())
		{
			break;
		}
		i++;
	}
	i = 2;
	fin.close();

	RemoveNonAlphabets(Text);
	int z = strlen(Text);
	ConvertWordToLowerCase(Text);
	MakeSubstrings(SubStrings, Text);
	SaveStringNumbers(SubStrings, StringNumbers);
	Write(StringNumbers, Num, i);
}

void Comparison(float & Percentage1, float & Percentage2, float & Percentage3)
{
	typedef int Matrix[2][2];
	Matrix arr1;
	Matrix arr2;
	Matrix arr3;
	Matrix Diffrence1;
	Matrix Diffrence2;
	Matrix Diffrence3;
	int Sum1 = 0, Sum2 = 0, Sum3 = 0;
	float Match1 = 0, Match2 = 0, Match3 = 0;

	ifstream fin1("file1.txt", ios::in);
	ifstream fin2("file2.txt", ios::in);
	ifstream fin3("file3.txt", ios::in);

	for (int x = 0; x < 10; x++)
	{
		Sum1 = 0;
		Sum2 = 0;
		Sum3 = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				fin1 >> arr1[i][j];
				fin2 >> arr2[i][j];
				fin3 >> arr3[i][j];

				if (arr1[i][j] > arr2[i][j])
				{
					Diffrence1[i][j] = arr1[i][j] - arr2[i][j];
				}
				else
				{
					Diffrence1[i][j] = arr2[i][j] - arr1[i][j];
				}
				if (arr2[i][j] > arr3[i][j])
				{
					Diffrence2[i][j] = arr2[i][j] - arr3[i][j];
				}
				else
				{
					Diffrence2[i][j] = arr3[i][j] - arr2[i][j];
				}
				if (arr1[i][j] > arr3[i][j])
				{
					Diffrence3[i][j] = arr1[i][j] - arr3[i][j];
				}
				else
				{
					Diffrence3[i][j] = arr3[i][j] - arr1[i][j];
				}
				Sum1 += Diffrence1[i][j];
				Sum2 += Diffrence2[i][j];
				Sum3 += Diffrence3[i][j];
			}
		}
		if (Sum1 < 60)
		{
			Match1++;
		}
		if (Sum2 < 60)
		{
			Match2++;
		}
		if (Sum3 < 60)
		{
			Match3++;
		}
	}
	Percentage1 = (Match1 / 10) * 100;
	Percentage2 = (Match2 / 10) * 100;
	Percentage3 = (Match3 / 10) * 100;
}

void RemoveNonAlphabets(char Text [])
{
	for (int i = 0; Text[i] != '\0'; i++)
	{
		if (!((Text[i] > 64 && Text[i] < 91) || (Text[i] > 96 && Text[i] < 123)))
		{
			for (int j = i; Text[j] != '\0'; j++)
			{
				Text[j] = Text[j + 1];
			}
			i--;
		}
	}
}

void ConvertWordToLowerCase(char Word[])
{
	for (int x = 0; Word[x] != '\0'; x++)
	{
		if (Word[x] >= 65 && Word[x] <= 90)
		{
			Word[x] = Word[x] + 32;
		}
	}
}

void MakeSubstrings(char SubStrings[][6], char Text[])
{
	int k = 0;

	for (int i = 0; Text[i + 4] != '\0'; i++)
	{
		k = i;
		for (int j = 0; j < 5; j++, k++)
		{
			SubStrings[i][j] = Text[k];
		}
	}
}

void SaveStringNumbers(char SubStrings[][6], int StringNumbers[])
{
	int Sum = 0;
	int h = 1;

	for (int i = 0; i < 1200; i++)
	{
		Sum = 0;
		for (int j = 0; j < 5; j++)
		{
			h = 1;
			for (char k = 97; k < 123; k++)
			{
				if (SubStrings[i][j] == k)
				{
					Sum += h;
					break;
				}
				else
				{
					h++;
				}
			}
		}
		StringNumbers[i] = Sum;
	}
}

void Write(int StringNumbers[], int Num[][2], int y)
{
	int k = 0;

	for (int x = 0; x < 1000; x++)
	{
		k = x;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++, k++)
			{
				Num[i][j] = StringNumbers[k];
			}
		}

		if (y == 0)
		{
			WriteFile1(Num);
		}
		else if (y == 1)
		{
			WriteFile2(Num);
		}
		else if (y == 2)
		{
			WriteFile3(Num);
		}
	}
}

void WriteFile1(int Num[][2])
{
	int k = 0;

	ofstream fout("file1.txt", ios::app);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++, k++)
		{
			fout << Num[i][j] << " ";
		}
		fout << endl;
	}

	fout << endl;
	fout.close();
}

void WriteFile2(int Num[][2])
{
	int k = 0;

	ofstream fout("file2.txt", ios::app);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++, k++)
		{
			fout << Num[i][j] << " ";
		}
		fout << endl;
	}

	fout << endl;
	fout.close();
}

void WriteFile3(int Num[][2])
{
	int k = 0;

	ofstream fout("file3.txt", ios::app);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++, k++)
		{
			fout << Num[i][j] << " ";
		}
		fout << endl;
	}

	fout << endl;
	fout.close();
}

void ClearText(char word[])
{
	for (int x = 0; x < 140; x++)
	{
		word[x] = '\0';
	}
}
