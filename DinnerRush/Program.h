#pragma once

#ifndef PROGRAM_H
#define PROGRAM_H

#include "Types.h"

class TimeInfo;
class DataLoader;
class Font;
class RenderedTextBuffer;

struct SDL_Window;
struct SDL_Renderer;

class Program
{
public:

	static Program* Inst(void);

	Program(void);
	~Program(void);

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

	DataLoader* getDataLoader(void) const;

	SDL_Window* getSDLWindow(void) const;
	SDL_Renderer* getSDLRenderer(void) const;

private:

	static Program	*sp_Instance;

	double			m_TargetFPS,
					m_CurrentFPS,
					m_UpdateInterval;

	DataLoader		*mp_DataLoader;

	SDL_Window		*mp_Window;
	SDL_Renderer	*mp_Renderer;

	Font				*mp_MainFont;
	RenderedTextBuffer	*mp_TextBuffer;

}; // Program

#endif // PROGRAM_H