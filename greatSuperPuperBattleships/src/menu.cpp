
#include "../menu.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../game.h"
#include "../settings.h"
#include "../constants.h"
#include "../customText.h"

using namespace sf;

Menu::Menu() {
    // creating app window and loading fonts/images/music
    RenderWindow menu_window(sf::VideoMode(app_width, app_height), "Battleships");
    menu_window.setFramerateLimit(app_fps);

    Font font;
    font.loadFromFile("../src/fonts/OpenSans-SemiBoldItalic.ttf");

    CustomText play_text("PLAY", font, app_width / 2, 2 * app_height / 9);

    CustomText settings_text("SETTINGS", font, app_width / 2, 4 * app_height / 9);

    CustomText exit_text("EXIT", font, app_width / 2, 2 * app_height / 3);

    Music menu_background_music;
    menu_background_music.openFromFile("../src/music/menu_music.ogg");
    menu_background_music.setLoop(true);
    menu_background_music.play();


    // menu event loop
    Event event;

    while (menu_window.isOpen()) {
        while (menu_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                menu_window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Enter) {
                    menu_window.close();
                    if (menu_state == PLAY) {
                        Game game;
                    }
                    if (menu_state == SETTINGS) {
                        Settings settings;
                    }
                }
                if (event.key.code == Keyboard::Up) {
                    if (menu_state == PLAY)
                        menu_state = EXIT;
                    else if (menu_state == SETTINGS)
                        menu_state = PLAY;
                    else if (menu_state == EXIT)
                        menu_state = SETTINGS;
                }
                if (event.key.code == Keyboard::Down) {
                    if (menu_state == PLAY)
                        menu_state = SETTINGS;
                    else if (menu_state == SETTINGS)
                        menu_state = EXIT;
                    else if (menu_state == EXIT)
                        menu_state = PLAY;
                }
            }
        }
        if (menu_state == PLAY) {
            settings_text.setColor(Color::White);
            exit_text.setColor(Color::White);
            play_text.setColor(Color::Red);
        }
        if (menu_state == SETTINGS) {
            settings_text.setColor(Color::Red);
            exit_text.setColor(Color::White);
            play_text.setColor(Color::White);
        }
        if (menu_state == EXIT) {
            settings_text.setColor(Color::White);
            exit_text.setColor(Color::Red);
            play_text.setColor(Color::White);
        }
        menu_window.clear(Color::Blue);
        play_text.draw(menu_window);
        settings_text.draw(menu_window);
        exit_text.draw(menu_window);
        menu_window.display();
    }
}