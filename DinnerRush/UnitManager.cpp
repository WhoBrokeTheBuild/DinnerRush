#include "UnitManager.h"
#include "Unit.h"

UnitManager::UnitManager(void)
{
#define MAGIC_FUCKING_NUMBER 100
#define AREYOUHAPPYNOWLAWSON MAGIC_FUCKING_NUMBER
	m_Units.resize(AREYOUHAPPYNOWLAWSON);
}

UnitManager::~UnitManager(void)
{
	for (Unit* pUnit : m_Units)
	{
		delete pUnit;
		pUnit = nullptr;
	}
	m_Units.clear();
}

bool UnitManager::addUnit(Unit* pUnit)
{
	if (m_Units.contains(pUnit)) 
	{
		return false;
	}

	m_Units.add(pUnit);
	return true;
}

bool UnitManager::removeUnit(Unit* pUnit)
{
	if (!m_Units.contains(pUnit))
	{
		return false;
	}

	m_Units.remove(pUnit);

	for (auto it = m_Tags.begin(); it != m_Tags.end(); ++it) 
	{
		it->second.remove(pUnit);
	}

	return true;
}

bool UnitManager::addTag(string tag, Unit* pUnit)
{
	if (!m_Tags.containsKey(tag)) {
		m_Tags.add(tag, ArrayList<Unit*>());
	}

	ArrayList<Unit*>& unitList = m_Tags[tag];
	if (!unitList.contains(pUnit)) {
		m_Tags[tag].add(pUnit);
		return true;
	}

	return false;
}

bool UnitManager::removeTag(string tag, Unit* pUnit)
{
	if (!m_Tags.containsKey(tag)) {
		return false;
	}

	ArrayList<Unit*>& unitList = m_Tags[tag];
	if (!unitList.contains(pUnit)) {
		return false;
	}

	m_Tags[tag].remove(pUnit);
	return true;
}

ArrayList<Unit*>& UnitManager::getTag(string tag)
{
	if (!m_Tags.containsKey(tag)) {
		return ArrayList<Unit*>();
	}
	
	return m_Tags[tag];
}
