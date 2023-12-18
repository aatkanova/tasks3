//5. Написать функцию для нахождения суммы чисел для каждого столбца двумерного 
//динамического массива, удовлетворяющих условию xi,j > a. Здесь a- произвольная величина.

#include <iostream>

// Функция для нахождения суммы чисел для каждого столбца,
// удовлетворяющих условию x[i][j] > a
void sumGreaterThanA(int** arr, int rows, int cols, int a) {
    for (int col = 0; col < cols; ++col) {
        int sum = 0;
        for (int row = 0; row < rows; ++row) {
            if (arr[row][col] > a) {
                sum += arr[row][col];
            }
        }
        std::cout << "Сумма чисел в столбце " << col + 1 << ", удовлетворяющих условию: " << sum << std::endl;
    }
}

int main() {
    int rows, cols, threshold;
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

    std::cout << "Введите значение a: ";
    std::cin >> threshold;

    std::cout << "Сумма чисел для каждого столбца, удовлетворяющих условию:\n";
    sumGreaterThanA(array, rows, cols, threshold);

    // Освобождение памяти, выделенной для двумерного массива
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
