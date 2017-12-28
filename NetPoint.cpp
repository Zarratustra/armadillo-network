//
// Created by pawel on 26.12.17.
//

#include "NetPoint.hpp"

const set<unsigned> NetPoint::POINT_CLASSES = set<unsigned>({0, 1 });


const vector<double> &NetPoint::getCoordinates() const {
	return coordinates;
}

void NetPoint::setCoordinates(const vector<double> &coordinates) {
	NetPoint::coordinates = coordinates;
}

unsigned int NetPoint::getPointClass() const {
	return pointClass;
}

void NetPoint::setPointClass(unsigned int pointClass) {
	NetPoint::pointClass = pointClass;
}

NetPoint::NetPoint(const vector<double> &myCoordinates, unsigned int pClass)
:coordinates(myCoordinates)
,pointClass(pClass)
{}

bool NetPoint::belongsToClass(unsigned compClass) {
	return compClass == pointClass;
}

ostream &operator<<(ostream &os, const NetPoint &netPoint) {
	os << "[";
	for (size_t i = 0; i < netPoint.coordinates.size()-1; ++i) {
		os << netPoint.coordinates[i] << ", ";
	}
	os << netPoint.coordinates[netPoint.coordinates.size() - 1] << "]";
	return os;
}
