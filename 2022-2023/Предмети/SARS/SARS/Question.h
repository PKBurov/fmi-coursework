#pragma once
#include <string>
#include <vector>

struct Option
{
	Option(const std::string text = "", const int points = 0) :text(text), points(points) {}

	void alterStatus() { marked = !marked; }

	std::string text;
	int points;
	bool marked = false;
};

class Question
{
public:
	Question(const std::string text) :text(text) {}

	Question& addOption(const std::string text, const int points);

	const Option& operator[](const unsigned int index) const;

	void print() const;

	Question& choose(int choice);

	int getOptionCount() const;
	int getChoiceResult() const;
	int getMaxResult() const;
	void printAllCorrect() const;

private:
	std::string text;
	std::vector<Option> options;
	int result = 0;
	unsigned int optionCount = 0;
};
