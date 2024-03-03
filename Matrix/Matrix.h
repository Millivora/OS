#ifndef MATRIX_H
#define MATRIX_H

#include "libraries.h"
#include "constants.h"

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;


    bool isRangeValid(int begin,int end,int rows) const;
    void partialMultiply(int begin, int end, const Matrix& other, Matrix& result) const;
   

public:
    Matrix(int _rows, int _cols);
    Matrix(std::vector<std::vector<double>> _data);
    Matrix multiply(const Matrix& other) const;
    Matrix multiplyThread(const Matrix& other) const;
    void fillRandomNumbers();
    void print() const;
    int getRows() const;
};

#endif