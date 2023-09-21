#include <iostream>
#include <fstream>

class Timestamp {
private:
	unsigned long m_Value;

public:
	Timestamp()
	{
		m_Value = 0;
	}

	Timestamp(unsigned long Value)
	{
		m_Value = Value;
	}

	unsigned long GetValue() const
	{
		return m_Value;
	}

	void SetValue(unsigned long Value)
	{
		m_Value = Value;
	}

	Timestamp& operator +=(unsigned long Quantity)
	{
		m_Value += Quantity;
		return *this;
	}

	Timestamp operator+(unsigned long Quantity)
	{
		return Timestamp(m_Value + Quantity);
	}
};

std::ostream& operator << (std::ostream& output, Timestamp const& ts)
{
	output << ts.GetValue();
	return output;
}

std::istream& operator >> (std::istream& input, Timestamp& ts)
{
	unsigned long value;
	input >> value;
	ts.SetValue(value);
	return input;
}

class TimestampWithDescription : public Timestamp {
private:
	char* m_Description;
public:
	TimestampWithDescription()
	{
		m_Description = NULL;
	}

	TimestampWithDescription(TimestampWithDescription const & other) : Timestamp(other)
	{
		m_Description = NULL;
		SetDescription(other.GetDescription());
	}

	~TimestampWithDescription()
	{
		delete m_Description;
	}

	TimestampWithDescription& operator=(TimestampWithDescription const & other)
	{
		if (this != &other)
		{
			Timestamp::operator=(other);
			SetDescription(other.GetDescription());
		}

		return *this;
	}

	void SetDescription(const char* Text)
	{
		delete[] m_Description;
		m_Description = NULL;

		if (Text)
		{
			m_Description = new char[strlen(Text) + 1];
			strcpy(m_Description, Text);
		}
	}

	const char* GetDescription() const
	{
		return m_Description ? m_Description : "";
	}
};

std::ostream& operator << (std::ostream& output, TimestampWithDescription const& tswd)
{
	output << tswd.GetValue() << " " << tswd.GetDescription() << std::endl;
	return output;
}

std::istream& operator >> (std::istream& input, TimestampWithDescription& tswd)
{
	unsigned long value;
	input >> value;
	tswd.SetValue(value);

	char buffer[100];
	input.getline(buffer, 100);
	tswd.SetDescription(buffer);

	return input;
}


int main()
{
	std::ifstream inputFile("timestamps.txt");

	unsigned long ts;
	char buffer[100];

	while (inputFile)
	{
		inputFile >> ts;
		inputFile.getline(buffer, 100);

		if (inputFile)
		{
			TimestampWithDescription tswd;
			tswd.SetValue(ts);
			tswd.SetDescription(buffer);
			std::cout << tswd;
		}
	}

    return 0;
}


//
// Функцията main() може да се напише и по-кратко, ако човек се сети,
// че операторите за вход и изход работят както за cin/cout,
// така и за inputFile:
//
//int main()
//{
//	std::ifstream inputFile("timestamps.txt");
//
//	TimestampWithDescription tswd;
//
//	while (inputFile)
//	{
//		inputFile >> tswd;
//
//		if (inputFile)
//			std::cout << tswd;
//	}
//
//    return 0;
//}