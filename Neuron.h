#pragma once
#include <vector>
#include <cstdlib>
#include "Net.h"

struct Connection {
	double weight;
	double deltaWeight;
};

class Neuron
{
public:
	Neuron(unsigned numOutputs);
	void feedForward(const Layer &prevLayer);
	void setOutputVal(double val) { outPutVal = val; };
	double getOutPutVal() const { return outPutVal; };
private:
	static double randomWeight() { return rand() / double(RAND_MAX); };
	double outPutVal;
	std::vector<Connection> outPutWeights;
};

