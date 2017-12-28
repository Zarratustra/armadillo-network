//
// Created by pawel on 27.12.17.
//

#ifndef ARMADILLO_NETWORK_LAYER_HPP
#define ARMADILLO_NETWORK_LAYER_HPP

#include <armadillo>
#include "Util.hpp"

using namespace std;
using namespace arma;

typedef rowvec (*ActivationFunction)(const rowvec &);

class Layer {
private:
	unsigned layerSize, inputSize;
	rowvec b;
	mat W;
	ActivationFunction activationFunction;

public:
	const ActivationFunction getActivationFunction() const;

	void setActivationFunction(ActivationFunction a const);

	Layer(unsigned lSize, unsigned iSize, ActivationFunction a = Util::softMax);

	unsigned int getLayerSize() const;

	void setLayerSize(unsigned int layerSize);

	unsigned int getInputSize() const;

	void setInputSize(unsigned int inputSize);

	const rowvec &getB() const;

	const mat &getW() const;

	rowvec computeOutput(const rowvec &input);

};


#endif //ARMADILLO_NETWORK_LAYER_HPP
