#include<iostream>

using namespace std;

const char START = 's';
const char ROOM = '-';
const char FINAL = 'e';

bool isInBounds(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

bool isExit(char **matrix, int row, int col) {
    return matrix[row][col] == FINAL;
}

void markAsVisited(bool **visited, int row, int col) {
    visited[row][col] = true;
}

void unmarkAsVisited(bool **visited, int row, int col) {
    visited[row][col] = false;
}

bool isRoom(char **matrix, int row, int col) {
    return matrix[row][col] == ROOM;
}

bool allVisited(char **matrix, bool **visited, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == ROOM && !visited[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void countPaths(
        char **matrix,
        bool **visited,
        int row,
        int col,
        int rows,
        int cols,
        int &pathsCount) {
    if (!isInBounds(row, col, rows, cols)) {
        return;
    }

    if (isExit(matrix, row, col) && allVisited(matrix, visited, rows, cols)) {
        pathsCount++;
    } else if (!visited[row][col] && (isRoom(matrix, row, col) || matrix[row][col] == START)) {
        markAsVisited(visited, row, col);

        countPaths(matrix, visited, row, col + 1, rows, cols, pathsCount);
        countPaths(matrix, visited, row + 1, col, rows, cols, pathsCount);
        countPaths(matrix, visited, row, col - 1, rows, cols, pathsCount);
        countPaths(matrix, visited, row - 1, col, rows, cols, pathsCount);

        unmarkAsVisited(visited, row, col);
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    char **matrix = new char *[rows];

    int startRow = -1;
    int startCol = -1;
    string input;
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];
        cin >> input;

        for (int j = 0; j < input.length(); ++j) {
            matrix[i][j] = input[j];
            if (input[j] == START) {
                startRow = i;
                startCol = j;
            }
        }
    }

    bool **visited = new bool *[rows];
    for (int i = 0; i < rows; ++i) {
        visited[i] = new bool[cols];
        for (int j = 0; j < cols; ++j) {
            visited[i][j] = false;
        }
    }


    int pathsCount = 0;
    countPaths(matrix, visited, startRow, startCol, rows, cols, pathsCount);
    cout << pathsCount;
}