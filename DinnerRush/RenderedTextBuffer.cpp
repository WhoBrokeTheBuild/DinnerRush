#include "RenderedTextBuffer.h"

#include "Font.h"
#include "Texture.h"

RenderedTextBuffer::RenderedTextBuffer(Font* font, const string& text, const Color& color) :
	m_Text(text),
	m_Color(color),
	mp_Font(font),
	mp_Texture(nullptr)
{
	render();
}

RenderedTextBuffer::~RenderedTextBuffer(void)
{
	delete mp_Texture;
}

void RenderedTextBuffer::setText(string text)
{
	m_Text = text;
	render();
}

void RenderedTextBuffer::setColor(Color color)
{
	m_Color = color;
	render();
}

Font* RenderedTextBuffer::getFont() const
{
	return mp_Font;
}

void RenderedTextBuffer::setFont(Font* font)
{
	mp_Font = font;
	render();
}

Texture* RenderedTextBuffer::getTexture(void) const
{
	return mp_Texture;
}

void RenderedTextBuffer::render(void)
{
	delete mp_Texture;
	mp_Texture = mp_Font->renderText(m_Text, m_Color);
}
