# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <random>
# include <math.h>
# include <string>
# include "header.h"


int number_of_lines(const std::string& Plik)
{
	std::string line;
	std::fstream file(Plik);
	int lineCounter = 0;

	while (getline(file, line))
	{
		lineCounter++;
	}
	return lineCounter;
	file.close();
}


int which_transformation(std::vector<formula>& vec, int howMany)
{
	std::vector<double> weights;

	for (int i = 0; i < howMany; i++)
	{
		weights.push_back(vec[i].weight);
	}
	std::random_device rd;
	std::mt19937 gen(rd());

	std::discrete_distribution< > distribution(weights.begin(), weights.end());

	return distribution(gen);
}


void transform_xy(int N, std::vector<formula>& vec, std::vector<point>& vecwyn, double x, double y, int ile)
{
	for (int i = 0; i < N; i++)
	{
		int wzor = which_transformation(vec, ile);
		double xp = x;
		double yp = y;



		x = vec[wzor].xx * xp + vec[wzor].xy * yp + vec[wzor].xw;
		y = vec[wzor].yx * xp + vec[wzor].yy * yp + vec[wzor].yw;

		vecwyn[i].x = x;
		vecwyn[i].y = y;
	}
	vec.clear();
}