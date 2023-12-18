//1. Написать программу, которая включает функцию (не возвращающую значение) для создания массива, 
//каждый элемент которого равен максимальному из соответствующих значений двух других массивов.

#include <iostream>

// Функция для создания массива на основе максимальных значений
void createMaxArray(int arr1[], int arr2[], int size, int result[]) {
    for (int i = 0; i < size; ++i) {
        result[i] = std::max(arr1[i], arr2[i]);
    }
}

int main() {
    const int size = 5; // Размер массивов

    int array1[size] = { 3, 7, 2, 9, 4 };
    int array2[size] = { 5, 1, 8, 6, 3 };
    int maxArray[size];

    createMaxArray(array1, array2, size, maxArray);

    std::cout << "Массив с максимальными значениями:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << maxArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
