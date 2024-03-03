#include "Matrix.h"

int main(){

    Matrix a(
        { {1,2,3},
          {2,3,4},
          {4,5,7} 
        });
    
    Matrix b(
        { {1,2,3},
          {2,3,4},
          {4,5,7} 
        });
    //  a.Matrix::fillRandomNumbers();
    //  b.Matrix::fillRandomNumbers();
    a.print();
    b.print();
    auto start = std::chrono::steady_clock::now();
    Matrix c = a.Matrix::multiply(b);
    c.Matrix::print();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}