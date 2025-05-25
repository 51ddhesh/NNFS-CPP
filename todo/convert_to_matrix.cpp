#include "../engine/axon.cpp"

Matrix toMatrix(const Vector &vec) {
    Matrix mat;
    int length = static_cast<int>(vec.V.size());
    if (vec.orientation) {
        // horizontal vector → 1 row, length cols
        mat.M.resize(1);
        mat.M[0] = vec.V;
    } else {
        // vertical vector → length rows, 1 col
        mat.M.resize(length);
        for (int i = 0; i < length; ++i) {
            mat.M[i].resize(1);
            mat.M[i][0] = vec.V[i];
        }
    }
    return mat;
}
