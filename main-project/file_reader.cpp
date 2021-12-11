#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include<cstring>


date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}


void read(const char* file_name, wind_rose* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            wind_rose* item = new wind_rose;


            file >> tmp_buffer;
            item->today = convert(tmp_buffer);
            file >> item->speed;

            file.read(tmp_buffer, 1);
            file.getline(item->wind, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Error open file";
    }

}