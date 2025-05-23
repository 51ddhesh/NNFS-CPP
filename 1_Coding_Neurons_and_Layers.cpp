#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    // * The First Neuron
    std::vector<double> inputs = {1.0, 2.0, 3.0, 2.5};
    std::vector<double> weights = {0.2, 0.8, -0.5, 1.0};
    double bias = 2.0;

    double output = inputs[0] * weights[0] + inputs[1] * weights[1] + inputs[2] * weights[2] + inputs[3] * weights[3] + bias;
    
    std::cout << std::fixed << std::setprecision(5) << output << std::endl; 

    output = 0;

    for (size_t i = 0; i < inputs.size(); i++) {
        output += inputs[i] * weights[i];
    }
    output += bias;

    std::cout << std::fixed << std::setprecision(5) << output << std::endl;
}