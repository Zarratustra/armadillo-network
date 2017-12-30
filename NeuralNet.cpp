//
// Created by pawel on 28.12.17.
//

#include "NeuralNet.hpp"

NeuralNet::NeuralNet(const vector<unsigned> &layerSizes, unsigned outputSize, LossFunction lossFunction1, ActivationFunction activationFunction) {

	for (size_t i=0; i<layerSizes.size()-1; ++i) {
		layers.emplace_back(layerSizes[i], layerSizes[i + 1], Util::tanhehe);
	}
	layers.emplace_back(layerSizes.back(), outputSize, activationFunction);
	this->lossFunction = lossFunction1;
}

rowvec NeuralNet::computeOutput(const rowvec &input) const {
//    cout << "No me digas nada" << endl;
	rowvec result = layers.at(0).computeOutput(input);
	for (size_t i = 1; i < layers.size(); ++i) {
		result = layers[i].computeOutput(result);
	}
	return result;
}

void NeuralNet::learn(const mat &positions,const mat &classifications, int iterations){

    double epsilon = 0.01; //# learning rate for gradient descent
    double reg_lambda = 0.01; //# regularization strength

    for (size_t i=0; i<layers.size(); ++i) {
        layers[i].randomize();
    }
//	cout << "Layers size: " << layers.size() << endl;

    mat W1 = layers[0].getW();
    mat b1 = layers[0].getB();
    mat W2 = layers[1].getW();
    mat b2 = layers[1].getB();

//    cout << "La"<< endl;
//
//    cout << "W1 " << W1.n_rows << " " << W1.n_cols << endl;
//    cout << W1 << endl;
//    cout << "W2 " << W2.n_rows << " " << W2.n_cols << endl;
//    cout << W2 << endl;
//    cout << "b1 " << b1.n_rows << " " << b1.n_cols << endl;
//    cout << b1 << endl;
//    cout << "b2 " << b2.n_rows << " " << b2.n_cols << endl;
//    cout << b2 << endl;


//    mat positions;
//    positions.zeros(trainingData.size(),2);
//
//    for (size_t i=0; i<trainingData.size(); ++i) {
//        positions(i,0)=trainingData[i].getCoordinates()[0];
//        positions(i,1)=trainingData[i].getCoordinates()[1];
//    }

    for (size_t i=0; i<iterations; ++i) {

          mat z1 = positions*W1 + repmat(b1, positions.n_rows, 1);
          mat a1 = tanh(z1);

//          cout << "Oreja"<< endl;

          mat z2 = a1*W2 + repmat(b2,positions.n_rows,1);
          mat exp_scores = exp(z2);
          mat probs = exp_scores / repmat(sum(exp_scores, 1),1,2);

//          cout << "de"<< endl;

          mat delta3 = probs;
          int j;
          for(j=0;j<positions.n_rows;j++){
              delta3(j,classifications[j])-=1;
          }

//		cout << "aaa" << endl;
          mat dW2 = a1.t()*delta3;
          mat db2 =sum(delta3,0);

//		cout << "bbb" << endl;
		    mat temp = delta3*W2.t();
//		    cout << "zzz" << endl;
          mat delta2 = (temp) % (1-pow(a1,2));
//          cout << "yyy" << endl;
          mat dW1 = positions.t()*delta2;
          mat db1 = sum(delta2, 0);

//		cout << "ccc" << endl;
//        //        # Add regularization terms (b1 and b2 don't have regularization terms)
            dW2 += reg_lambda * W2;
            dW1 += reg_lambda * W1;
//		cout << "ddd" << endl;

//            cout << "dW1" << endl << dW1 << endl;
//            cout << "przystosowane: " << endl << (-epsilon * dW1) << endl;

        //        # Gradient descent parameter update
            W1 = W1 + (-epsilon * dW1);
            b1 = b1 + (-epsilon * db1);
            W2 = W2 + (-epsilon * dW2);
            b2 = b2 + (-epsilon * db2);
//		cout << "eee"  << endl;
    }

    layers[0].W = W1;
    layers[0].b = b1;
    layers[1].W = W2;
    layers[1].b = b2;

//    cout << "------------------------------------------------" << endl;
//
//     cout << "W1 " << W1.n_rows << " " << W1.n_cols << endl;
//        cout << W1 << endl;
//        cout << "W2 " << W2.n_rows << " " << W2.n_cols << endl;
//        cout << W2 << endl;
//        cout << "b1 " << b1.n_rows << " " << b1.n_cols << endl;
//        cout << b1 << endl;
//        cout << "b2 " << b2.n_rows << " " << b2.n_cols << endl;
//        cout << b2 << endl;



}
