#include "Matrix.h"

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
    if (this->cols != other.rows){
        throw std::runtime_error("Matrix dimensions are inappropriate for multiplication");
    }

    Matrix result(rows,other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < cols; k++) {
                sum = sum + ( data[i][k] * other.data[k][j] );
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

void Matrix::threadMultiply()
{
    throw std::runtime_error("'Threadmultiply' is not implemented");
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
            std::cout << std::setw(8) << std::setprecision(COUT_PRECISION) << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "=============================================="<<std::endl;
}
