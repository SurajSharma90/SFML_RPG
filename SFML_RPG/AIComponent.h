#pragma once

#include "Entity.h"

#include "AIFollow.h"

class AIComponent
{
private:
	Entity& entity;
	Entity& self;

public:
	AIComponent(Entity& self, Entity& entity);
	~AIComponent();

	void update(const float& dt);
};

