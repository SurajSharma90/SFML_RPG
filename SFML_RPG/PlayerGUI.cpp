#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void PlayerGUI::initLevelBar()
{
	float width = gui::p2pX(1.6f, this->vm);
	float height = gui::p2pY(2.8f, this->vm);
	float x = gui::p2pX(1.f, this->vm);
	float y = gui::p2pY(1.9f, this->vm);

	this->levelBarBack.setSize(sf::Vector2f(width, height));
	this->levelBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->levelBarBack.setPosition(x, y);

	this->levelBarText.setFont(this->font);
	this->levelBarText.setCharacterSize(gui::calcCharSize(this->vm, 150));
	this->levelBarText.setPosition(
		this->levelBarBack.getPosition().x + gui::p2pX(0.53f, this->vm), 
		this->levelBarBack.getPosition().y + gui::p2pY(0.5f, this->vm)
	);
}

void PlayerGUI::initEXPBar()
{
	this->expBar = new gui::ProgressBar(
		1.f, 5.6f, 10.4f, 1.9f,
		sf::Color::Blue, 220,
		this->vm, &this->font);
}

void PlayerGUI::initHPBar()
{
	this->hpBar = new gui::ProgressBar(
		1.f, 8.3f, 10.4f, 2.8f,
		sf::Color::Red, 180,
		this->vm, &this->font);
}

void PlayerGUI::initPlayerTabs(sf::VideoMode &vm, sf::Font &font, Player &player)
{
	this->playerTabs = new PlayerGUITabs(vm, font, player);
}

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm)
	: vm(vm)
{
	this->player = player;

	this->initFont();
	this->initLevelBar();
	this->initEXPBar();
	this->initHPBar();
	this->initPlayerTabs(vm, font, *player);
}

PlayerGUI::~PlayerGUI()
{
	delete this->hpBar;
	delete this->expBar;
	delete this->playerTabs;
}

const bool PlayerGUI::getTabsOpen() const
{
	return this->playerTabs->tabsOpen();
}

void PlayerGUI::toggleCharacterTab()
{
	this->playerTabs->toggleTab(PLAYER_TABS::CHARACTER_TAB);
}

//Functions
void PlayerGUI::updateLevelBar()
{
	this->levelBarString = std::to_string(this->player->getAttributeComponent()->level);
	this->levelBarText.setString(this->levelBarString);
}

void PlayerGUI::updateEXPBar()
{
	this->expBar->update(this->player->getAttributeComponent()->exp, this->player->getAttributeComponent()->expNext);
}

void PlayerGUI::updateHPBar()
{
	this->hpBar->update(this->player->getAttributeComponent()->hp, this->player->getAttributeComponent()->hpMax);
}

void PlayerGUI::updatePlayerTabs()
{
	this->playerTabs->update();
}

void PlayerGUI::update(const float & dt)
{
	this->updateLevelBar();
	this->updateEXPBar();
	this->updateHPBar();
	this->updatePlayerTabs();
}


void PlayerGUI::renderLevelBar(sf::RenderTarget & target)
{
	target.draw(this->levelBarBack);
	target.draw(this->levelBarText);
}

void PlayerGUI::renderEXPBar(sf::RenderTarget & target)
{
	this->expBar->render(target);
}

void PlayerGUI::renderHPBar(sf::RenderTarget & target)
{
	this->hpBar->render(target);
}

void PlayerGUI::renderPlayerTabs(sf::RenderTarget& target)
{
	this->playerTabs->render(target);
}

void PlayerGUI::render(sf::RenderTarget & target)
{
	this->renderLevelBar(target);
	this->renderEXPBar(target);
	this->renderHPBar(target);
	this->renderPlayerTabs(target);
}
