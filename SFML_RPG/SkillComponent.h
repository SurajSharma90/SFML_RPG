#ifndef SKILLCOMPONENT_H
#define SKILLCOMPONENT_H

class SkillComponent
{
private:
	class Skill
	{
	private:
		int level;
		int levelCap;
		int exp;
		int expNext;

	public:
		Skill() 
		{
			this->level = 1;
			this->levelCap = 99;
			this->exp = 0;
			this->expNext = 100;
		}

		~Skill() {}

		//Accessors
		inline const int& getLevel() const { return this->level; }
		inline const int& getExp() const { return this->exp; }
		inline const int& getExpNext() const { return this->expNext; }

		//Modifiers
		void setLevel(const int level) { this->level = level; }
		void setLevelCap(const int level_cap) { this->levelCap = level_cap; }

		//Functions
		void gainExp(const int exp) 
		{ 
			this->exp += exp; 
			this->updateLevel(); 
		}

		void loseExp(const int exp)
		{
			this->exp -= exp;
		}

		void updateLevel(const bool up = true)
		{
			/**
			  * Increases or decreases the level of the skill depending on if there is a deficit in the exp or not. 
			  *
			  */

			if (up)
			{
				if (this->level < this->levelCap)
				{
					while (this->exp >= this->expNext)
					{
						if (this->level < this->levelCap)
						{
							this->level++;
							this->expNext = static_cast<int>(std::pow(this->level, 2)) + this->level * 10 + this->level * 2;
						}
					}
				}
			}
			else
			{
				if (this->level > 0)
				{
					while (this->exp < 0)
					{
						if (this->level > 0)
						{
							this->level--;
							this->expNext = static_cast<int>(std::pow(this->level, 2)) + this->level * 10 + this->level * 2;
						}
					}
				}
			}
		}

		void update()
		{
			
		}
	};

	std::map<std::string, Skill> skills;

public:
	SkillComponent();
	virtual ~SkillComponent();

	const int getSkill(const std::string key) const;
};

#endif //!SKILLCOMPONENT_H
