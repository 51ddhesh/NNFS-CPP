#ifndef __AXON_
#define __AXON_

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
};

class Axon {
    public:
        // Returns the shapes of the Vector and Matrix
        Shape shape(const Vector &vec); 
        Shape shape(const Matrix &matrix);

        // Convert a column Vector to a column Matrix
        Matrix tomatrix(const Vector &vec);

};

#endif // __AXON_
