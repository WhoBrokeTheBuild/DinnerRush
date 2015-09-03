#include "Unit.h"
#include "Program.h"

Unit::Unit()
{ 
}

Unit::Unit(Animation* animation)
{
	mp_Anim = animation;
}

Unit::~Unit()
{
}

void Unit::render(const Event& evt)
{
}

void Unit::update(const Event& evt)
{
}
