#include <iostream>

#include "Functions.h"

int main()
{
//Задача 1. Вывод изменяемого динамического массива
    int actual_size{};
    int logical_size{};
    
    std::cout << "Input actual size of massive : ";
    std::cin >> actual_size;
    std::cout << "Input logical size of massive : ";
    std::cin >> logical_size;
    if(logical_size > actual_size) {
        std::cout << "Error! The logical size of the array cannot exceed the actual size!" << std::endl;
    }
    else {
        int* arr = new int[actual_size];
        for(int i = 0; i < logical_size; ++i) {
            std::cout << "Input arr[" << i << "]: ";    
            std::cin >> arr[i];
        }

        std::cout << "Dynamic massive : ";
        MyFunc::print_dynamic_array(arr, logical_size, actual_size);
        
        delete[] arr;
    }

    std::cin.get();
    return 0; 
}