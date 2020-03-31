#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "CSGO");
    ImGui::SFML::Init(window);
    sf::Clock deltaClock;

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

    sf::Color bgColor(0, 0, 0);

    while (window.isOpen())
    {
        ///////////////////////////////////////
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ///////////////////////////////////////
        // Update
        // ImGui
        ImGui::Begin("Debug");
            if(music.getStatus() == sf::Music::Stopped)
                ImGui::Text("Stopped");
            else
                ImGui::Text("Playing %.2f s", music.getPlayingOffset().asSeconds());
            if(ImGui::Button("Replay"))
            {
                ct_win = false;
                music.setPlayingOffset(sf::seconds(0.f));
                music.play();
            }
        ImGui::End();
        // Game Update
        if(!ct_win && music.getPlayingOffset().asSeconds() >= 9.0f)
        {
            ct_win = true;
            se.play();
        }
        ///////////////////////////////////////
        // Draw
        window.clear(bgColor); // Clear screen

        // OpenGL draws
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-0.4, -0.4);
            glVertex2f(0.0, 0.4);
            glVertex2f(0.4, -0.4);
        glEnd();

        // SFML Draws
        window.pushGLStates();
        window.draw(sprite); // Draw the sprite
        // Draw the string
        if(ct_win)
            window.draw(text);
        window.popGLStates();

        // imgui draws
        window.pushGLStates();
            ImGui::SFML::Render(window);
        window.popGLStates();

        // Update the window
        window.display();
    }
    ImGui::SFML::Shutdown();
}