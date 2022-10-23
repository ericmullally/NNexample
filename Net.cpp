#include "Net.h"
#include <cassert>



Net::Net(std::vector<unsigned> topo) {
	for (int layer = 0; layer < topo.size(); layer++) {
		m_layers.push_back(Layer());
		unsigned numOutputs = layer == topo.size() - 1 ? 0 : topo[layer + 1];
		for (int neuron = 0; neuron <= topo[layer]; neuron++) { // Each layer has the number of neurons passed plus a weight.
			m_layers.back().push_back(Neuron(numOutputs));
		}
	}

};

void Net::feedForward(const std::vector<double> &inputVals) {
	assert(inputVals.size() == m_layers[0].size() -1);
	//assign the input value to the input neuron.
	for (unsigned i = 0; i < inputVals.size(); i++) {
		m_layers[0][i].setOutputVal(inputVals[i]);
	}
	// forward propagate 
	for (unsigned layernum = 1; layernum < m_layers.size(); layernum++) {
		Layer &prevLayer = m_layers[layernum - 1];
		for (unsigned n = 0; n < m_layers[layernum].size() -1; n++) {
			m_layers[layernum][n].feedForward(prevLayer);
		}
	}
};

void Net::backProp(const std::vector<double> &targetVals) {

};

void Net::getResults(std::vector<double> &resultVals) const{
	
	
};



