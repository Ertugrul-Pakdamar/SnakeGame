#include<iostream>
#include<SFML/Graphics.hpp>
#include<cstdlib>
using namespace std;

sf::Vector2f elmaPos(0, 0);
int score = -1;

void random()
{
	int elmaPosIntX = rand() % 5;
	elmaPos.x = elmaPosIntX * 100;

	int elmaPosIntY = rand() % 5;
	elmaPos.y = elmaPosIntY * 100;
}

int main()
{
	sf::RenderWindow pencere(sf::VideoMode(500, 500), "Tilan Oyunu  Score: 0");

	sf::RectangleShape kare(sf::Vector2f(50, 50));
	sf::Vector2f konum(0, 0);
	kare.setFillColor(sf::Color::White);
	kare.setPosition(sf::Vector2f(konum));

	sf::RectangleShape elma(sf::Vector2f(50, 50));
	elma.setFillColor(sf::Color::Red);
	elma.setPosition(elmaPos);

	bool elmaOlus = true;
	bool kaybettin = false;

	while (true)
	{
		int yon = 0;

		while (pencere.isOpen())
		{

			sf::Event olay;
			while (pencere.pollEvent(olay))
			{
				if (olay.type == sf::Event::Closed)
				{
					pencere.close();
				}
				if (olay.type == sf::Event::KeyPressed)
				{
					if (olay.key.code == sf::Keyboard::D)
					{
						yon = 1;
					}
					if (olay.key.code == sf::Keyboard::A)
					{
						yon = 2;
					}
					if (olay.key.code == sf::Keyboard::S)
					{
						yon = 3;
					}
					if (olay.key.code == sf::Keyboard::W)
					{
						yon = 4;
					}
				}

			}

			if (konum.x == elmaPos.x && konum.y == elmaPos.y)
			{
				random();
				score++;
			}

			if (konum.x > 500 || konum.x < 0 || konum.y > 500 || konum.y < 0)
			{
				cout << "---Game Over!---" << endl << "High Score: " << score << endl;
				string gameovertitle = "Game Over!  High Score: " + to_string(score);
				
				kaybettin = true;

				sf::RenderWindow kaybetmeP(sf::VideoMode(500, 0), gameovertitle);
				
				while (kaybettin)
				{
					sf::Event olay2;
					while (kaybetmeP.pollEvent(olay2))
					{
						if (olay2.type == sf::Event::Closed)
						{
							kaybetmeP.close();
							pencere.close();
						}
					}

					kaybetmeP.display();
				}
			}

			pencere.clear();

			switch (yon)
			{
			case 0:
				konum.x += 50;
				break;
			case 1:
				konum.x += 50;
				break;
			case 2:
				konum.x -= 50;
				break;
			case 3:
				konum.y += 50;
				break;
			case 4:
				konum.y -= 50;
				break;
			}

			kare.setPosition(konum);
			elma.setPosition(elmaPos);

			string title = "Yilan Oyunu  Score: " + to_string(score);
			
			pencere.setTitle(title);
			pencere.draw(kare);
			
			if (elmaOlus == true)
			{
				pencere.draw(elma);
			}

			sf::sleep(sf::seconds(0.5));

			pencere.display();
		}
	}
}