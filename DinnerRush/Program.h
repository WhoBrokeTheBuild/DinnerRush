#pragma once

#ifndef PROGRAM_H
#define PROGRAM_H

#include "Types.h"
#include "IEventDispatcher.h"
#include "TrackedObject.h"

class DataManager;
class InputManager;
class UnitManager;

class TimeInfo;

struct SDL_Window;
struct SDL_Renderer;

class Program :
	public IEventDispatcher,
	public TrackedObject
{
public:

	static EventID EVT_UPDATE;
	static EventID EVT_RENDER;

	static Program* Inst(void);

	Program(void);
	~Program(void);

	virtual inline string getClassName(void) const { return "Program"; }

	void init(void);
	void term(void);

	void run(void);

	void createWindow(void);
	void destroyWindow(void);

	void update(TimeInfo& timeInfo);
	void render(void);

	double getTargetFPS() const { return m_TargetFPS; }
	void setTargetFPS(double fps);

	double getActualFPS() const { return m_CurrentFPS; }

	InputManager* getInputManager(void) const;
	UnitManager* getUnitManager(void) const;

	DataManager* getDataLoader(void) const;

	SDL_Window* getSDLWindow(void) const;
	SDL_Renderer* getSDLRenderer(void) const;

private:

	static Program	*sp_Instance;

	double			m_TargetFPS,
					m_CurrentFPS,
					m_UpdateInterval;

	DataManager		*mp_DataManager;
	InputManager    *mp_InputManager;
	UnitManager		*mp_UnitManager;

	SDL_Window		*mp_Window;
	SDL_Renderer	*mp_Renderer;

}; // Program

#endif // PROGRAM_H