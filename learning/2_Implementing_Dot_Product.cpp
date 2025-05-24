// * ---------- Headers ---------- * //
#include <iostream>
#include <vector>

// * ---------- Aliases ---------- * //
using Vector = std::vector<double>;
using Matrix = std::vector<Vector>;

// * ---------- fn dot(weights, inputs) -> forward_pass ---------- * //
// * Finds the dot product of two vectors => 1D x 1D
Vector dot(const Vector &weights, const Vector &inputs) {
    size_t weight_size = weights.size();
    size_t input_size = inputs.size();
    if (weight_size != input_size) {
        throw std::invalid_argument("Shape mismatch. Argument 1 length: " + std::to_string(weight_size) + ". Argument 2 length: " + std::to_string(input_size) + ". They both must be same.");
    }
    Vector dotProduct(weight_size);
    for (size_t i = 0; i < weight_size; i++) {
        dotProduct[i] = weights[i] * inputs[i];
    }
    return dotProduct;
}

// * Finds the dot product of two matrices => 2D x 2D
Matrix dot(const Matrix &weights, const Matrix &inputs) {
    size_t weights_rows = weights.size();
    size_t weights_columns = weights[0].size();
    size_t inputs_rows = inputs.size();
    size_t inputs_columns = inputs[0].size();
    if (weights_columns != inputs_rows) {
        throw std::invalid_argument("Shape mismatch. Argument 1 has " + \
            std::to_string(weights_columns) + " columns. Argument 2 has " + \
            std::to_string(inputs_rows) + " rows. They must be the same.");    
    }
    // * Implementing the naive matrix multiplication algorithm
    
    Matrix result(weights_rows, Vector(inputs_columns, 0.0));

    for (size_t i = 0; i < weights_rows; i++) {
        for (size_t j = 0; j < inputs_columns; j++) {
            for (size_t k = 0; k < weights_columns; k++) {
                result[i][j] += weights[i][k] * inputs[k][j];
            }
        } 
    }
    return result;
}

// * Finds the dot product of a vector and a matrix => 1D x 2D
Vector dot(const Vector &vec, const Matrix &matrix) {
    size_t vector_size = vec.size();
    size_t matrix_rows = matrix.size();
    if (vector_size != matrix_rows) {
        throw std::invalid_argument("Shape mismatch. Vector size: " + std::to_string(vector_size) + \
            ", Matrix rows: " + std::to_string(matrix_rows));
    }
    size_t matrix_columns = matrix[0].size();
    Vector result(matrix_columns, 0.0);
    for (size_t i = 0; i < matrix_columns; i++) {
        for (size_t j = 0; j < vector_size; j++) {
            result[i] += vec[j] * matrix[j][i];
        }
    }
    return result;
}

Vector transpose(Vector &v) {

}

Matrix transpose(Matrix &v) {

}


int main() {

    return 0;
}
