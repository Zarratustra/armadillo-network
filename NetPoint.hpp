//
// Created by pawel on 26.12.17.
//

#ifndef ARMADILLO_NETWORK_NETPOINT_HPP
#define ARMADILLO_NETWORK_NETPOINT_HPP

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class NetPoint {
private:
	vector<double> coordinates;
	unsigned pointClass;

public:
	static const set<unsigned> POINT_CLASSES;

	NetPoint(const vector<double> &myCoordinates = {0, 0}, unsigned pClass = *POINT_CLASSES.begin());
	bool belongsToClass(unsigned compClass);

	const vector<double> &getCoordinates() const;

	void setCoordinates(const vector<double> &coordinates);

	unsigned int getPointClass() const;

	void setPointClass(unsigned int pointClass);

	friend ostream &operator<<(ostream &os, const NetPoint &netPoint);
};


#endif //ARMADILLO_NETWORK_NETPOINT_HPP
