//
// Created by pawel on 28.12.17.
//

#ifndef ARMADILLO_NETWORK_NEURALNET_HPP
#define ARMADILLO_NETWORK_NEURALNET_HPP

#include <armadillo>
#include "Layer.hpp"
#include "Util.hpp"
#include <vector>
using namespace std;
using namespace arma;

class NeuralNet {
private:
	vector<Layer> layers;
	LossFunction lossFunction;

public:
	NeuralNet(const vector<unsigned>& layerSizes, unsigned outputSize, ActivationFunction = Util::softMax, LossFunction);
	// layerSizes -> input of each layer

	rowvec computeOutput(const rowvec &input) const;

	void learn(const rowvec &input, const rowvec &expectedOutput);
};


#endif //ARMADILLO_NETWORK_NEURALNET_HPP
