#pragma once

#ifndef UNIT_H
#define UNIT_H

class Unit
{
public:

	Unit();

	~Unit();

	int getX() const { return m_X; }
	void setX(int val) { m_X = val; }

	int getY() const { return m_Y; }
	void setY(int val) { m_Y = val; }

private:

	int		m_X,
			m_Y;

}; // Unit

#endif // UNIT_H