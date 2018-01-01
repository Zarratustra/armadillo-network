//
// Created by pawel on 27.12.17.
//

#ifndef ARMADILLO_NETWORK_UTIL_HPP
#define ARMADILLO_NETWORK_UTIL_HPP

#include <armadillo>
#include <cmath>
using namespace arma;
using namespace std;

typedef rowvec (*ActivationFunction)(const rowvec &);

typedef double (*LossFunction)(const mat &, const mat &);

class Util {
public:
	static rowvec softMax(const rowvec &myInput);

	static rowvec tanhehe(const rowvec &myInput);

	static double crossEntropyLoss(const rowvec &input, const rowvec &expectedOutput);
};


#endif //ARMADILLO_NETWORK_UTIL_HPP
