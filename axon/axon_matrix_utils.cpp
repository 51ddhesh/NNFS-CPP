#include "axon_utils.hpp"

Vector::Vector() : orientation(1) {}

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

// Find the transpose of the Vector
Matrix Axon::T(const Vector &vec) {
    return Axon::to_column_matrix(std::cref(vec));
}

// Find the transpose of the Matrix
Matrix Axon::T(const Matrix &mat) {
    size_t rows = mat.M.size();        // Number of rows in original matrix
    size_t columns = mat.M[0].size();  // Number of columns in original matrix

    // Create a new matrix for the transpose, with `columns` rows and `rows` columns
    Matrix transposedMatrix(columns, rows, 0);  // Initialize with zeros (or any default value)

    // Fill the transposed matrix
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            transposedMatrix.M[j][i] = mat.M[i][j];  // Switch rows and columns
        }
    }

    return transposedMatrix;
}


// Print the vector
void Axon::print(const Vector &vec) {
    if (vec.orientation) {
        size_t length = vec.V.size();
        std::cout << '[';
        for (size_t i = 0; i < length; i++) {
            if (i == length - 1) {
                std::cout << vec.V[i];
            }
            else {
                std::cout << vec.V[i] << ", ";
            }    
        }
        std::cout << "]\n";
    } else {
        size_t height = vec.V.size();
        std::cout << "[";
        for (size_t i = 0; i < height; i++) {
            if (i == 0) {
                std::cout << '[' << vec.V[i] << "],\n"; 
            }
            else if (i == height - 1) {
                std::cout << " [" << vec.V[i] << ']'; 
            }
            else {
                std::cout << " [" << vec.V[i] << "],\n"; 
            }    
        }
        std::cout << "]\n";
    }
}

void Axon::print(const Matrix &mat) {
    size_t rows = mat.M.size();
    size_t columns = mat.M[0].size();
    std::cout << '[';
    for (size_t i = 0; i < rows; i++) {
        if (i == 0) {
            std::cout << '[';
        } else {
            std::cout << " [";
        }
        
        for (size_t j = 0; j < columns; j++) {
            if (j == 0) {
                std::cout << mat.M[i][j] << ", ";
            }
            else if (j == columns - 1) {
                std::cout << mat.M[i][j];
            }
            else {
                std::cout << mat.M[i][j] << ", ";
            }
        }
        
        if (i != rows - 1) {
            std::cout << "],\n";
        } else {
            std::cout << "]";
        }
    }
    std::cout << "]\n";
}


