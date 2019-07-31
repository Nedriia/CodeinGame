#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	std::string LON;
	std::cin >> LON; std::cin.ignore();
	std::string LAT;
	std::cin >> LAT; std::cin.ignore();
	int N;
	std::cin >> N; std::cin.ignore();
	//We create a array N -> number of defibrilateur in the list, and 6 -> since we know each 
	//defib will have 6 infos
	std::string infos[N][6];
	int j = 0;

	for (int i = 0; i < N; i++)
	{
		std::string DEFIB;
		std::getline(std::cin, DEFIB);
		std::istringstream ss(DEFIB);
		std::string list_substr;

		while (j < 6)
		{
			std::getline(ss, list_substr, ';');
			if (list_substr.size() > 1)
				infos[i][j] = list_substr;
			j++;
		}
		j = 0;
	}
	std::replace(LON.begin(), LON.end(), ',', '.');
	std::replace(LAT.begin(), LAT.end(), ',', '.');

	double LON_B = stod(LON);
	double LAT_B = stod(LAT);
	double mini = std::numeric_limits<int>::max();

	std::string closer_Defib;

	for (int i = 0; i < N; i++)
	{
		//Longitud(4th)  latitud(5th)
		std::replace(infos[i][4].begin(), infos[i][4].end(), ',', '.');
		std::replace(infos[i][5].begin(), infos[i][5].end(), ',', '.');
		double LON_A = stod(infos[i][4]);
		double LAT_A = stod(infos[i][5]);

		double x = (LON_B - LON_A) * cos((LAT_B + LAT_A) / 2);
		double y = (LAT_B - LAT_A);
		//latitudes and longitudes are express in radians, we need to convert x and y in degrees
		x *= 3.14159265359 / 180;
		y *= 3.14159265359 / 180;

		double distance = std::sqrt(pow(x, 2) + pow(y, 2));
		if (distance < mini || distance == 0)
		{
			mini = distance;
			closer_Defib = infos[i][1];
		}
	}
	std::cout << closer_Defib;
}