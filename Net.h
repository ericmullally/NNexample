#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Neuron.h"


typedef std::vector<Neuron> Layer;

class Net
{
public:
	Net(std::vector<unsigned> topo);
	void feedForward(const std::vector<double> &inputVals);
	void backProp(const std::vector<double> &targetVals);
	void getResults(std::vector<double> &resultVals) const;
private:
	std::vector<Layer> m_layers;
	
};

