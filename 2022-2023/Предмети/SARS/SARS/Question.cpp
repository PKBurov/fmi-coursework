#include "Question.h"
#include <iostream>

Question& Question::addOption(const std::string text, const int points)
{
	options.emplace_back(Option(text, points));
	++optionCount;
	if (points > 0)
	{
		result += points;
	}
	return *this;
}

const Option& Question::operator[](const unsigned int index) const
{
	return options[index];
}
void Question::printAllCorrect() const
{
    std::cout<<"Right answers: ";
    for (unsigned int i = 0; i < optionCount; ++i)
    {
        if(options[i].points>0)
            std::cout<< i+1 << " ";
    }
    std::cout<<std::endl;
}
void Question::print() const
{
	std::cout << text << std::endl;
	for (unsigned int i = 0; i < optionCount; ++i)
	{
		if (options[i].marked)
		{
			std::cout << "(" << i + 1 << ".) ";
		}
		else
		{
			std::cout << i + 1 << ". ";
		}
		std::cout << options[i].text << std::endl;
	}
}

Question& Question::choose(int choice)
{
	options[choice].alterStatus();
	return *this;
}

int Question::getOptionCount() const
{
	return optionCount;
}

int Question::getChoiceResult() const
{
	int result = 0;
	for (unsigned int i = 0; i < optionCount; ++i)
	{
		if (options[i].marked)
		{
			result += options[i].points;
		}
	}
	return result;
}

int Question::getMaxResult() const
{
	return result;
}
