#include "include.h"
#include <iostream>



    Array::Array()
    {
        size = 0;
        strings = NULL;
        for (int i = 0; i != size; i++) {
            strings[i] = new char[50];
        }
    }

    Array::Array(int s)
    {
        size = s;
        strings = new char* [size];
        for (int i = 0; i < size; i++) {
            strings[i] = new char[50];
        }
    }

    Array::~Array() {
        delete[]strings;
    }


    void Array::set_size(int s)
    {
        size = s;
        strings = new char* [size];
        for (int i = 0; i < size; i++) {
            strings[i] = 0;
        }
    }

    void Array::creating_an_array()
    {
        for (int i = 0; i < size; i++) cin >> strings[i];
    }

    void Array::array_print()
    {
        for (int i = 0; i != size; i++) {
            cout << strings[i] << " ";
        }
    }

    void Array::string_by_index(int index)
    {
        if (index >= 0 && index < size) {
            cout << strings[index] << " ";
        }
        else cout << "������, ����� �� ������� �������";
    }

    // ����� ��� ������������� ��������� ���� �������� � ������������ ������ �������
    Array* Array::concatenate(Array& other) {
        int newSize = size + other.size;
        Array* result = new Array(newSize);

        for (int i = 0; i < size; ++i) {
            strcpy(result->strings[i], strings[i]);
        }
        for (int i = 0; i < other.size; ++i) {
            strcpy(result->strings[size + i], other.strings[i]);
        }

        return result;
    }

    // ����� ��� ������� ���� �������� � ����������� ������������� ���������
    void Array::merge_unique(const Array& arr1, const Array& arr2) {
        int i, j, k = 0;
        bool isDuplicate;
        Array result(arr1.size + arr2.size);
        // ��������� �������� ������� �������
        for (i = 0; i < arr1.size; i++) {
            isDuplicate = false;
            // ���������, ���� �� ������� � ����������
            for (j = 0; j < k; j++) {
                if (strcmp(arr1.strings[i], result.strings[j]) == 0) {
                    isDuplicate = true;
                    break;
                }
            }
            // ���� ������� �� ������ � ����������, ��������� ���
            if (!isDuplicate) {
                result.strings[k++] = arr1.strings[i];
            }
        }

        // ��������� �������� ������� �������
        for (i = 0; i < arr2.size; i++) {
            isDuplicate = false;
            // ���������, ���� �� ������� � ����������
            for (j = 0; j < k; j++) {
                if (strcmp(arr2.strings[i], result.strings[j]) == 0) {
                    isDuplicate = true;
                    break;
                }
            }
            // ���� ������� �� ������ � ����������, ��������� ���
            if (!isDuplicate) {
                result.strings[k++] = arr2.strings[i];
            }
        }
        result.size = k;
        for (int i = 0; i < result.size; ++i) {
            cout << result.strings[i] << " ";
        }
    }

    void Array::element_by_index(int index)
    {
        if (index >= 0 && index < size) {
            cout << strings[index];
        }
        else cout << "������, ����� �� ������� �������";
    }


