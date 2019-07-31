#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	int mini = std::numeric_limits<int>::max();
	int n; // the number of temperatures to analyse
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		int t; // a temperature expressed as an integer ranging from -273 to 5526
		cin >> t; cin.ignore();
		if (abs(t) < abs(mini))
			mini = t;
		else if (t == mini && t < 0 && mini < 0)
			mini == t;
		else if (abs(t) == abs(mini))
			mini = abs(t);
		//std::cout << mini << std::endl;
	}
	if (n == 0)
		std::cout << "0" << std::endl;
	else
		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		std::cout << mini << std::endl;
}