#include "processing.h"
#include <iostream>
using namespace std;

double process(wind_rose* array[], int size, double res)
{
	int mon;
	cin >> mon;
	double sum=0;
	int link = 0;
	
	double* array2 = new double[size];
	for (int i = 0; i < size; i++) {
		if (array[i]->today.month == mon) {
			link++;
			
			sum = sum + array[i]->speed;
		}
	}
	
	res = (sum / link);

	return res;
}
