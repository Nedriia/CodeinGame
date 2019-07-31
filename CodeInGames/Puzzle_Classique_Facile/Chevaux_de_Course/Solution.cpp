#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	int N;
	std::vector<int> puissance;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; i++) {
		int Pi;
		cin >> Pi; cin.ignore();
		puissance.push_back(Pi);
	}
	std::sort(puissance.begin(), puissance.end(), std::greater<int>());
	int max = std::numeric_limits<int>::max();
	for (auto it = puissance.begin(); it != puissance.end(); ++it)
	{
		if (*it - *(it + 1) < max)
			max = *it - *(it + 1);
	}
	std::cout << max << std::endl;
}