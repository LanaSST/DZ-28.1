#include <iostream>
#include "Functions.h"

namespace MyFunc {
 
    void print_dynamic_array(int* arr, int logical_size, int actual_size) {
        for (int i = 0; i < actual_size; ++i) {
            if(i < logical_size) {
                std::cout << arr[i] << " ";
            }
            else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }  
        
    void append_to_dynamic_array(int el, int*& arr, int & logical_size, int & actual_size) {
        if(logical_size < actual_size) {
            arr[logical_size++] = el;
        }
        else {
            int* arr_new = new int[actual_size * 2];
            for(int i = 0; i < actual_size; ++i) {
                arr_new[i] = arr[i];
            }
            actual_size *= 2;                
            arr_new[logical_size++] = el;                
            delete[] arr;
            arr = arr_new;
            arr_new = nullptr;
        }
    }

    void remove_dynamic_array_head(int*& arr, int & logical_size, int & actual_size) {
        if(logical_size - 1 > actual_size / 3) {
            for(int i = 0; i < logical_size; ++i) {
                arr[i] = arr[i+1];
            }
            arr[logical_size--] = 0;    
        }
        else {
            int* arr_new = new int[actual_size / 3];
            for(int i = 0; i < logical_size - 1; ++i) {
                arr_new[i] = arr[i+1];
            }
            actual_size /= 3;
            logical_size--;
            delete[] arr;
            arr = arr_new;
            arr_new = nullptr;
        }    

    }

}