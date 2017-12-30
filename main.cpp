#include <iostream>
#include <armadillo>

#include "Layer.hpp"
#include "NeuralNet.hpp"

using namespace std;
using namespace arma;

int rightRound(double babyYouSpinMe){
    if(babyYouSpinMe > 0.5){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
//	cout << "No a teraz drogie dzieci" << "\n" ;
//	cout << "Trzeba dane łapać w sieci." << "\n";
//	cout << "Zmalujemy coś w gnuplocie" << "\n";
//	cout << "Wywiesimy to na płocie." << "\n";
//	cout << "EZ\nxD" << endl;

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

    positions.load("positions.csv", csv_ascii);
    y.load("przynaleznosc.csv");

//	cout << "Positions size: " << positions.n_rows << " " << positions.n_cols << endl;
//	cout << "y size: " << y.n_rows << " " << y.n_cols << endl;


    vector<unsigned> layerSizes = vector<unsigned>({2, 5});

    NeuralNet net(layerSizes,2, nullptr);

    net.learn(positions,y);

    rowvec maxes = max(positions,0);
    rowvec mins = min(positions,0);

    int nPoints = 100;

    vec xx = linspace<vec>(mins(0), maxes(0), nPoints);
    vec yy = linspace<vec>(mins(1), maxes(1), nPoints);

//    cout << "Maks" << maxes << "min " << mins << endl;

    for(int i=0;i<nPoints;i++){
        for(int j=0;j<nPoints;j++){
//        cout << "Aha" << endl;
            rowvec input = { xx(i),yy(j) };
//            cout << "Czego?" << endl;
            rowvec output = net.computeOutput(input);
            cout << xx(i) << "," << yy(j) << "," << rightRound(output(0)) << endl;
        }
    }

	return 0;
}
