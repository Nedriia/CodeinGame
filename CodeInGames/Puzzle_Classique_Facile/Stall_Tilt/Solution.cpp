#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <map>
#include <set>
#include <functional>

bool Angle_Check(int speed, int radius)
{
	double angle_ = (pow(speed, 2) / (radius * 9.81)); //36.57° // 29°
	angle_ = atan(angle_);
	angle_ *= 180 / 3.14159265359;
	angle_ = 90 - angle_;
	if (angle_ > 30)
		return true;
	else
		return false;
}

int main()
{
	int n;
	std::cin >> n; std::cin.ignore();
	int v;
	std::cin >> v; std::cin.ignore();
	std::map<char, int>speed_List;
	std::vector<int> curves_List;

	for (int i = 0; i < n; i++) {
		int speed;
		std::cin >> speed; std::cin.ignore(); //speed < 60
		speed_List.insert({ static_cast<char>('a' + i),speed });
	}

	// Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef std::function<bool(std::pair<char, int>, std::pair<char, int>)> Comparator;

	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
		[](std::pair<char, int> elem1, std::pair<char, int> elem2)
	{
		return elem1.second > elem2.second;
	};

	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<char, int>, Comparator> List_Result(
		speed_List.begin(), speed_List.end(), compFunctor);

	for (int i = 0; i < v; i++) {
		int bends;
		std::cin >> bends; std::cin.ignore();
		curves_List.push_back(bends);
	}


	std::vector<int>::iterator result = std::min_element(std::begin(curves_List), std::end(curves_List));
	double optimal_Speed = ceil(sqrt(atan(30) *(*result) * 9.81));
	if (Angle_Check(optimal_Speed + 1, *result))
		optimal_Speed++;
	std::cout << optimal_Speed << std::endl; //Return the optimal speed around to the up value

	//Angle calculus
	std::vector<int> pilots_state;
	int count = 0;
	for (auto it = List_Result.begin(); it != List_Result.end(); ++it)
	{
		for (int j = 0; j < v; j++)
		{
			double angle_ = (pow(it->second, 2) / (curves_List[j] * 9.81));
			angle_ = atan(angle_);
			angle_ *= 180 / 3.14159265359;
			angle_ = 90 - angle_;
			if (angle_ > 30)
				count++;
		}
		pilots_state.push_back(count);
		count = 0;
	}

	std::vector<char> first_half;
	std::vector<char> second_half;
	std::vector<int> second_half_sucess;
	int index = 0;
	for (auto it = List_Result.begin(); it != List_Result.end(); ++it)
	{
		if (it->second < optimal_Speed)
			first_half.push_back(it->first);
		else
		{
			second_half.push_back(it->first);
			second_half_sucess.push_back(pilots_state[index]);
		}
		index++;
	}

	std::vector<char> test;
	for (int k = curves_List.size(); k >= 0; k--)
	{
		for (int i = 0; i < second_half.size(); i++)
		{
			if (second_half_sucess[i] == k)
			{
				test.push_back(second_half[i]);
			}
		}
	}
	first_half.insert(first_half.begin(), 'y');
	first_half.insert(first_half.end(), test.begin(), test.end());
	for (auto it = first_half.begin(); it != first_half.end(); ++it)
		std::cout << *it << std::endl;

}