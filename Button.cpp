#include "Button.h"

void Button::initVariables() {
}

Button::Button(float height, float width, float x, float y, sf::Color color, const std::string& text) : buttonHeight(height), buttonWidth(width), xPosition(x), yPosition(y), color(color) {
	button.setSize(sf::Vector2f(width, height));
	button.setPosition(x, y);
	button.setFillColor(color);

    font = std::make_shared<sf::Font>(); // Allocate the font
    //Load and check the availability of the font file
    if (!font->loadFromFile("C:/Programming Projects/C++/Floppy/ARIAL.TTF")) {
        std::cout << "can't load font" << std::endl;
    }

    buttonText.setString(text); // Set the text content
    buttonText.setCharacterSize(40); // Set the character size
    buttonText.setFillColor(sf::Color::White); // Set the text color

    // Calculate the position for the text based on the button's position and size
    buttonText.setPosition(x + width / 4.f, y + height / 4.f);
    buttonText.setFont(*font);
    sf::FloatRect textBounds = buttonText.getLocalBounds();
}

Button::Button() : buttonHeight(0), buttonWidth(0), xPosition(0), yPosition(0), color(sf::Color::White) {
    button.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    button.setPosition(xPosition, yPosition);
    button.setFillColor(color);
}

Button::~Button() {
    //delete font;
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(button);
    window.draw(buttonText);
}
