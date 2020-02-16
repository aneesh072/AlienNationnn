#pragma once
#include "StateGame.h"
#include <vector>

class MachineState
{
public:

	std::vector <StateGame*>  stateGame;
	MachineState();
	~MachineState();

	//state management
	void push(StateGame* state);
	void changeState(StateGame* state);
	void pop();
	void clearAll();

	void update();
	void render();




};

