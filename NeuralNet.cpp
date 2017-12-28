//
// Created by pawel on 28.12.17.
//

#include "NeuralNet.hpp"

NeuralNet::NeuralNet(const vector<unsigned> &layerSizes, unsigned outputSize, ActivationFunction activationFunction) {
	for (size_t i=0; i<layerSizes.size()-1; ++i) {
		layers.push_back(Layer(layerSizes[i], layerSizes[i + 1], activationFunction));
	}
	layers.push_back(Layer(layerSizes.back(), outputSize, activationFunction));
}

rowvec NeuralNet::computeOutput(const rowvec &input) {
	return arma::rowvec();
}
