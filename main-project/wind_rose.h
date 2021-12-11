#pragma once
#ifndef WIND_ROSE_H
#define WIND_ROSE_H


#include "constants.h"

struct date
{
	int day;
	int month;
	int year;
};

struct wind_rose
{
	date today;
	double speed;
	char wind[MAX_STRING_SIZE];
};

#endif