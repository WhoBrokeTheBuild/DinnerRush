#include "InputManager.h"
#include "Event.h"
#include "EventSystem.h"
#include "CloseProgramEvent.h"
#include "ToggleFpsEvent.h"

#include <Windows.h>

bool KeyDown::Esc = false;
bool KeyDown::EscP = false;
bool KeyDown::Fps = false;
bool KeyDown::FpsP = false;


InputManager::InputManager()
{
	gameStarted = false;
};

InputManager::~InputManager()
{

};

void InputManager::update()
{
	KeyDown::update();

	checkKeyboard();

	KeyDown::checkPrev();
}

void InputManager::checkKeyboard()
{
	if (KeyDown::checkEscDown())
		gpEventSystem->fireEvent(CloseProgramEvent());

	if (KeyDown::checkFpsDown())
	{
		gpEventSystem->fireEvent(ToggleFpsEvent());
	}



}
void KeyDown::init()
{
	Esc = EscP = false;
	Fps = FpsP = false;
}

void KeyDown::update()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		Esc = true;
	else
		Esc = false;

	if (GetAsyncKeyState(VK_NUMPAD0))
		Fps = true;
	else
		Fps = false;

}

void KeyDown::checkPrev()
{
	EscP = Esc;
	FpsP = Fps;
}