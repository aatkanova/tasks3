//4. Написать функцию для нахождения количества положительных чисел в каждом столбце двумерного 
//динамического массива.


#include <iostream>

// Функция для нахождения количества положительных чисел в каждом столбце двумерного массива
void countPositiveInColumns(int** arr, int rows, int cols) {
    for (int col = 0; col < cols; ++col) {
        int count = 0;
        for (int row = 0; row < rows; ++row) {
            if (arr[row][col] > 0) {
                count++;
            }
        }
        std::cout << "Столбец " << col + 1 << ": " << count << " положительных чисел\n";
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

    std::cout << "Количество положительных чисел в каждом столбце:\n";
    countPositiveInColumns(array, rows, cols);

    // Освобождение памяти, выделенной для двумерного массива
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
