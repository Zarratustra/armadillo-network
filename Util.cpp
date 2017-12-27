//
// Created by pawel on 27.12.17.
//

#include "Util.hpp"

vector<double> Util::softMax(const vector<double> &myInput) {

	vector<double> toReturn(myInput.size());
	double bot = 0;
	for (double j : myInput) {
		bot += exp(j);
	}

	for (size_t i = 0; i < myInput.size(); ++i) {
		toReturn[i] = exp(myInput[i]) / bot;
	}
	return toReturn;
}
