#include "stdafx.h"
#include "PlayerGUITabs.h"

PlayerGUITabs::PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player)
	: vm(vm), font(font), player(player)
{
	this->initTabMenu();
	this->initCharacterTab();
}

PlayerGUITabs::~PlayerGUITabs()
{

}

void PlayerGUITabs::initTabMenu()
{

}

void PlayerGUITabs::initCharacterTab()
{
	//Background
	this->CharacterTabBack.setFillColor(sf::Color(50, 50, 50, 180));
	this->CharacterTabBack.setSize(sf::Vector2f(gui::p2pX(30.f, this->vm), static_cast<float>(this->vm.height)));

	//Text
	this->CharacterInfoText.setFont(this->font);
	this->CharacterInfoText.setCharacterSize(gui::calcCharSize(this->vm, 50));
	this->CharacterInfoText.setFillColor(sf::Color::White);
	this->CharacterInfoText.setPosition(this->CharacterTabBack.getPosition().x + 20.f, this->CharacterTabBack.getPosition().y + 20.f);
}
