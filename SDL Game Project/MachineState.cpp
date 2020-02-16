#include "MachineState.h"


MachineState::MachineState()
{
}


MachineState::~MachineState()
{
}

void MachineState::push(StateGame * state)
{
	stateGame.push_back(state);
	stateGame.back()->whenEnter();
}

void MachineState::changeState(StateGame * state)
{
	if (!stateGame.empty()) {
		if (stateGame.back()->getStateID() == state->getStateID())
			return; 

		if (stateGame.back()->whenExit())
		{
			delete stateGame.back();
			stateGame.pop_back();
		}

	}

	stateGame.push_back(state);
	stateGame.back()->whenEnter();
}

void MachineState::pop()
{
	if (!stateGame.empty()) {
		if (stateGame.back()->whenExit())
		{
			delete stateGame.back();
			stateGame.pop_back();
		}

	}
}

void MachineState::clearAll()
{
	
	for (auto gs : stateGame) {
		delete gs;
	}
	stateGame.clear();
}

void MachineState::update()
{
	if (!stateGame.empty())
		stateGame.back()->update();
}

void MachineState::render()
{
	if (!stateGame.empty())
		stateGame.back()->render();
}


