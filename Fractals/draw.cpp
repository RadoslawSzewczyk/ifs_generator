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


void draw(std::vector<point>& vecwyn, std::string& outputFile, int N)
{

	double maxX = std::numeric_limits<double>::min();
	double minX = std::numeric_limits<double>::max();

	double maxY = std::numeric_limits<double>::min();
	double minY = std::numeric_limits<double>::max();

	for (int i = 0; i < N; i++)
	{
		if (vecwyn[i].x > maxX)
			maxX = vecwyn[i].x;
		if (vecwyn[i].x < minX)
			minX = vecwyn[i].x;
		if (vecwyn[i].y > maxY)
			maxY = vecwyn[i].y;
		if (vecwyn[i].y < minY)
			minY = vecwyn[i].y;
	}

	double domain = abs(maxX - minX);
	double range = abs(maxY - minY);

	double centerX = (maxX + minX) / 2;
	double centerY = (maxY + minY) / 2;


	int windowSizeX = 1600;
	int windowSizeY = 900;

	double pointSize = 1;

	int scale = 500 / std::max(domain, range); 


	sf::RenderWindow window{ sf::VideoMode(windowSizeX, windowSizeY), outputFile };

	window.setFramerateLimit(60);

	sf::Image image;
	std::ofstream Plik(outputFile);

	sf::View view(sf::Vector2f(windowSizeX / 2 + centerX * scale, windowSizeY / 2 - centerY * scale), sf::Vector2f(windowSizeX, windowSizeY));
	while (true)
	{
		sf::Event event;
		window.clear(sf::Color::White);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
		}
		window.setView(view);
		for (int i = 0; i < N; i++)
		{
			sf::VertexArray quad(sf::Quads, 4);

			quad[0].position = sf::Vector2f(windowSizeX / 2 + vecwyn[i].x * scale, windowSizeY / 2 - vecwyn[i].y * scale);
			quad[1].position = sf::Vector2f(windowSizeX / 2 + vecwyn[i].x * scale + pointSize, windowSizeY / 2 - vecwyn[i].y * scale);
			quad[2].position = sf::Vector2f(windowSizeX / 2 + vecwyn[i].x * scale + pointSize, windowSizeY / 2 - vecwyn[i].y * scale + pointSize);
			quad[3].position = sf::Vector2f(windowSizeX / 2 + vecwyn[i].x * scale, windowSizeY / 2 - vecwyn[i].y * scale + pointSize);

			quad[0].color = sf::Color::Black;
			quad[1].color = sf::Color::Black;
			quad[2].color = sf::Color::Black;
			quad[3].color = sf::Color::Black;
			window.draw(quad);

		}
		window.display();

		sf::Texture outputTexture;
		outputTexture.create(windowSizeX, windowSizeY);
		outputTexture.update(window);

		sf::Image output;
		output.create(windowSizeX, windowSizeY);
		output = outputTexture.copyToImage();
		output.saveToFile(outputFile);

	}

	vecwyn.clear();
}

int save_to_file(sf::Image& screenshot)
{
	if (!screenshot.saveToFile("result.png"))
		return -1;
}