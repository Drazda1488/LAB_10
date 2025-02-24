#include <iostream>
#include <ctime>  // ��� time()
#include <clocale> // ��� setlocale

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int rows, cols, rowToDelete;

    // 1. ���� ������� ������� � ������ ������ ��� ��������
    cout << "������� ���������� �����: ";
    cin >> rows;
    cout << "������� ���������� ��������: ";
    cin >> cols;
    cout << "������� ����� ������ ��� �������� (������� � 0): ";
    cin >> rowToDelete;

    // �������� ������������ ���������� ������ ������
    if (rowToDelete < 0 || rowToDelete >= rows) {
        cerr << "������: ������������ ����� ������ ��� ��������." << endl;
        return 1; // ���������� ��� ������
    }

    // 2. ������������ ���������� ������������� �������
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // 3. ���������� ������� ���������� �������
    unsigned seed = time(0); // ���������� time ��� seed
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // ����������� ��������� ��������� ����� (�� ���������, �� ��������)
            seed = (seed * 9301 + 49297) % 233280;
            matrix[i][j] = seed % 100; // ��������� ������� �� 0 �� 99
        }
    }

    // 4. ����� ��������� ������� (��� ��������)
    cout << "�������� ������:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 5. ������������ ������ ������� ����� �������� ������
    int newRows = rows - 1;
    int** newMatrix = new int* [newRows];
    for (int i = 0; i < newRows; ++i) {
        newMatrix[i] = new int[cols];
    }

    // ����������� ������ � ����� ������, ��������� ������ ��� ��������
    int currentRow = 0;
    for (int i = 0; i < rows; ++i) {
        if (i != rowToDelete) {
            for (int j = 0; j < cols; ++j) {
                newMatrix[currentRow][j] = matrix[i][j];
            }
            currentRow++;
        }
    }

    // 6. ����� ������ �������
    cout << "\n������ ����� �������� ������ " << rowToDelete << ":" << endl;
    for (int i = 0; i < newRows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // 7. ������������ ������, ���������� ��� �������
    // �������� ��������� �������
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // �������� ������ �������
    for (int i = 0; i < newRows; ++i) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;

    return 0;
}
