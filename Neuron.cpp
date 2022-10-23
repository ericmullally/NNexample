#include "Neuron.h"

Neuron::Neuron(unsigned numOutputs) {
	for (unsigned c = 0; c < numOutputs; c++) {
		outPutWeights.push_back(Connection());
		outPutWeights.back().weight = randomWeight();
	}
}


