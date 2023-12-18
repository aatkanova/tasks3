//3. Написать функцию. В одномерном динамическом массиве найти максимальный по модулю 
//элемент массива и сумму элементов массива, расположенных между первым и вторым положительными элементами.

#include <iostream>

// Функция для поиска максимального элемента по модулю в массиве
int findMaxAbsolute(int arr[], int size) {
    int maxAbs = 0;
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i]) > abs(maxAbs)) {
            maxAbs = arr[i];
        }
    }
    return abs(maxAbs);
}

// Функция для нахождения суммы элементов между первым и вторым положительными элементами
int sumBetweenPositives(int arr[], int size) {
    int sum = 0;
    bool foundFirstPositive = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            if (foundFirstPositive) {
                return sum;
            }
            foundFirstPositive = true;
        }
        if (foundFirstPositive && arr[i] > 0) {
            sum = 0;
        } else if (foundFirstPositive) {
            sum += arr[i];
        }
    }
    return 0; // Если нет двух положительных элементов
}

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int maxAbsolute = findMaxAbsolute(arr, size);
    std::cout << "Максимальный по модулю элемент массива: " << maxAbsolute << std::endl;

    int sumBetween = sumBetweenPositives(arr, size);
    if (sumBetween != 0) {
        std::cout << "Сумма элементов между первым и вторым положительными элементами: " << sumBetween << std::endl;
    } else {
        std::cout << "Нет двух положительных элементов для вычисления суммы." << std::endl;
    }

    delete[] arr; // Освобождаем память, выделенную для массива

    return 0;
}
