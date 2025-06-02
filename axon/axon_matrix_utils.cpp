#include "axon_utils.hpp"

// Default Constructor
Matrix::Matrix() : M() {}

// Resize Constructor
Matrix::Matrix(size_t rows, size_t columns, double init_value) {
    M = std::vector<std::vector<double>>(rows, std::vector<double> (columns, init_value));
}

Shape Axon::shape(const Vector &vec) {
    size_t length = vec.V.size();
    if (vec.orientation) {
        // * Horizontal (Row Vector) -> Shape: (1, length)
        return {1, length};
    }
    else {
        // * Vertical (Column Vector) -> Shape: (length, 1)
        return {length, 1};
    }
}

Shape Axon::shape(const Matrix &matrix) {
    size_t rows = matrix.M.size();
    size_t columns = rows > 0 ? matrix.M[0].size() : 0;
    return {rows, columns};
}

Matrix Axon::to_column_matrix(const Vector &vec) {
    if (!vec.orientation) {
        throw std::invalid_argument("The argument is a column vector. This function is defined for a row vector");
    }
    size_t rows = vec.V.size();
    Matrix M(rows, 1, 0); // Declare a matrix of `rows` rows and 1 column
    for (auto &i : vec.V) {
        std::vector<double> temp = {i}; // Create a 1D array of each element of the Vector
        M.M.push_back(temp); // Push that element into the new matrix
    }
    return M;
}
