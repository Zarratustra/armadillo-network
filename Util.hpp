//
// Created by pawel on 27.12.17.
//

#ifndef ARMADILLO_NETWORK_UTIL_HPP
#define ARMADILLO_NETWORK_UTIL_HPP

#include <vector>
#include <cmath>
using namespace std;

class Util {
public:
	static vector<double> softMax(const vector<double> &myInput);
};


#endif //ARMADILLO_NETWORK_UTIL_HPP
