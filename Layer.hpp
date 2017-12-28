//
// Created by pawel on 27.12.17.
//

#ifndef ARMADILLO_NETWORK_LAYER_HPP
#define ARMADILLO_NETWORK_LAYER_HPP

#include <armadillo>
#include "Util.hpp"

using namespace std;
using namespace arma;

class Layer {
private:
	unsigned layerSize, inputSize;
	rowvec b;
	mat W;
	ActivationFunction activationFunction;

public:
	Layer(unsigned lSize, unsigned iSize, ActivationFunction a = Util::softMax);

	const ActivationFunction getActivationFunction() const;

	void setActivationFunction(ActivationFunction a);

	unsigned int getLayerSize() const;

	void setLayerSize(unsigned int layerSize);

	unsigned int getInputSize() const;

	void setInputSize(unsigned int inputSize);

	void randomize();

	const rowvec &getB() const;

	const mat &getW() const;

	rowvec computeOutput(const rowvec &input) const;

};


#endif //ARMADILLO_NETWORK_LAYER_HPP
