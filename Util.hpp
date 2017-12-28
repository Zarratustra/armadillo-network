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

typedef double (*LossFunction)(const rowvec &, const rowvec &);

class Util {
public:
	static rowvec softMax(const rowvec &myInput);
};


#endif //ARMADILLO_NETWORK_UTIL_HPP
