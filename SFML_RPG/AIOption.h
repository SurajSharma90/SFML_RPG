#pragma once
#include"Entity.h"

class AIOption
{
protected:

	Entity& self;
	Entity& entity;

public:
	AIOption(Entity& self, Entity& entity)
		: self(self), entity(entity)
	{
		
	}

	virtual void update(const float& dt) = 0;
};

