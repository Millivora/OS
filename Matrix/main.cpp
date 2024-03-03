#include "Matrix.h"

int main(){

    // Matrix a(
    //     { {1,2,3},
    //       {2,3,4},
    //       {4,5,7} 
    //     });
    
    // Matrix b(
    //     { {1,2,3},
    //       {2,3,4},
    //       {4,5,7} 
    //     });
    Matrix a(10,10);
    Matrix b(10,10);
    a.Matrix::fillRandomNumbers();
    b.Matrix::fillRandomNumbers();
    // a.print();
    // b.print();
    auto start = std::chrono::steady_clock::now();
    Matrix c = a.Matrix::multiplyThread(b);
     c.Matrix::print();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Threads: Time: " << duration.count() << " milliseconds" << std::endl;



    start = std::chrono::steady_clock::now();
    Matrix d = a.Matrix::multiply(b);
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "No threads: Time: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}