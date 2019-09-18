#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int actualFloor = 0;
	int blocker = 0;
	int nbFloors; // number of floors
	int width; // width of the area
	int nbRounds; // maximum number of rounds
	int exitFloor; // floor on which the exit is found
	int exitPos; // position of the exit on its floor
	int nbTotalClones; // number of generated clones
	int nbAdditionalElevators; // ignore (always zero)
	int nbElevators; // number of elevators
	int positionWanted = 0;
	map<int, int> elev;
	int elevatorPos;
	cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
	for (int i = 0; i < nbElevators; i++) {
		int elevatorFloor; // floor on which this elevator is found
		 // position of the elevator on its floor
		cin >> elevatorFloor >> elevatorPos; cin.ignore();
		elev.insert({ elevatorFloor,elevatorPos });
	}
	int timer = 0;
	// game loop
	while (1) {
		auto search = elev.find(actualFloor);
		if (search != elev.end())
			positionWanted = search->second;

		int cloneFloor; // floor of the leading clone
		int clonePos; // position of the leading clone on its floor
		string direction; // direction of the leading clone: LEFT or RIGHT
		cin >> cloneFloor >> clonePos >> direction; cin.ignore();
		if (cloneFloor == exitFloor)
		{
			if (clonePos <= exitPos)
			{
				if (direction == "LEFT" && timer > 1 && blocker == 0)
				{
					std::cout << "BLOCK" << std::endl;
					timer = 0;
					blocker++;
				}
				else
					std::cout << "WAIT" << std::endl;
			}
			else
			{
				if (direction == "RIGHT" && timer > 1 && blocker == 0)
				{
					std::cout << "BLOCK" << std::endl;
					timer = 0;
					blocker++;
				}
				else
					std::cout << "WAIT" << std::endl;
			}
		}
		else
		{
			if (clonePos <= positionWanted)
			{
				if (direction == "LEFT"&& timer > 1 && blocker == 0 && clonePos != positionWanted)
				{
					std::cout << "BLOCK" << std::endl;
					timer = 0;
					blocker++;
				}
				else
					std::cout << "WAIT" << std::endl;
			}
			else if (clonePos >= positionWanted)
			{
				if (direction == "RIGHT"&& timer > 1 && blocker == 0 && clonePos != positionWanted)
				{
					std::cout << "BLOCK" << std::endl;
					std::cerr << "here" << std::endl;
					timer = 0;
					blocker++;
				}
				else
					std::cout << "WAIT" << std::endl;
			}
			if (clonePos == positionWanted)
			{
				if (actualFloor + 2 < nbFloors)
					actualFloor++;
				blocker = 0;
				timer = 0;
			}
		}
		timer++;
	}
}