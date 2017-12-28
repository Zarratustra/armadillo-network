//
// Created by pawel on 28.12.17.
//

#include "NeuralNet.hpp"

NeuralNet::NeuralNet(const vector<unsigned> &layerSizes, unsigned outputSize, ActivationFunction activationFunction, LossFunction lossFunction1) {
	for (size_t i=0; i<layerSizes.size()-1; ++i) {
		layers.emplace_back(layerSizes[i], layerSizes[i + 1], activationFunction);
	}
	layers.emplace_back(layerSizes.back(), outputSize, activationFunction);
	this->lossFunction = lossFunction1;
}

rowvec NeuralNet::computeOutput(const rowvec &input) {
	rowvec result = layers.at(0).computeOutput(input);
	for (size_t i = 1; i < layers.size(); ++i) {
		result = layers[i].computeOutput(result);
	}
	return result;
}
