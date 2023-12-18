//12.Написать функцию для нахождения произведения элементов для каждого столбца двумерного динамического массива. Поменять местами столбцы с максимальным и минимальным 
//значением произведения.

#include <iostream>
#include <limits>

// Функция для нахождения произведения элементов для каждого столбца
void productInColumns(int** arr, int rows, int cols, int product[]) {
    for (int col = 0; col < cols; ++col) {
        product[col] = 1;
        for (int row = 0; row < rows; ++row) {
            product[col] *= arr[row][col];
        }
    }
}

// Функция для нахождения индекса столбца с минимальным произведением
int findMinProductColumn(int product[], int cols) {
    int minIndex = 0;
    int minProduct = product[0];
    for (int i = 1; i < cols; ++i) {
        if (product[i] < minProduct) {
            minProduct = product[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Функция для нахождения индекса столбца с максимальным произведением
int findMaxProductColumn(int product[], int cols) {
    int maxIndex = 0;
    int maxProduct = product[0];
    for (int i = 1; i < cols; ++i) {
        if (product[i] > maxProduct) {
            maxProduct = product[i];
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

    int* columnProducts = new int[cols];
    productInColumns(array, rows, cols, columnProducts);

    int minIndex = findMinProductColumn(columnProducts, cols);
    int maxIndex = findMaxProductColumn(columnProducts, cols);

    std::cout << "Столбец с минимальным произведением: " << minIndex + 1 << std::endl;
    std::cout << "Столбец с максимальным произведением: " << maxIndex + 1 << std::endl;

    swapColumns(array, rows, minIndex, maxIndex);

    std::cout << "Массив после обмена столбцов:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти, выделенной для двумерного массива и произведений столбцов
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    delete[] columnProducts;

    return 0;
}
