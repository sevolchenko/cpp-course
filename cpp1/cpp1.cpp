#include <iostream>

using namespace std;


int** swapped(int** matrix, int rows, int cols) {
    int** swapped_matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        swapped_matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
            swapped_matrix[i][j] = matrix[rows - i - 1][j];
    }
    return swapped_matrix;
}

int main()
{
    
    int rows, cols;
    cin >> rows;
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];
    }

    cout << "\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    int** swapped_matrix = swapped(matrix, rows, cols);

    cout << "\n";
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << swapped_matrix[i][j] << " ";
        cout << "\n";
    }

    cout << "\n";

    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;

    for (int i = 0; i < rows; ++i)
        delete[] swapped_matrix[i];
    delete[] swapped_matrix;
    swapped_matrix = nullptr;

    return 0;
}