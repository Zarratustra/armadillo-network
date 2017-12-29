//
// Created by pawel on 28.12.17.
//

#ifndef ARMADILLO_NETWORK_NEURALNET_HPP
#define ARMADILLO_NETWORK_NEURALNET_HPP

#include <armadillo>
#include "NetPoint.hpp"
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
	NeuralNet(const vector<unsigned>& layerSizes, unsigned outputSize, LossFunction, ActivationFunction = Util::softMax);
	// layerSizes -> input of each layer (without input layer, that usually is added only to copy input data)

	rowvec computeOutput(const rowvec &input) const;

	void learn(const mat &positions,const mat &classifications, int iterations=2000);
};


#endif //ARMADILLO_NETWORK_NEURALNET_HPP
