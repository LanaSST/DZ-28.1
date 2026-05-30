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
        if (logical_size == 0) {
            return;
        }
        auto logical_size_new = logical_size - 1;

        if (logical_size_new == 0) {
            delete[] arr;
            arr = nullptr;
            logical_size = 0;
            actual_size = 1;
            return;
        }

        if(logical_size_new > actual_size / 3) {
            for(int i = 0; i < logical_size_new; ++i) {
                arr[i] = arr[i+1];
            }
        }
        else {
            auto actual_size_new = actual_size / 3;
            int* arr_new = new int[actual_size_new];
            for(int i = 0; i < logical_size_new; ++i) {
                arr_new[i] = arr[i+1];
            }
            actual_size = actual_size_new;
            delete[] arr;
            arr = arr_new;
            arr_new = nullptr;
        }    
        logical_size = logical_size_new;

    }

}
