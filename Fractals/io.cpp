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


void print_info()
{
	std::cout << "FRACTALS \n\n Project made on Silesian University of Technology \n author: Radoslaw Szewczyk\n supervisor: MS Adam Gudys" << std::endl;
}


void switch_error()
{
	std::cout << "Switch error. \nProgram should be run with following switches: \n  -i input file in .txt extension\n -o output file (avilable extensions: .bmp, .png, .tga, .jpg, .gif, .psd, .hdr oraz .pic) \n -n (optional) number of generated points\n";
	exit(0);
}


void check_switches(std::string& plikWejsciowy, std::string& plikWyjsciowy, int argc, std::vector<std::string>& argv, int& N)
{
	bool isGood = false;

	if ((argc == 5 || argc == 7) == false)
	{
		isGood = false;
	}

	for (int i = 0; i < argc - 1; i++)
	{
		std::string s(argv[i]);

		if (s == "-i")
		{
			std::string txt = ".txt";

			size_t znal = argv[i + 1].find(txt);
			if (znal != std::string::npos)
				plikWejsciowy = argv[i + 1];
			else
			{
				isGood = false;
			}
		}

		if (s == "-n")
		{
			N = stoi(argv[i + 1]);
		}

		if (s == "-o")
		{
			plikWyjsciowy = argv[i + 1];
			std::vector<std::string> extensions = { ".bmp", ".png", ".tga", ".jpg",".gif", ".psd", ".hdr", ".pic" };
			std::size_t dot = plikWyjsciowy.find_last_of(".");
			std::string extension = plikWyjsciowy.substr(dot, plikWyjsciowy.back());

			for (int i = 0; i < extensions.size(); i++)
			{
				if (extensions[i] == extension)
					isGood = true;
			}
		}
	}
	if (isGood == false)
		switch_error();

	print_info();
}


void load_formulas(const std::string& Plik, std::vector<formula>& vec)
{
	std::string line;
	std::fstream file(Plik);
	int i = 0;

	int liczniklini = number_of_lines(Plik);

	vec.resize(liczniklini);


	while (getline(file, line))
	{
		std::stringstream ss(line);
		double weight;
		double xx;
		double xy;
		double xw;
		double yx;
		double yy;
		double yw;

		while (ss >> weight >> xx >> xy >> xw >> yx >> yy >> yw)
		{
			vec[i].weight = weight;
			vec[i].xx = xx;
			vec[i].xy = xy;
			vec[i].xw = xw;

			vec[i].yx = yx;
			vec[i].yy = yy;
			vec[i].yw = yw;
		}
		i++;
	}
	file.close();
}