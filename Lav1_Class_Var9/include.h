#pragma once



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <cstring>

using namespace std;

class Array
{
private:
    char** strings; // Массив указателей на строки
    int size; // Текущий размер массива

public:

    Array();

    Array(int s);

    ~Array();


    void set_size(int s);

    void creating_an_array();

    void array_print();

    void string_by_index(int index);

    // Метод для поэлементного сцепления двух массивов с образованием нового массива
    Array* concatenate(Array& other);

    // Метод для слияния двух массивов с исключением повторяющихся элементов
    void merge_unique(const Array& arr1, const Array& arr2);

    void element_by_index(int index);
};
