#ifndef __AXON_UTILS_HPP_
#define __AXON_UTILS_HPP_

#include <iostream>
#include <vector>
#include <utility>

using Shape = std::pair<size_t, size_t>;

struct Vector {
    std::vector<double> V;
    bool orientation; // True -> horizontal, False -> vertical
};

struct Matrix {
    std::vector<std::vector<double>> M;
    Matrix();
    // Constructor to resize the matrix
    Matrix(size_t rows, size_t columns, double init_value);
};

class Axon {
    public:
        // Returns the shapes of the Vector and Matrix
        Shape shape(const Vector &vec); 
        Shape shape(const Matrix &matrix);

        // Convert a column Vector to a column Matrix
        Matrix to_column_matrix(const Vector &vec);

};

#endif // __AXON_UTILS_HPP_
