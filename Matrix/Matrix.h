#ifndef MATRIX_H
#define MATRIX_H

#include "libraries.h"
#include "CONSTANTS.h"

class Matrix {
    private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

    public:
    Matrix(int _rows, int _cols);
    Matrix& multiply(const Matrix& other);
    void fillRandomNumbers();
    void print() const;
};

#endif