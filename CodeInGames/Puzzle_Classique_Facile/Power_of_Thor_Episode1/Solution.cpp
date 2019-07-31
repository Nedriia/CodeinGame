#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
	int lightX; // the X position of the light of power
	int lightY; // the Y position of the light of power
	int initialTX; // Thor's starting X position
	int initialTY; // Thor's starting Y position
	cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
	int coordX = initialTX, coordY = initialTY;

	// game loop
	while (1) {
		int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
		cin >> remainingTurns; cin.ignore();

		if (lightX > coordX && lightY == coordY)
		{
			cout << "E" << endl;
			coordX++;
		}
		else if (lightX < coordX && lightY == coordY)
		{
			cout << "W" << endl;
			coordX--;
		}
		else if (lightX == coordX && lightY > coordY)
		{
			cout << "S" << endl;
			coordY++;
		}
		else if (lightX == coordX && lightY < coordY)
		{
			cout << "N" << endl;
			coordY--;
		}
		else if (lightX > coordX && lightY > coordY)
		{
			cout << "SE" << endl;
			coordY++;
			coordX++;
		}
		else if (lightX < coordX && lightY > coordY)
		{
			cout << "SW" << endl;
			coordY++;
			coordX--;
		}
		else if (lightX > coordX && lightY < coordY)
		{
			cout << "NE" << endl;
			coordY--;
			coordX++;
		}
		else
		{
			cout << "NW" << endl;
			coordY--;
			coordX--;
		}
		// A single line providing the move to be made: N NE E SE S SW W or NW
	}
}