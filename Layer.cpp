//
// Created by pawel on 27.12.17.
//

#include "Layer.hpp"

const ActivationFunction Layer::getActivationFunction() const {
	return activationFunction;
}

void Layer::setActivationFunction(ActivationFunction a) {
	Layer::activationFunction = a;
}

Layer::Layer(unsigned iSize, unsigned lSize, ActivationFunction a)
:layerSize(lSize)
,inputSize(iSize)
,b(lSize, fill::zeros)
,W(iSize, lSize, fill::zeros)
,activationFunction(a)
{}

unsigned int Layer::getLayerSize() const {
	return layerSize;
}

void Layer::setLayerSize(unsigned int layerSize) {
	Layer::layerSize = layerSize;
	b.zeros(layerSize);
	W.zeros(inputSize, layerSize);
}

unsigned int Layer::getInputSize() const {
	return inputSize;
}

void Layer::setInputSize(unsigned int inputSize) {
	W.zeros(inputSize, layerSize);
}

const rowvec &Layer::getB() const {
	return b;
}

const mat &Layer::getW() const {
	return W;
}

void Layer::randomize(){
    W=randu<mat>(inputSize, layerSize) / sqrt(W.n_rows);
}

rowvec Layer::computeOutput(const rowvec &input) const {
	rowvec tmpResult = input * W + b;
	return activationFunction(tmpResult);
}
