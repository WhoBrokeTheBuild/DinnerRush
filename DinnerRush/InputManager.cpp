#include "InputManager.h"
#include "Event.h"


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

}
void KeyDown::init()
{
}

void KeyDown::update()
{
}

void KeyDown::checkPrev()
{
}