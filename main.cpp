#include <iostream>
#include <armadillo>

#include "Layer.hpp"
#include "NeuralNet.hpp"

using namespace std;
using namespace arma;

int main()
{
	cout << "No a teraz drogie dzieci" << "\n" ;
	cout << "Trzeba dane łapać w sieci." << "\n";
	cout << "Zmalujemy coś w gnuplocie" << "\n";
	cout << "Wywiesimy to na płocie." << "\n";
	cout << "EZ\nxD" << endl;

//	mat A = randu<mat>(4,5);
//	mat B = randu<mat>(4,5);
//
//	mat C = A * B.t();
//	cout << C << endl;
//	cout << det(C) << endl;
//	rowvec a = randu < rowvec > (4);
//	cout << "LOL\n" << a * A << endl;

	mat positions;
    mat y;

    positions.load("positions.csv");
    y.load("przynaleznosc.csv");

    vector<unsigned> layerSizes = vector<unsigned>({2, 5 });

    NeuralNet* net = new NeuralNet(layerSizes,2,NULL);

    net->learn(positions,y);

	return 0;
}