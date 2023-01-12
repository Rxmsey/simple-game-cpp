#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("player.png"))
        return EXIT_FAILURE;
    sf::Sprite player(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move the player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(5, 0);

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(player);

        // Draw the text
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
