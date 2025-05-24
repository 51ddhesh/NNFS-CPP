#ifndef __NUMPY_H
#define __NUMPY_H

#include <iostream>
#include <vector>
#include <utility> // For std::pair

template <typename T>
class numpy {
public:
    // Shape for 1D vector
    std::pair<int, int> shape(const std::vector<T>& A) {
        int x = A.size();
        std::cerr << "(" << x << ",)" << std::endl;
        return {x, 1}; 
    }

    // Shape for 2D vector
    std::pair<int, int> shape(const std::vector<std::vector<T>>& A) {
        int x = A.size();
        int y = (x > 0) ? A[0].size() : 0; 
        std::cerr << "(" << x << ", " << y << ")" << std::endl;
        return {x, y};
    }
};

#endif // __NUMPY_H
