
#include <iostream>
#include<iomanip>

using namespace std;

#include"wind_rose.h"
#include"constants.h"
#include"file_reader.h"
#include"filter_reader.h"


void output(wind_rose* rose)
{

	cout << "����.........:   ";
	cout << setw(2) << setfill('0') << rose->today.day << "-";
	cout << setw(2) << setfill('0') << rose->today.month << "-";
	cout << setw(4) << setfill('0') << rose->today.year << "\n";
	cout << "����������� �����.....:   ";
	cout << rose->wind << "\n";

	cout << "�������� �����....:   ";
	cout << rose->speed << " m/sec\n";
	cout << "\n";
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "������������ ������ #8. GIT\n";
	cout << "������� #6. Wind Rose\n";
	cout << "������� ��������� ���������\n";
	cout << "������ 14\n";
	wind_rose* roses[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", roses, size);
		cout << "***** ���� ������ *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(roses[i]);
		}
		bool (*check_function)(wind_rose*);


		cout << "�������� ����������  : ";

		int item;

		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:


			check_function = check_book_subscription_by_wind;
			cout << "*****   ��������� ��������� 1    *****\n\n";
			break;
		case 2:
			check_function = check_book_subscription_by_speed;
			cout << "*****     ��������� ���������� 2    *****\n\n";
			break;
		default:
			throw " ��� ����� ���������� ";
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


