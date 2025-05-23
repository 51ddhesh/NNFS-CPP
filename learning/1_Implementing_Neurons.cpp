// * ---------- HEADERS ---------- * //
#include <iostream>
#include <vector>
#include <iomanip>

// * ---------- fn firstNeuron() ---------- * //
void firstNeuron() {
    std::cerr << "function: firstNeuron()" << std::endl;

    std::vector<double> inputs = {1.0, 2.0, 3.0, 2.5};
    std::vector<double> weights = {0.2, 0.8, -0.5, 1.0};
    double bias = 2.0;
    
    double output = inputs[0] * weights[0] + inputs[1] * weights[1] + inputs[2] * weights[2] + inputs[3] * weights[3] + bias;
    
    std::cout << std::fixed << std::setprecision(5) << output << std::endl; 
    
    output = 0;
    
    // * Using a loop
    for (size_t i = 0; i < inputs.size(); i++) output += inputs[i] * weights[i];
    output += bias;
    
    std::cout << std::fixed << std::setprecision(5) << output << std::endl;
}

// * ---------- fn layerOfNeurons() ---------- * //
void layerOfNeurons() {
    std::cerr << "function: layerOfNeurons()" << std::endl;

    std::vector<double> inputs = {1, 2, 3, 2.5};
    std::vector<std::vector<double>> weights = {
        {0.2, 0.8, -0.5, 1}, // weights[0]
        {0.5, -0.91, 0.26, -0.5}, // weights[1]
        {-0.26, -0.27, 0.17, 0.87} // weights[2]
    };

    std::vector<double> biases = {2, 3, 0.5};

    // * Number of Neurons = Number of Outputs = weights.size() = biases.size()

    std::vector<double> outputs(weights.size());

    /*
    * outputs[0] = inputs[0] * weights[0][0] + inputs[1] * weights[0][1] + inputs[2] * weights[0][2] + inputs[3] * weights[0][3] + biases[0]
    * outputs[1] = inputs[0] * weights[1][0] + inputs[1] * weights[1][1] + inputs[2] * weights[1][2] + inputs[3] * weights[1][3] + biases[1]
    * outputs[2] = inputs[0] * weights[2][0] + inputs[1] * weights[2][1] + inputs[2] * weights[2][2] + inputs[3] * weights[2][3] + biases[2]
    */

    outputs[0] = inputs[0] * weights[0][0] + inputs[1] * weights[0][1] + inputs[2] * weights[0][2] + inputs[3] * weights[0][3] + biases[0];
    outputs[1] = inputs[0] * weights[1][0] + inputs[1] * weights[1][1] + inputs[2] * weights[1][2] + inputs[3] * weights[1][3] + biases[1];
    outputs[2] = inputs[0] * weights[2][0] + inputs[1] * weights[2][1] + inputs[2] * weights[2][2] + inputs[3] * weights[2][3] + biases[2];

    std::cout << "outputs: [ ";
    for (size_t i = 0; i < outputs.size(); i++) {
        std::cout << std::fixed << std::setprecision(5) << outputs[i] << ' ';
    }
    std::cout << "]\n";
    
    // * Resetting the output vector
    for (double &i : outputs) i = 0;
    
    // * Looping
    for (size_t i = 0; i < weights.size(); i++) {
        for (size_t j = 0; j < inputs.size(); j++) {
            outputs[i] += inputs[j] * weights[i][j];
        }
    }
    
    for (size_t i = 0; i < biases.size(); i++) outputs[i] += biases[i];
    
    std::cout << "outputs: [ ";
    for (size_t i = 0; i < outputs.size(); i++) {
        std::cout << std::fixed << std::setprecision(5) << outputs[i] << ' ';
    }
    std::cout << "]\n";
}


// * ---------- fn main() ---------- * //
int main() {
    firstNeuron();
    layerOfNeurons();
    return 0;
}