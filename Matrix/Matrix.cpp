#include "Matrix.h"

bool Matrix::isRangeValid(int begin, int end, int rows)
{
    return (begin < 0 && end > rows && begin >= end);
}

void Matrix::partialMultiply(int begin, int end, const Matrix &other, Matrix &result)
{
    if (cols != other.rows){
        throw std::runtime_error("Matrix dimensions are inappropriate for multiplication");
    }

    if (!isRangeValid(begin,end,rows)){
        throw std::runtime_error("Range for multiplication is inappropriate");
    }

    for (int i = begin; i < end; i++){
        for (int j = 0; j < other.cols; j++){
            double sum = 0.0;
            for (int k = 0; k < cols; k++){
                sum = sum + (data[i][k] * other.data[k][j]);
            }
            result.data[i][j] = sum;
        }
    }
}

Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;


    data.resize(rows);
    for (auto& row : data) {
        row.resize(cols);
    }
}

Matrix::Matrix(std::vector<std::vector<double>> _data)
{
    rows = _data.size();
    cols = _data[0].size();

    data = _data;
}

Matrix Matrix::multiply(const Matrix& other)
{
    Matrix result(rows,other.cols);
    
    partialMultiply(0,rows,other,result);

    return result;
}

void Matrix::multiplyThread(const Matrix& other)
{
    // throw std::runtime_error("'Threadmultiply' is not implemented");
    
}

void Matrix::fillRandomNumbers()
{ 
    std::random_device rd;
    std::uniform_real_distribution<double> dist(CONSTANTS::RAND_RANGE_BEGIN,CONSTANTS::RAND_RANGE_END);

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
            std::cout << std::setw(8) << std::setprecision(CONSTANTS::COUT_PRECISION) << value << " ";
        }
        std::cout << std::endl;
    }
    // std::cout << "=============================================="<<std::endl;
}
