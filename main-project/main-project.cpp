
#include <iostream>
#include<iomanip>

using namespace std;

#include"wind_rose.h"
#include"constants.h"
#include"file_reader.h"
#include"filter_reader.h"


void output(wind_rose* rose)
{

	cout << "Дата.........:   ";
	cout << setw(2) << setfill('0') << rose->today.day << "-";
	cout << setw(2) << setfill('0') << rose->today.month << "-";
	cout << setw(4) << setfill('0') << rose->today.year << "\n";
	cout << "Направление ветра.....:   ";
	cout << rose->wind << "\n";

	cout << "Скорость ветра....:   ";
	cout << rose->speed << " m/sec\n";
	cout << "\n";
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Лабораторная работа #8. GIT\n";
	cout << "Вариант #6. Wind Rose\n";
	cout << "Козлова Екатерина Вадимовна\n";
	cout << "Группа 14\n";
	wind_rose* roses[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", roses, size);
		cout << "***** РОЗА ВЕТРОВ *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(roses[i]);
		}
		bool (*check_function)(wind_rose*);


		cout << "Выберите фильтрацию  : ";

		int item;

		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:


			check_function = check_book_subscription_by_wind;
			cout << "*****   Результат фильрации 1    *****\n\n";
			break;
		case 2:
			check_function = check_book_subscription_by_speed;
			cout << "*****     Результат фильтрации 2    *****\n\n";
			break;
		default:
			throw " Нет такой фильтрации ";
		}
		int new_size;
		wind_rose** filtered = filter(roses, size, check_function, new_size);
		for (int i = 0; i < new_size; i++)
		{
			output(filtered[i]);
		}
		delete[] filtered;
		for (int i = 0; i < size; i++)
		{
			delete roses[i];
		}
	}

	catch (const char* error)
	{
		cout << error << "\n";
	}
	return 0;


}


