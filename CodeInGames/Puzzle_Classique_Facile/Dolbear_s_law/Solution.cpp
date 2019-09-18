#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	int lineNumber;
	std::cin >> lineNumber; std::cin.ignore();
	std::string list[lineNumber][1];
	std::vector<int> sumList;
	int index = 0;
	float sum = 0;
	float temp = 0;


	for (int i = 0; i < lineNumber; i++)
	{
		std::string LINE;
		getline(std::cin, LINE);
		list[i][0] = LINE;
	}

	for (int i = 0; i < lineNumber; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			for (int k = 0; k < list[i][j].length(); k++)
			{
				char C = list[i][j].at(k);
				if (C != ' ')
				{
					auto it = sumList.insert(sumList.end(), (int)C - '0');
					//std::cerr << C << std::endl;
				}
			}
		}
	}

	for (auto it = sumList.begin(); it != sumList.end(); ++it)
	{
		if (index != 15)
		{
			temp += *it;
			//std::cerr << temp << std::endl;
		}
		else
		{
			sum += 10 + (temp - 40) / 7;
			//std::cerr << "____" << sum << std::endl;
			temp = 0;
			temp = *it;
			index = 0;
		}
		index++;
	}
	sum += 10 + (temp - 40) / 7;
	//std::cerr << "____" << sum << std::endl;
	sum /= lineNumber;

	std::printf("%.1f", sum); std::cout << "\n";
	//if the value is between 5 and 30 -> then return the average of estimates calculated
	//every 8 seconds
	if (sum >= 5 && sum <= 30)
	{
		sum = 0; temp = 0;
		//Check if the length of the list is odd
		if (sumList.size() % 2 != 0)
			sumList.pop_back();
		for (index = 0; index < sumList.size(); index += 2)
		{
			temp = *(sumList.begin() + index) + *(sumList.begin() + (index + 1));
			//std::cerr << temp  << "_____" << sum << std::endl;
			sum += temp + 5;
			temp = 0;
		}
		sum /= sumList.size() / 2;
		std::printf("%.1f", sum); std::cout << "\n";
	}

}