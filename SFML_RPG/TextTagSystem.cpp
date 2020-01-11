#include "stdafx.h"
#include "TextTagSystem.h"

//Private functions
void TextTagSystem::initVariables()
{

}

void TextTagSystem::initFonts(std::string font_file)
{
	if (!this->font.loadFromFile(font_file))
		std::cout << "ERROR::TEXTTAGSYSTEM::CONSTRUCTOR::Failed to load font " << font_file << "\n";
}

void TextTagSystem::initTagTemplates()
{
	this->tagTemplates[DEFAULT_TAG] = new TextTag(this->font, "sadas", 100.f, 100.f, 0.f, -1.f, sf::Color::White, 50, 1000.f, 200.f);
}

//Constructor / Destructor
TextTagSystem::TextTagSystem(std::string font_file)
{
	this->initFonts(font_file);
	this->initVariables();
	this->initTagTemplates();
}

TextTagSystem::~TextTagSystem()
{
	//Clean up tags
	for (auto *tag : this->tags)
	{
		delete tag;
	}

	//Clean up templates
	for (auto &tag : this->tagTemplates)
	{
		delete tag.second;
	}
}

//Functions
void TextTagSystem::addTextTag(unsigned tag_type)
{
	this->tags.push_back(new TextTag(*this->tagTemplates[DEFAULT_TAG]));
}

void TextTagSystem::removeTextTag()
{

}

void TextTagSystem::update(const float & dt)
{
	for (auto&tag : this->tags)
	{
		tag->update(dt);
	}
}

void TextTagSystem::render(sf::RenderTarget & target)
{
	for (auto&tag : this->tags)
	{
		tag->render(target);
	}
}
