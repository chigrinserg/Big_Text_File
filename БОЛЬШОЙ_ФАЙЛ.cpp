#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono> // для получения времени
#include <string>
#include <fstream>  // работа с файлами
#include <cstdlib> // для получения рандомных чисел
#include <ctime>
#include <array>

void write_arr(const std::string& filename, const int* arr, const int n) //функция записи в файл
{
    std::fstream fs;

    fs.open(filename, std::fstream::app);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        //fs << n << '\n';  // записываем размер массива
        for (int i = 0; i < n; i++)
            fs << arr[i] << ' '; // записываем значения через пробел
        fs << '\n';

        fs.close(); // закрываем файл
    }
}
void read_arr(const std::string& filename, int*& arr, int& n)
{
    std::fstream fs;

    fs.open(filename, std::fstream::in);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        fs >> n;  // читаем размер массива
        arr = new int[n];
        for (int i = 0; i < n; i++)
            fs >> arr[i]; // читаем из файла разделительные символы - пробел и перенос строки
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";

        fs.close(); // закрываем файл
    }
}
int getMax(int* arr, int n) //функция нахождения максимального значения в массиве
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countSort(int* arr, int n) //функция сортировки подсчетом
{	
    int max = getMax(arr, n);
    int* count = new int[max + 1];

    for (int i = 0; i < max + 1; ++i)
    {
        count[i] = 0;
    }

    int* output = new int[n];

    for (int i = 0; i < n; ++i)
    {
        ++count[arr[i]];
    }

    for (int i = 1; i < max + 1; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
    delete[] count;
    delete[] output;
}
int main()  
{
    srand(time(nullptr));
    setlocale(LC_ALL, "Rus");
    const int size = 50000000;
    std::string filename = "array_data.txt";
    int* array1 = new int[size];
    int* array2 = new int[size];
    int* array3 = new int[size];
    int* array4 = new int[size];
    int* array5 = new int[size];
    int* array6 = new int[size];
    int* array7 = new int[size];
    int* array8 = new int[size];
    int* array9 = new int[size];
    int* array10 = new int[size];
    auto start = std::chrono::high_resolution_clock::now(); // сохраняем время начала работы алгоритма
    for(int i=0; i<size; ++i)
    { array1[i]= 1 + rand() % 1001; }
    countSort(array1, size);
    write_arr(filename, array1, size); // 

    for (int i = 0; i < size; ++i)
    { array2[i] = 1000 + rand() % 1001; }
    countSort(array2, size);
    write_arr(filename, array2, size); // 

    for (int i = 0; i < size; ++i)
    {  array3[i] = 2000 + rand() % 1001;}
    countSort(array3, size);
    write_arr(filename, array3, size); // 

    for (int i = 0; i < size; ++i)
    {  array4[i] = 3000 + rand() % 1001; }
    countSort(array4, size);
    write_arr(filename, array4, size); // 

    for (int i = 0; i < size; ++i)
    {  array5[i] = 4000 + rand() % 1001; }
    countSort(array5, size);
    write_arr(filename, array5, size); // 

    for (int i = 0; i < size; ++i)
    {  array6[i] = 5000 + rand() % 1001; }
    countSort(array6, size);
    write_arr(filename, array6, size); // 

    for (int i = 0; i < size; ++i)
    {  array7[i] = 6000 + rand() % 1001;
    }
    countSort(array7, size);
    write_arr(filename, array7, size); // 

    for (int i = 0; i < size; ++i)
    {  array8[i] = 7000 + rand() % 1001; }
    countSort(array8, size);
    write_arr(filename, array8, size); // 

    for (int i = 0; i < size; ++i)
    {  array9[i] = 8000 + rand() % 1001;  }
    countSort(array9, size);
    write_arr(filename, array9, size); // 

    for (int i = 0; i < size; ++i)
    {  array10[i] = 9000 + rand() % 1001; }
    countSort(array10, size);
    write_arr(filename, array10, size); // 

    auto finish = std::chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " sec" << std::endl; // вычисляем продолжительность работ

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;
    delete[] array6;
    delete[] array7;
    delete[] array8;
    delete[] array9;
    delete[] array10;
    return 0;
}
//Elapsed time : 5353.36 sec

//randomDigits_3[i] = 200 + rand() % 101; // 200 ... 300