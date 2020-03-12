#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(761, 435), "CSGO");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("assets/csgo.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Counter Terrorists Win", font, 50);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("assets/bombtenseccount.ogg"))
        return EXIT_FAILURE;
    music.play();

    // Load sound to play
    sf::SoundBuffer soundBuffer;
    if(!soundBuffer.loadFromFile("assets/ctwin.wav"))
        return EXIT_FAILURE;
    sf::Sound se(soundBuffer);
    bool ct_win = false;

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

        if(!ct_win && music.getPlayingOffset().asSeconds() >= 9.0f)
        {
            ct_win = true;
            se.play();
        }

        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        if(ct_win)
            window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}