//13.Написать функцию для нахождения произведения элементов для каждой строки двумерного 
//динамического массива. Поменять местами строки с максимальным и минимальным значением произведения.

#include <iostream>
#include <limits>

// Функция для нахождения произведения элементов для каждой строки
void productInRows(int** arr, int rows, int cols, int product[]) {
    for (int row = 0; row < rows; ++row) {
        product[row] = 1;
        for (int col = 0; col < cols; ++col) {
            product[row] *= arr[row][col];
        }
    }
}

// Функция для нахождения индекса строки с минимальным произведением
int findMinProductRow(int product[], int rows) {
    int minIndex = 0;
    int minProduct = product[0];
    for (int i = 1; i < rows; ++i) {
        if (product[i] < minProduct) {
            minProduct = product[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для нахождения индекса строки с максимальным произведением
int findMaxProductRow(int product[], int rows) {
    int maxIndex = 0;
    int maxProduct = product[0];
    for (int i = 1; i < rows; ++i) {
        if (product[i] > maxProduct) {
            maxProduct = product[i];
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

    int* rowProducts = new int[rows];
    productInRows(array, rows, cols, rowProducts);

    int minIndex = findMinProductRow(rowProducts, rows);
    int maxIndex = findMaxProductRow(rowProducts, rows);

    std::cout << "Строка с минимальным произведением: " << minIndex + 1 << std::endl;
    std::cout << "Строка с максимальным произведением: " << maxIndex + 1 << std::endl;

    swapRows(array, cols, minIndex, maxIndex);

    std::cout << "Массив после обмена строк:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти, выделенной для двумерного массива и произведений строк
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    delete[] rowProducts;

    return 0;
}
