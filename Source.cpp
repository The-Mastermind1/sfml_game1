#include"Header.h"
int main() {
	
	
	sf::RenderWindow window(sf::VideoMode(1000, 800), "game-1");
    sf::Event ev{};
    window.setFramerateLimit(60);
	sf::Texture texture;
    srand(static_cast<unsigned int>(time(0)));
    Player1 player1{ sf::Color::Green };
	Player2 player2{sf::Color::Red };
    Ball ball1{ sf::Color::Cyan };
    int kati=1;
    int kati2=2;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W) {
                    player1.modifyPosition(sf::Keyboard::W,window);
                }
            }

            // Check if a key was released
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    player1.modifyPosition(sf::Keyboard::S, window);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    player2.modifyPosition(sf::Keyboard::Up, window);
                }
            }

            // Check if a key was released
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down) {
                    player2.modifyPosition(sf::Keyboard::Down, window);
                }
            }
            
        }
        if (ball1.get().intersects(player1.get())) {
            kati2 = rand() % 3 + 1;
            kati = 1;
            
            ball1.modifyPosition(window, kati,kati2);
        }
        else if (ball1.get().intersects(player2.get())) {
            kati2 = rand() % 3 + 1;
            kati = 2;
           
            ball1.modifyPosition(window, kati,kati2);
        }
        ball1.modifyPosition(window, kati,kati2);
       
        
        // Clear the window
        window.clear(sf::Color::Blue);

        // Draw the rectangle
        player1.draw(window);
        player2.draw(window);
        ball1.draw(window);
        // Display what has been drawn
        window.display();
    }
}
