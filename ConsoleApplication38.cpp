#include "pch.h"
#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

const int max = 100;

long long int Power(int x, int power);
char Min(vector<char>&);



void Translate(int, char*);
void Translate(double, char*);


template <typename T>
char *F(T x, char *translation)
{
	strcpy_s(translation, max, "sorry, please try again later\n\0");
	return translation;
}

char *F(int x, char *translation)
{
	int result(0);

	if (x > 0)
	{
		result = Power(x, 4) % 191;
		Translate(result, translation);
	}
	else if (x < 0)
	{
		result = (Power(x, 5) + Power(x, 3)) % 291;
		Translate(result, translation);
	}
	else if (x == 0)
	{
		result = sin(x - 391);
		Translate(result, translation);
	}

	return translation;
}

char *F(double x, char *translation)
{
	double result(0);

	result = sin(x - 391);
	Translate(result, translation);

	return translation;
}

char *F(pair<char[100], char[100]> x, char *translation)
{
	int lenght1(0), lenght2(0);
	int i(0), j(0), b(0);

	for (; x.first[lenght1] != '\0'; lenght1++)
		;
	for (; x.second[lenght2] != '\0'; lenght2++)
		;

	for (int a = 0; a < lenght1 || a < lenght2; a++)
	{
		if (a < lenght1)
		{
			for (; x.first[i] != ' ' && x.first[i] != '\0'; i++, b++)
				translation[b] = x.first[i];
			translation[b++] = ' ';
			i++;
		}

		if (a < lenght2)
		{
			for (; x.second[j] != ' ' && x.second[j] != '\0'; j++, b++)
				translation[b] = x.second[j];

			translation[b++] = ' ';
			j++;
		}
	}
	translation[b] = '\0';

	return translation;
}

char *F(vector<char> x, char *translation)
{
	vector<char> y(max);
	int a(0);
	translation[0] = 0;

	for (int i = 0; x[0] != '\0'; i++)
		y[i] = Min(x);

	for (int i = 0; y[i] != '\0'; i++)
	{
		translation[a++] = y[i];

		for (int j = 0; y[j] != '\0'; j++)
		{
			if (i != j)
				translation[a++] = y[j];
		}

		translation[a++] = ' ';
	}

	translation[a] = '\0';

	return translation;
}

char  *F(char *x, char *translation)
{
	int i(0), j(0);

	for (; x[i] != '\0'; i++)
		;

	for (; i >= 0; i--)
	{
		for (; x[i] != ' ' && i >= 0; i--)
			;

		i++;

		for (; x[i] != ' ' && x[i] != '\0'; i++, j++)
			translation[j] = x[i];

		i--;

		translation[j++] = ' ';

		for (; x[i] != ' ' && i >= 0; i--)
			;

		i--;

		if (i < 0) break;
	}

	translation[j] = '\0';

	return translation;
}


int main()
{
	setlocale(LC_ALL, "rus");

	char result[max];
	char line[max];

	pair<char[max], char[max]> para;
	vector<char> x(max);

	para.first[0] = 'a';
	para.first[1] = 'b';
	para.first[2] = ' ';
	para.first[3] = 'f';
	para.first[4] = 'x';
	para.first[5] = ' ';
	para.first[6] = 'r';
	para.first[7] = 'k';
	para.first[8] = 'l';

	para.second[0] = 'd';
	para.second[1] = ' ';
	para.second[2] = 'm';
	para.second[3] = 'l';

	x[0] = 'a';
	x[1] = 'c';
	x[2] = 'b';
	x[3] = 'f';

	cout << "Значение функции для аргумента x = 5: " << F(5, result) << endl;
	cout << "Значение функции для аргумента x = -3: " << F(-3, result) << endl;
	cout << "Значение функции для аргумента x = 22.3: " << F(22.3, result) << endl;
	cout << "Значение функции для аргумента x = [ab fx rkl]: " << F(para.first, result) << endl;
	cout << "Значение функции для аргумента x = (a, b),\n a = [ab fx rkl], b = [d ml]: " << F(para, result) << endl;
	cout << "Значение функции для аргумента x = [acbf] (vector): " << F(x, result) << endl;
	cout << "Значение функции для всех других x: " << F(&x, result) << endl;


	return 0;
}


long long int Power(int x, int count)
{
	long long int result(1);

	for (int i = 0; i < count; i++)
		result *= x;

	return result;
}

void Translate(int x, char *translation)
{
	const char* third[3] = { "", "one hundred", "two hundred" };
	const char* second1[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eigthteen", "nineteen" };
	const char* second2[10] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eigthty", "ninety" };
	const char* first[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine" };

	translation[0] = 0;

	if (x < 0)
	{
		strcat_s(translation, max, "minus ");
		x *= -1;
	}
	if (x == 0)
	{
		strcat_s(translation, max, "zero");
		return;
	}

	if (sizeof(x) == sizeof(int))
	{
		int i = x / 100;
		strcat_s(translation, max, third[i]);
		x %= 100;
		strcat_s(translation, max, " ");
		if (x < 20 && x > 9)
		{
			strcat_s(translation, max, second1[x % 10]);
			strcat_s(translation, max, " ");
		}
		else
		{
			strcat_s(translation, max, second2[x / 10]);
			x %= 10;
			strcat_s(translation, max, " ");
			strcat_s(translation, max, first[x]);
		}

	}
}

void Translate(double x, char *translation)
{
	const char* third[3] = { "", "one hundred", "two hundred" };
	const char* second1[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eigthteen", "nineteen" };
	const char* second2[10] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eigthty", "ninety" };
	const char* first[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine" };

	int eng = 0;

	translation[0] = 0;

	if (x < 0)
	{
		strcat_s(translation, max, "-");
		x *= -1;
	}
	if (x == 0)
	{
		strcat_s(translation, max, "zero");
		return;
	}
	else if (x == 1)
	{
		strcat_s(translation, max, "one");
		return;
	}
	else
		strcat_s(translation, max, "0.");

	eng = x * 100;

	if (eng < 20 && eng > 9)
	{
		strcat_s(translation, max, second1[eng % 10]);
		strcat_s(translation, max, " ");
	}
	else
	{
		strcat_s(translation, max, second2[eng / 10]);
		eng %= 10;
		strcat_s(translation, max, " ");
		strcat_s(translation, max, first[eng]);
	}
}


char Min(vector<char>& x)
{
	char min('z');
	int numb(0);

	for (int i = 0; i < x[i] != '\0'; i++)
	{
		if (x[i] < min)
		{
			min = x[i];
			numb = i;
		}
	}

	x.erase(x.begin() + numb);

	return min;
}