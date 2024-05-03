// Lav1_Class_Var9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

  Array()
    {
        size = 0;
        strings = NULL;
        for (int i = 0; i != size; i++) {
            strings[i] = new char[50];
        }
    }

    Array(int s)
    {        
            size = s;
            strings = new char*[size];
            for (int i = 0; i < size; i++) {
                strings[i] = new char[50];
            }
    }

    ~Array() {
        delete[]strings;
    }

    
    void set_size(int s)
    {
        size = s;
        strings = new char*[size];
        for (int i = 0; i < size; i++) {
            strings[i] = 0;
        }
    }

    void creating_an_array()
    {   
        for (int i = 0; i < size; i++) cin >> strings[i];
    }

    void array_print()
    {
        for (int i = 0; i != size; i++) {
            cout << strings[i] << " ";
        }
    }

    void string_by_index(int index)
    {
        if (index >= 0 && index < size) {
            cout << strings[index] << " ";
        }
        else cout << "Ошибка, выход за границы массива";
    }

    // Метод для поэлементного сцепления двух массивов с образованием нового массива
    Array* concatenate(Array& other) {
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

    // Метод для слияния двух массивов с исключением повторяющихся элементов
    void merge_unique(const Array& arr1, const Array& arr2) {
        int i, j, k = 0;
        bool isDuplicate;
        Array result(arr1.size + arr2.size);
        // Проверяем элементы первого массива
        for (i = 0; i < arr1.size; i++) {
            isDuplicate = false;
            // Проверяем, есть ли элемент в результате
            for (j = 0; j < k; j++) {
                if (strcmp(arr1.strings[i], result.strings[j]) == 0) {
                    isDuplicate = true;
                    break;
                }
            }
            // Если элемент не найден в результате, добавляем его
            if (!isDuplicate) {
                result.strings[k++] = arr1.strings[i];
            }
        }

        // Проверяем элементы второго массива
        for (i = 0; i < arr2.size; i++) {
            isDuplicate = false;
            // Проверяем, есть ли элемент в результате
            for (j = 0; j < k; j++) {
                if (strcmp(arr2.strings[i], result.strings[j]) == 0) {
                    isDuplicate = true;
                    break;
                }
            }
            // Если элемент не найден в результате, добавляем его
            if (!isDuplicate) {
                result.strings[k++] = arr2.strings[i];
            }
        }
        result.size = k;
        for (int i = 0; i < result.size; ++i) {
            cout << result.strings[i] << " ";
        }
    }

    void element_by_index(int index)
    {
        if (index >= 0 && index < size) {
            cout << strings[index];
        }
        else cout << "Ошибка, выход за границы массива";
    }
};



int Menu()
{
    int select;
    do
    {       
        cout << "1 - Вывод всего массива";cout << endl;
        cout << "2 - Печать строки по индексу";cout << endl;
        cout << "3 - Сцепление двух массивов";cout << endl;
        cout << "4 - Слияние двух массивов";cout << endl;
        cout << "5 - Вывод элемента массива по индексу";cout << endl;
        cout << "6 - Выход";cout << endl;
        cout << "Введите пункт меню: ";
        cin >> select;
        cout << endl;
    } while ((select < 1) || (select > 6));

    return select;
}

int main()
{    
    setlocale(LC_ALL, "Russian");

   // int size;
    //cout << "Введите размер массива: ";
    //cin >> size;

    cout << "Введите три строки для первого массива и три строки для второго массива: ";cout << endl;

    Array arr1(3), arr2(3);
    arr1.creating_an_array();
    arr2.creating_an_array();

    int select;   

    do {
        cout << endl;
        select = Menu();
        switch (select)
        {       
        case 1:
        {
            arr1.array_print();
            arr2.array_print();
            cout << endl;
            break;
        }
        case 2:
        {
            int ind;
            cout << "Введите индекс строки, индексы начинаются с [0]: ";
            cin >> ind;
            arr1.string_by_index(ind);
            arr2.string_by_index(ind);
            cout << endl;
            break;
        }
        case 3:
        {
            Array* concatenatedArray = arr1.concatenate(arr2);
            cout << "Массив после операции поэлементного сцепления двух массивов с образованием нового массива: " << endl;
            concatenatedArray->array_print();
            cout << endl;
            break;
        }
        case 4:
        {                   
            cout << "Массив после слияния двух массивов с исключением повторяющихся элементов: " << endl;
            Array res;
            res.merge_unique(arr1, arr2);
            cout << endl;
            break;

        }
        case 5:
        {
            int n;
            int ind;
            cout << "Из какого массива вывести элемент? Введите 1 или 2: ";
            cin >> n;
            cout << "Введите индекс эелемента, индексы начинаются с [0]: ";
            cin >> ind; cout << endl;
            n == 1 ? arr1.element_by_index(ind) : arr2.element_by_index(ind);
            cout << endl;
            break;
        }

        }
    } while (select != 6);
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
