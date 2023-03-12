#pragma once
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <random>
# include <math.h>
# include <string>


struct point
{
	double x;
	double y;
};


struct formula
{
	double weight;
	double xx;
	double xy;
	double xw;
	double yx;
	double yy;
	double yw;
};

int number_of_lines(const std::string& Plik);

void check_switches(std::string& inputFile, std::string& outputFile, int argc, std::vector<std::string>& argv, int& N);

void load_formulas(const std::string& Plik, std::vector<formula>& vec);

void transform_xy(int N, std::vector<formula>& vec, std::vector<point>& vecwyn, double x, double y, int ile);

void draw(std::vector<point>& vecwyn, std::string& outputFile, int N);

int save_to_file(sf::Image& screenshot);