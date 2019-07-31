#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int main()
{
	double velocityX = 0, velocityY = 0;
	double EvelocityX = 0, EvelocityY = 0;
	double prevX = 0, prevY = 0;
	double EprevX = 0, EprevY = 0;
	double distance = 0;
	double Edistance = 0, futurDistance = 0;
	int thrust = 100;
	int timer = 0;
	// game loop
	while (1) {
		timer++;
		int x;
		int y;
		int nextCheckpointX; // x position of the next check point
		int nextCheckpointY; // y position of the next check point

		int newCheckpointX;
		int newCheckpointY;

		int nextCheckpointDist; // distance to the next checkpoint
		int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
		std::cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; std::cin.ignore();
		int opponentX;
		int opponentY;
		std::cin >> opponentX >> opponentY; std::cin.ignore();

		double r = 0, d = 0, f = 0;
		double directionX = 0, directionY = 0;

		directionX = nextCheckpointX - x;
		directionY = nextCheckpointY - y;

		r = std::sqrt(directionX * directionX + directionY * directionY);
		directionX /= r;
		directionY /= r;
		std::cerr << "Desired velocity " << directionX * 100 << "  " << directionY * 100 << std::endl;

		velocityX = x - prevX;
		velocityY = y - prevY;
		d = std::sqrt(velocityX * velocityX + velocityY * velocityY);
		velocityX /= d;
		velocityY /= d;
		prevX = x;
		prevY = y;
		std::cerr << "Velocity " << velocityX * 100 << " " << velocityY * 100 << std::endl;
		std::cerr << "Steering " << directionX * 1000 - velocityX * 1000 << " " << directionY * 1000 - velocityY * 1000 << std::endl;
		distance = std::sqrt(std::pow(nextCheckpointX - x, 2) + std::pow(nextCheckpointY - y, 2));
		std::cerr << "Distance :" << distance << std::endl;


		if (nextCheckpointAngle <8 && nextCheckpointAngle >-8)
		{
			newCheckpointX = nextCheckpointX + ((directionX * 1000 - velocityX * 1000));
			newCheckpointY = nextCheckpointY + ((directionY * 1000 - velocityY * 1000));
		}
		else
		{
			// * 4 -> allow us to predict futur position 
			newCheckpointX = nextCheckpointX + ((directionX * 1000 - velocityX * 1000) * 4);
			newCheckpointY = nextCheckpointY + ((directionY * 1000 - velocityY * 1000) * 4);
		}

		std::cerr << nextCheckpointAngle << std::endl;
		if (nextCheckpointAngle > 80 || nextCheckpointAngle < -80)
			thrust = 40;
		else if (nextCheckpointAngle > 18 || nextCheckpointAngle < -18)
			thrust = 85;
		else if (nextCheckpointDist > 1100 && nextCheckpointDist < 2000)
			thrust = 40;
		else
			thrust = 100;


		if (distance <= 800)
			std::cout << nextCheckpointX << " " << nextCheckpointY << " " << std::to_string(thrust) << std::endl;
		else
		{
			if (distance > 6500 && timer > 10 && ((nextCheckpointAngle < 3 && nextCheckpointAngle > -3)))
			{
				//New point to seek to compensate inertia
				std::cout << newCheckpointX << " " << newCheckpointY << " " << "BOOST" << std::endl;
			}
			else if (futurDistance < Edistance && Edistance < 900)
				std::cout << newCheckpointX << " " << newCheckpointY << " " << "SHIELD" << std::endl;
			else
			{
				//New point to seek to compensate inertia
				std::cout << newCheckpointX << " " << newCheckpointY << " " << std::to_string(thrust) << std::endl;
			}
		}

	}
}