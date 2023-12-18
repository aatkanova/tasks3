//2. Написать программу, которая включает функцию (возвращающую значение) для создания массива, 
//каждый элемент которого, равен минимальному из соответствующих значений двух других массивов.

#include <iostream>

// Функция для создания массива на основе минимальных значений
int* createMinArray(int arr1[], int arr2[], int size) {
    int* result = new int[size];
    for (int i = 0; i < size; ++i) {
        result[i] = std::min(arr1[i], arr2[i]);
    }
    return result;
}

int main() {
    const int size = 5; // Размер массивов

    int array1[size] = { 3, 7, 2, 9, 4 };
    int array2[size] = { 5, 1, 8, 6, 3 };

    int* minArray = createMinArray(array1, array2, size);

    std::cout << "Массив с минимальными значениями:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << minArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] minArray; // Освобождаем память, выделенную для minArray

    return 0;
}
