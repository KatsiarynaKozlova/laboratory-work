#include "file_reader.h"
#include <cstring>
#include <iostream>

wind_rose** filter(wind_rose* array[], int size, bool (*check)(wind_rose* element), int& result_size)
{
	wind_rose** result = new wind_rose * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_book_subscription_by_wind(wind_rose* element)
{

	return strcmp(element->wind, "North") == 0;

}

bool check_book_subscription_by_speed(wind_rose* element)
{
	return element->speed >= 5;
}
