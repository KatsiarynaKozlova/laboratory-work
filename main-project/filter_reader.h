#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "wind_rose.h"

wind_rose** filter(wind_rose* array[], int size, bool (*check)(wind_rose* element), int& result_size);
bool check_book_subscription_by_wind(wind_rose* element);
bool check_book_subscription_by_speed(wind_rose* element);
#endif
