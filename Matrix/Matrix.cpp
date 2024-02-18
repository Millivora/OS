#include "Matrix.h"

Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;

    for (auto& row : data) {
        row.resize(cols);
    }
}

Matrix &Matrix::multiply(const Matrix& other)
{
    
}

void Matrix::fillRandomNumbers()
{ 
    std::random_device rd;
    std::uniform_real_distribution<double> dist(RANGE_BEGIN,RANGE_END);

    for (int i = 0; i < rows; i++){
        for (int j = 0 ; j < cols; j++){
            data[i][j] = dist(rd);
        }
    }
}

void Matrix::print() const
{
    for(auto& row : data ){
        for(auto& value : row){
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
