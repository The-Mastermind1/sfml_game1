#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
class Player1 {
private:
	std::string playername{ "player1" };
	sf::RectangleShape rec;
public:
	Player1() {
		
		
	}
	Player1(const sf::Color& color) :rec{ sf::Vector2f{50.f,150.f} } {
		
		rec.setFillColor(color);

		

		rec.setOutlineThickness(5.f);

		rec.setOutlineColor(sf::Color::Black);

		rec.setPosition(sf::Vector2f{5.f,6.f});


	}
	void draw(sf::RenderWindow &window) {
		window.draw(rec);
	}
	sf::FloatRect get() {
		return rec.getGlobalBounds();
	}
	void modifyPosition(const sf::Keyboard::Key &e, sf::RenderWindow& window) {

		if (rec.getPosition().y > 0) {
			if (e == sf::Keyboard::W) {
				rec.setPosition(rec.getPosition().x, rec.getPosition().y - 10.5f);
			}
		}
		if (rec.getPosition().y + rec.getSize().y < window.getSize().y) {
			if (e == sf::Keyboard::S) {
				rec.setPosition(rec.getPosition().x, rec.getPosition().y + 10.5f);
			}
		}
	}
};
class Player2 {
private:
	sf::RectangleShape rec;
	std::string playername{"player2"};
public:
	Player2() {
		

	}
	Player2(const sf::Color& color) :rec{ sf::Vector2f{50.f,150.f} } {
		
		rec.setFillColor(color);
		
		rec.setOutlineThickness(5.f);

		rec.setOutlineColor(sf::Color::Black);
		
		rec.setPosition(sf::Vector2f{ 945.f,6.f });
	}
	void draw(sf::RenderWindow& window) {
		window.draw(rec);
	}
	sf::FloatRect get() {
		return rec.getGlobalBounds();
	}
	void modifyPosition(const sf::Keyboard::Key& e,sf::RenderWindow &window) {
		if (rec.getPosition().y > 0) {
			if (e == sf::Keyboard::Up) {
				rec.setPosition(rec.getPosition().x, rec.getPosition().y - 10.5f);
			}
		}
		if (rec.getPosition().y + rec.getSize().y < window.getSize().y) {
			if (e == sf::Keyboard::Down) {
				rec.setPosition(rec.getPosition().x, rec.getPosition().y + 10.5f);

			}
		}
	}
};
class Ball {
	sf::CircleShape ball;
	int task;
public:
	int kati3;
	Ball() :kati3{}, ball{} {
		

	}
	Ball(const sf::Color& color) :ball{ 10.5f }, kati3{} {
		ball.setFillColor(color);

		ball.setPosition(sf::Vector2{ 450.f,250.f });

		ball.setOutlineThickness(5.f);

		ball.setOutlineColor(sf::Color::Black);

		

	}
	void draw(sf::RenderWindow &window) {
		window.draw(ball);
	}
	void modifyPosition(sf::RenderWindow &window,int kati,int kati2) {
		if (ball.getPosition().x <= 0) {
			
			abort();
		}
		else if (ball.getPosition().x >= window.getSize().x) {
			
			abort();
		}


		if (ball.getPosition().y - ball.getRadius() > 0 && ball.getPosition().y + ball.getRadius() < window.getSize().y&&kati3==0  ) {
			
			
			if (kati == 1) {

				//colision with p1
				
				if (kati2 == 1) {
					ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y - 5.5f);
				}
				else if (kati2 == 2) {
					ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y);
				}
				else if (kati2 == 3) {
					ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y + 5.5f);
					
				}

			}
			else if (kati == 2) {
				//colision with p2
				
				if (kati2 == 1) {
					ball.setPosition(ball.getPosition().x - 5.5f, ball.getPosition().y -5.5f);
				}
				else if (kati2 == 2) {
					ball.setPosition(ball.getPosition().x - 5.5f, ball.getPosition().y);
				}
				else if(kati2==3) {
					ball.setPosition(ball.getPosition().x - 5.5f, ball.getPosition().y + 5.5f);
				}


			}
		}
		else {
			kati3 = 4;
			if (kati == 1) {
				if (ball.getPosition().y - ball.getRadius() <= 0) {
					task = 1;
						
						ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y + 5.5f);
						
						
					
				}
				if (task == 1) {
					ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y + 5.5f);

				}
				
				else if (ball.getPosition().y + ball.getRadius() >= window.getSize().y) {
					task = 2;
						
						ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y - 5.5f);
						
						
					
				}
				if (task == 2) {
					ball.setPosition(ball.getPosition().x + 5.5f, ball.getPosition().y - 5.5f);
				}
			
			}
			else if (kati == 2) {
				if (ball.getPosition().y - ball.getRadius() <= 0) {
					task = 3;
						
						ball.setPosition(ball.getPosition().x - 5.5f, ball.getPosition().y + 5.5f);
						
						
					
				}
				if (task == 3) {
					ball.setPosition(ball.getPosition().x - 5.5f, ball.getPosition().y + 5.5f);
				}
				else if (ball.getPosition().y + ball.getRadius() >= window.getSize().y) {
					task = 4;
						
						ball.setPosition(ball.getPosition().x - 10.5f, ball.getPosition().y - 10.5f);
						
						
					
				}
				if (task == 4) {
					ball.setPosition(ball.getPosition().x - 5.5f, ball.getPosition().y - 5.5f);
				}
				
			}

		}

		
			
	}
	sf::FloatRect get() {
		return ball.getGlobalBounds();
	}
	
	

};




