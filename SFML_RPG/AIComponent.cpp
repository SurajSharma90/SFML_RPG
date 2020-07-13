#include "stdafx.h"
#include "AIComponent.h"

AIComponent::AIComponent(Entity& self, Entity& entity)
	: self(self), entity(entity)
{
}

AIComponent::~AIComponent()
{
}

void AIComponent::update(const float& dt)
{
}
