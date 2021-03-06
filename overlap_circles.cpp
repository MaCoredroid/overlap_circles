// overlap_circles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//first step: build a box to hold the circles
//second step: count whether points are in the circles according to precision
//third step:count how musch propotion of area the circles compare to the rectangle

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include<iomanip>

class circle
{
public:
	circle(double x=0,double y=0,double r=0)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
	double x;
	double y;
	double r;
};

void square(double& left ,double& right ,double& up ,double& down , std::vector<circle> circles)
{
	for (int i = 0; i < circles.size(); i++)
	{
		if (left > circles[i].x - circles[i].r)
		{
			left = circles[i].x - circles[i].r;
		}
		if (right < circles[i].x + circles[i].r)
		{
			right = circles[i].x + circles[i].r;
		}
		if (up < circles[i].y + circles[i].r)
		{
			up = circles[i].y + circles[i].r;
		}
		if (down > circles[i].y - circles[i].r)
		{
			down = circles[i].y - circles[i].r;
		}
	}
}

bool is_in_the_circle(double& i,double& j, std::vector<circle> circles)
{
	for (int p = 0; p < circles.size(); p++)
	{
		if (pow((i - circles[p].x),2)+pow((j - circles[p].y),2) < circles[p].r*circles[p].r)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	std::vector<circle> circles;
	std::ifstream input("circles.txt");
	if (input.is_open())
	{
		while (!input.eof())
		{
			double x=0;
			double y=0;
			double r=0;
			input >> x >> y >> r;
		//	std::cout << x << y << r << std::endl;
			circle temp(x,y,r);
			circles.push_back(temp);
		}
	}
	double left = 0;
	double right = 0;
	double up = 0;
	double down = 0;
	square(left, right, up, down, circles);
//	std::cout << left << " " << right << " " << up << " " << down;
	std::cout << "Please input precision:";
	int precision = 0;
	std::cin >> precision;
	int precise = int(precision / 2) + 1;
	double temp = std::pow(10, (-1)*precise);
	double count = 0;
	for (double i = left; i < right; i += temp )
	{
		for (double j = down; j < up; j += temp)
		{
			if (is_in_the_circle(i, j,circles))
			{
				count++;
			}
			
			
		}
	}
	std::cout << std::fixed << std::setprecision(precision) << count *temp*temp << std::endl;

	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
