#include <iostream>
#include <ctime>  // Для time()
#include <clocale> // Для setlocale

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int rows, cols, rowToDelete;

    // 1. Ввод размера массива и номера строки для удаления
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    cout << "Введите номер строки для удаления (начиная с 0): ";
    cin >> rowToDelete;

    // Проверка корректности введенного номера строки
    if (rowToDelete < 0 || rowToDelete >= rows) {
        cerr << "Ошибка: Некорректный номер строки для удаления." << endl;
        return 1; // Возвращаем код ошибки
    }

    // 2. Формирование двумерного динамического массива
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // 3. Заполнение массива случайными числами
    unsigned seed = time(0); // Используем time как seed
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Самодельный генератор случайных чисел (не идеальный, но работает)
            seed = (seed * 9301 + 49297) % 233280;
            matrix[i][j] = seed % 100; // Заполняем числами от 0 до 99
        }
    }

    // 4. Вывод исходного массива (для проверки)
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 5. Формирование нового массива после удаления строки
    int newRows = rows - 1;
    int** newMatrix = new int* [newRows];
    for (int i = 0; i < newRows; ++i) {
        newMatrix[i] = new int[cols];
    }

    // Копирование данных в новый массив, пропуская строку для удаления
    int currentRow = 0;
    for (int i = 0; i < rows; ++i) {
        if (i != rowToDelete) {
            for (int j = 0; j < cols; ++j) {
                newMatrix[currentRow][j] = matrix[i][j];
            }
            currentRow++;
        }
    }

    // 6. Вывод нового массива
    cout << "\nМассив после удаления строки " << rowToDelete << ":" << endl;
    for (int i = 0; i < newRows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // 7. Освобождение памяти, выделенной под массивы
    // Удаление исходного массива
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // Удаление нового массива
    for (int i = 0; i < newRows; ++i) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;

    return 0;
}
