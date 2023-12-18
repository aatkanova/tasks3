//7. Написать функцию для нахождения для каждого столбца двумерного динамического массива 
//отклонение его элементов от среднего значения для этого столбца.

#include <iostream>
#include <cmath>

// Функция для нахождения отклонения элементов от среднего значения для каждого столбца
void calculateDeviation(int** arr, int rows, int cols) {
    for (int col = 0; col < cols; ++col) {
        // Вычисление среднего значения для текущего столбца
        double columnSum = 0.0;
        for (int row = 0; row < rows; ++row) {
            columnSum += arr[row][col];
        }
        double columnMean = columnSum / rows;

        // Вычисление отклонения элементов от среднего значения
        double deviationSum = 0.0;
        for (int row = 0; row < rows; ++row) {
            deviationSum += std::abs(arr[row][col] - columnMean);
        }
        double deviation = deviationSum / rows;

        std::cout << "Отклонение элементов столбца " << col + 1 << " от среднего значения: " << deviation << std::endl;
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

    std::cout << "Отклонение элементов от среднего значения для каждого столбца:\n";
    calculateDeviation(array, rows, cols);

    // Освобождение памяти, выделенной для двумерного массива
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
