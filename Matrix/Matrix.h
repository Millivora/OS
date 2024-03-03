#ifndef MATRIX_H
#define MATRIX_H

#include "libraries.h"
#include "CONSTANTS.h"

class Matrix {
    private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;


    bool isRangeValid(int begin,int end,int rows);
    void partialMultiply(int begin, int end, const Matrix& other, Matrix& result);


public:
    Matrix(int _rows, int _cols);
    Matrix(std::vector<std::vector<double>> _data);
    Matrix multiply(const Matrix& other);
    void multiplyThread(const Matrix& other);
    void fillRandomNumbers();
    void print() const;
};

#endif