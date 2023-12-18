//10.Написать функцию для нахождения суммы элементов для каждого столбца двумерного динамического массива. 
//Поменять местами столбцы с максимальным и минимальным значением суммы.

#include <iostream>
#include <limits>

// Функция для нахождения суммы элементов для каждого столбца
void sumInColumns(int** arr, int rows, int cols, int sum[]) {
    for (int col = 0; col < cols; ++col) {
        sum[col] = 0;
        for (int row = 0; row < rows; ++row) {
            sum[col] += arr[row][col];
        }
    }
}

// Функция для нахождения индекса столбца с минимальной суммой
int findMinSumColumn(int sum[], int cols) {
    int minIndex = 0;
    int minSum = sum[0];
    for (int i = 1; i < cols; ++i) {
        if (sum[i] < minSum) {
            minSum = sum[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для нахождения индекса столбца с максимальной суммой
int findMaxSumColumn(int sum[], int cols) {
    int maxIndex = 0;
    int maxSum = sum[0];
    for (int i = 1; i < cols; ++i) {
        if (sum[i] > maxSum) {
            maxSum = sum[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функция для обмена столбцов
void swapColumns(int** arr, int rows, int col1, int col2) {
    for (int i = 0; i < rows; ++i) {
        int temp = arr[i][col1];
        arr[i][col1] = arr[i][col2];
        arr[i][col2] = temp;
    }
}

int main() {
    int rows, cols;
    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;

    // Создание двумерного динамического массива
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }

    int* columnSums = new int[cols];
    sumInColumns(array, rows, cols, columnSums);

    int minIndex = findMinSumColumn(columnSums, cols);
    int maxIndex = findMaxSumColumn(columnSums, cols);

    std::cout << "Столбец с минимальной суммой: " << minIndex + 1 << std::endl;
    std::cout << "Столбец с максимальной суммой: " << maxIndex + 1 << std::endl;

    swapColumns(array, rows, minIndex, maxIndex);

    std::cout << "Массив после обмена столбцов:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти, выделенной для двумерного массива и сумм столбцов
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    delete[] columnSums;

    return 0;
}
