//11.Написать функцию для нахождения суммы элементов для каждой строки двумерного 
//динамического массива. Поменять местами строки с максимальным и минимальным значением суммы.

#include <iostream>
#include <limits>

// Функция для нахождения суммы элементов для каждой строки
void sumInRows(int** arr, int rows, int cols, int sum[]) {
    for (int row = 0; row < rows; ++row) {
        sum[row] = 0;
        for (int col = 0; col < cols; ++col) {
            sum[row] += arr[row][col];
        }
    }
}

// Функция для нахождения индекса строки с минимальной суммой
int findMinSumRow(int sum[], int rows) {
    int minIndex = 0;
    int minSum = sum[0];
    for (int i = 1; i < rows; ++i) {
        if (sum[i] < minSum) {
            minSum = sum[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для нахождения индекса строки с максимальной суммой
int findMaxSumRow(int sum[], int rows) {
    int maxIndex = 0;
    int maxSum = sum[0];
    for (int i = 1; i < rows; ++i) {
        if (sum[i] > maxSum) {
            maxSum = sum[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функция для обмена строк
void swapRows(int** arr, int cols, int row1, int row2) {
    for (int i = 0; i < cols; ++i) {
        int temp = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp;
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

    int* rowSums = new int[rows];
    sumInRows(array, rows, cols, rowSums);

    int minIndex = findMinSumRow(rowSums, rows);
    int maxIndex = findMaxSumRow(rowSums, rows);

    std::cout << "Строка с минимальной суммой: " << minIndex + 1 << std::endl;
    std::cout << "Строка с максимальной суммой: " << maxIndex + 1 << std::endl;

    swapRows(array, cols, minIndex, maxIndex);

    std::cout << "Массив после обмена строк:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти, выделенной для двумерного массива и сумм строк
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    delete[] rowSums;

    return 0;
}
