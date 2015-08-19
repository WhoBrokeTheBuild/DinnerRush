#pragma once

#ifndef UNIT_MANAGER_H
#define UNIT_MANAGER_H

#include "TrackedObject.h"
#include "ArrayList.h"
#include "Map.h"

class Unit;

class UnitManager :
	public TrackedObject
{
public:

	UnitManager(void);

	virtual ~UnitManager(void);

	virtual inline string getClassName(void) const { return "Unit Manager"; }

	bool addUnit(Unit* pUnit);
	bool removeUnit(Unit* pUnit);

	bool addTag(string tag, Unit* pUnit);
	bool removeTag(string tag, Unit* pUnit);

	ArrayList<Unit*>& getTag(string tag);

private:

	ArrayList<Unit*>				m_Units;
	Map<string, ArrayList<Unit*>>	m_Tags;

};

#endif // UNIT_MANAGER_H