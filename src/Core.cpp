#include "Core.h"

Core::Core() = default;

Core::~Core() {
    ImGui::SFML::Shutdown();
}

int Core::init() {
    window.create(sf::VideoMode(600, 600), "Core", sf::Style::Close);
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    embraceTheDarkness();
    return EXIT_SUCCESS;
}

void Core::loop() {
    while (window.isOpen()) {
        handleEvents();
        ImGui::SFML::Update(window, m_deltaClock.restart());
        imgui();
        display();
    }
}

void Core::handleEvents() {
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(window, event);

        switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) window.close();
                break;
        }
    }
}

void Core::display() {
    window.clear();
    ImGui::SFML::Render(window);
    window.display();
}

void Core::imgui() {

}