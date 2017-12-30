//
// Created by pawel on 27.12.17.
//

#include "Util.hpp"

rowvec Util::softMax(const rowvec &myInput) {

	rowvec toReturn(myInput.size());
	double bot = 0;
	for (double j : myInput) {
		bot += exp(j);
	}

	for (size_t i = 0; i < myInput.size(); ++i) {
		toReturn[i] = exp(myInput[i]) / bot;
	}
	return toReturn;
}

rowvec Util::tanhehe(const rowvec &myInput) {
	return tanh(myInput);
}
