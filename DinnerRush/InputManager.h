#pragma once

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

class InputManager 
{
public:
	InputManager();
	~InputManager();

	void update();
	void checkKeyboard();

private:
	bool gameStarted;

};