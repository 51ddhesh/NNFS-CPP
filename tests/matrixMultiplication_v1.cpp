#include <iostream>
#include <vector>
#include <omp.h>

using Matrix = std::vector<std::vector<double>>;

// Naive matrix multiplication with OpenMP parallelization
Matrix multiply_naive_parallel(const Matrix& A, const Matrix& B) {
    size_t rowsA = A.size();
    size_t colsA = A[0].size();
    size_t colsB = B[0].size();

    Matrix C(rowsA, std::vector<double>(colsB, 0.0));

    #pragma omp parallel for
    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsB; ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < colsA; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

int main() {
    // Example 600x600 multiplication
    size_t n = 600;
    Matrix A(n, std::vector<double>(n, 1.0));
    Matrix B(n, std::vector<double>(n, 2.0));

    Matrix C = multiply_naive_parallel(A, B);

    std::cout << "C[0][0] = " << C[0][0] << "\n"; // Expect 1*2*n = 1200

    return 0;
}
