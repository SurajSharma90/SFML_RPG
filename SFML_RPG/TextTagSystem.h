#ifndef TEXTTAGSYSTEM_H
#define TEXTTAGSYSTEM_H

class TextTagSystem
{
private:
	class TextTag
	{
	public:

	};

public:
	TextTagSystem();
	virtual ~TextTagSystem();

	//Functions
	void addTextTag(TextTag* text_tag);
	void removeTextTag();

	void update(const float &dt);
	void render(sf::RenderTarget * target);
};

#endif // !TEXTTAGSYSTEM_H
