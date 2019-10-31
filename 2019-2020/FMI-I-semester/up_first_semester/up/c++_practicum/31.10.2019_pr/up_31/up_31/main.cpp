#include<iostream>
#include<iomanip>
int main()
{
	int days, counter = 0, leap, result;
	int year, year_counter=0,leap_counter=0;

	std::cout << "Enter num:", std::cin >> days;

	for (int i = 0; i <= days; i+=365)
	{
		year_counter++;
		
		if (year_counter % 4 == 0)
		{
			if (year_counter % 100 == 0)
			{
				if (year_counter % 400 == 0)
					++i;
				++leap_counter;
			}
			else
				++i;
			++leap_counter;
		}

	}
	std::cout << "Year_counter = " << year_counter << std::endl;
			//std::cout << year << " is not a leap year.";
	leap = leap_counter * 366;
	year = days - leap;
	year = year / 365;
	result = leap_counter + year;

	//year/365 

		std::cout << "Year= " << result << std::endl;

	std::cin.get();
}