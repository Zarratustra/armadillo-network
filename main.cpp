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

double lossFunction(const mat & positions, const mat & y)
{
	/*int sum = 0;
	for(int i=0;i<300;i++)
	{
		rowvec input = { positions(i,0),positions(i,1) };
		rowvec output = net.computeOutput(input);
		if(rightRound(output(1)) == y(0,i))
			sum++;
	}
	return sum*100/300;*/return 0;
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


    vector<unsigned> layerSizes = vector<unsigned>({2, 3});

    NeuralNet net(layerSizes,2, lossFunction);

    net.learn(positions,y);

    rowvec maxes = max(positions,0) + 0.5;
    rowvec mins = min(positions,0) - 0.5;

    int nPoints = 200;

    vec xx = linspace<vec>(mins(0), maxes(0), nPoints);
    vec yy = linspace<vec>(mins(1), maxes(1), nPoints);

//    cout << "Maks" << maxes << "min " << mins << endl;

    for(int j=0;j<nPoints;j++){
        for(int i=0;i<nPoints;i++){
//        cout << "Aha" << endl;
            rowvec input = { xx(i),yy(j) };
//            cout << "Czego?" << endl;
            rowvec output = net.computeOutput(input);
            cout << xx(i) << "," << yy(j) << "," << rightRound(output(1)) << endl;
        }
    }
    
    mat test;
    mat test_y;

    test.load("test.csv", csv_ascii);
    test_y.load("przynaleznosc_test.csv");
    
    int sum = 0;
	for(int i=0;i<300;i++)
	{
		rowvec input = { test(i,0),test(i,1) };
		rowvec output = net.computeOutput(input);
		if(rightRound(output(1)) == test_y(0,i))
			sum++;
	}
	cout << (double)sum*100/300 << endl;
    
    //cout << net.lossFunction(test, test_y) << endl;

	return 0;
}
