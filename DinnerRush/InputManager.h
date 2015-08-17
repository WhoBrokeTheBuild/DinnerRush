#pragma once

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "TrackedObject.h"

class KeyDown
{
public:
	KeyDown() {};
	~KeyDown() {};

	static void init();
	static void update();
	static void checkPrev();

	static bool checkEscDown() { return (Esc && !EscP) ? true : false; };
	static bool checkFpsDown() { return (Fps && !FpsP) ? true : false; };

private:
	//add keys here
	static bool Fps, FpsP;
	static bool Esc, EscP;
};

class InputManager :
	public TrackedObject
{
public:

	InputManager(void);
	~InputManager(void);

	virtual inline string getClassName(void) const { return "Input Manager"; }

	void update(void);
	void checkKeyboard(void);

private:
	bool gameStarted;

};

#endif // INPUT_MANAGER_H