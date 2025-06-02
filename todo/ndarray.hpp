#ifndef __AXON_NDARRAY_HPP_ 
#define __AXON_NDARRAY_HPP_

#include <iostream>
#include <vector>

class Ndarray {
    private:
        std::vector<double> data; // Store the data in a single row
        std::vector<size_t> shape; // shape
        std::vector<size_t> strides; // number of steps to take to move to the required index

    public:
        Ndarray(const std::vector<size_t> &shape_, double init_val = 0.0);
        double& operator() ();

    
};


#endif // __AXON_NDARRAY_HPP_