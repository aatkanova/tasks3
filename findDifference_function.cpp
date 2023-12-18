//9. Написать функцию для нахождения для каждой строки двумерного динамического массива значение разности между 
//наибольшим и наименьшим элементами.

#include <iostream>
#include <limits>

// Функция для нахождения разности между наибольшим и наименьшим элементами для каждой строки
void findDifference(int** arr, int rows, int cols) {
    for (int row = 0; row < rows; ++row) {
        int minVal = std::numeric_limits<int>::max(); // Начальное значение для минимального элемента
        int maxVal = std::numeric_limits<int>::min(); // Начальное значение для максимального элемента

        // Находим минимальное и максимальное значения в текущей строке
        for (int col = 0; col < cols; ++col) {
            if (arr[row][col] < minVal) {
                minVal = arr[row][col];
            }
            if (arr[row][col] > maxVal) {
                maxVal = arr[row][col];
            }
        }

        std::cout << "Разность между наибольшим и наименьшим элементами строки " << row + 1 << ": " << maxVal - minVal << std::endl;
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

    std::cout << "Разность между наибольшим и наименьшим элементами для каждой строки:\n";
    findDifference(array, rows, cols);

    // Освобождение памяти, выделенной для двумерного массива
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
