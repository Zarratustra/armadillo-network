//
// Created by pawel on 28.12.17.
//

#include "NeuralNet.hpp"

NeuralNet::NeuralNet(const vector<unsigned> &layerSizes, unsigned outputSize, LossFunction lossFunction1, ActivationFunction activationFunction) {
	for (size_t i=0; i<layerSizes.size()-1; ++i) {
		layers.emplace_back(layerSizes[i], layerSizes[i + 1], activationFunction);
	}
	layers.emplace_back(layerSizes.back(), outputSize, activationFunction);
	this->lossFunction = lossFunction1;
}

rowvec NeuralNet::computeOutput(const rowvec &input) const {
	rowvec result = layers.at(0).computeOutput(input);
	for (size_t i = 1; i < layers.size(); ++i) {
		result = layers[i].computeOutput(result);
	}
	return result;
}

void NeuralNet::learn(const mat &positions,const mat &classifications, int iterations){

    int epsilon = 0.01; //# learning rate for gradient descent
    int reg_lambda = 0.01; //# regularization strength

    for (size_t i=0; i<layers.size(); ++i) {
        layers[i].randomize();
    }

    mat W1 = layers[0].getW();
    mat b1 = layers[0].getB();
    mat W2 = layers[1].getW();
    mat b2 = layers[1].getB();

    cout << "La"<< endl;

//    mat positions;
//    positions.zeros(trainingData.size(),2);
//
//    for (size_t i=0; i<trainingData.size(); ++i) {
//        positions(i,0)=trainingData[i].getCoordinates()[0];
//        positions(i,1)=trainingData[i].getCoordinates()[1];
//    }

    for (size_t i=0; i<iterations; ++i) {

          mat z1 = positions*W1 + repmat(b1,positions.size(),1);
          mat a1 = tanh(z1);

          cout << "Oreja"<< endl;

          mat z2 = a1*W2 + repmat(b2,positions.size(),1);
          mat exp_scores = exp(z2);
          mat probs = exp_scores / repmat(sum(exp_scores, 1),1,2);

          cout << "de"<< endl;

          mat delta3 = probs;
          int j;
          for(j=0;j<positions.n_rows;j++){
              delta3(j,classifications[j])-=1;
          }

          mat dW2 = a1.t()*delta3;
          mat db2 =sum(delta3,0);

          mat delta2 = (delta3*W2.t()) * (1-pow(a1,2));
          mat dW1 = positions.t()*delta2;
          mat db1 = sum(delta2, 0);

//        //        # Add regularization terms (b1 and b2 don't have regularization terms)
            dW2 += reg_lambda * W2;
            dW1 += reg_lambda * W1;
//
//        //        # Gradient descent parameter update
            W1 += -epsilon * dW1;
            b1 += -epsilon * db1;
            W2 += -epsilon * dW2;
            b2 += -epsilon * db2;

    }



}
