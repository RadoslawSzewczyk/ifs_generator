# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <random>
# include <math.h>
# include <string>
# include "Header.h"


int main(int argc, char* argv[])
{
	int N = 100000;

	double x = 0;
	double y = 0;

	std::string inputFile;
	std::string outputFile;

	std::vector<formula> vec;

	std::vector<std::string> argv_c(argv + 1, argv + argc);

	check_switches(inputFile, outputFile, argc, argv_c, N);

	std::vector<point> vecwyn(N);

	int numberOfLines = number_of_lines(inputFile); 

	load_formulas(inputFile, vec);

	transform_xy(N, vec, vecwyn, x, y, numberOfLines);

	draw(vecwyn,outputFile, N);
}