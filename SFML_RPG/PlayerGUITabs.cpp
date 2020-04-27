#include "stdafx.h"
#include "PlayerGUITabs.h"

PlayerGUITabs::PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player)
	: vm(vm), font(font), player(player),
	characterTab(vm, font, player)
{

}

PlayerGUITabs::~PlayerGUITabs()
{

}

void PlayerGUITabs::update()
{
}

void PlayerGUITabs::render(sf::RenderTarget * target)
{
	this->characterTab.render(target);
}
