#pragma once

#ifndef RENDERED_TEXT_BUFFER_H
#define RENDERED_TEXT_BUFFER_H

#include "Types.h"

class Font;
class Texture;

class RenderedTextBuffer 
{
public:

	RenderedTextBuffer(Font* font, const string& text, const Color& color);
	~RenderedTextBuffer(void);

	string getText() const { return m_Text; }
	void setText(string val);

	Color getColor() const { return m_Color; }
	void setColor(Color val);

	Font* getFont(void) const;
	void setFont(Font* val);

	Texture* getTexture(void) const;

private:

	void render(void);

	string		m_Text;
	Color		m_Color;
	Font		*mp_Font;
	Texture		*mp_Texture;

}; // class RenderedTextBuffer

#endif // RENDERED_TEXT_BUFFER_H