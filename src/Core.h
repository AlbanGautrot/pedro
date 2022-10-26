#ifndef TEMPLATE_CORE_H
#define TEMPLATE_CORE_H

#include "Libraries.h"

class Core {

private:

    sf::RenderWindow window;

    sf::Event event{};

    sf::Clock m_deltaClock;

public:

    Core();

    ~Core();

    int init();

    void loop();

    void handleEvents();

    void display();

    void imgui();
};


#endif
