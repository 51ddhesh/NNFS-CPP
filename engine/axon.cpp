#include "axon.hpp"


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


