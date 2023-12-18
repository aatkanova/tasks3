//6. Написать функцию для нахождения произведения чисел для каждого столбца двумерного массива:

#include <iostream>

// Функция для нахождения произведения чисел для каждого столбца
void productInColumns(int** arr, int rows, int cols) {
    for (int col = 0; col < cols; ++col) {
        int product = 1; // Начальное значение произведения равно 1
        for (int row = 0; row < rows; ++row) {
            product *= arr[row][col];
        }
        std::cout << "Произведение чисел в столбце " << col + 1 << ": " << product << std::endl;
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

    std::cout << "Произведение чисел для каждого столбца:\n";
    productInColumns(array, rows, cols);

    // Освобождение памяти, выделенной для двумерного массива
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
