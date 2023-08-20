#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main() {
    // The window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Floppy", sf::Style::Default);
    
    // A green circle
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // The game loop
    while (window.isOpen()) {
        // Event polling
        sf::Event event;
        while (window.pollEvent(event)) {
            // Closes the window
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    break;
                }
            }
                
        }

        // Update game state


        // Render game
        window.clear(); // Clear old frame

        window.draw(shape);

        window.display(); // Draws what has been rendered so far
    }

    return 0;
}