#ifndef Functions_H
#define Functions_H

namespace MyFunc {

    void print_dynamic_array(int* arr, int logical_size, int actual_size); // Вывод массива

    void append_to_dynamic_array(int el, int*& arr, int & logical_size, int & actual_size); //Добавление в изменяемый динамический массив

    void remove_dynamic_array_head(int*& arr, int & logical_size, int & actual_size); //Удаление первого элемента из изменяемого динамического массива

}

#endif