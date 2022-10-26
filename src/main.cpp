#include "Libraries.h"
#include "Core.h"

int main() {
    Core core;
    if (core.init() == EXIT_SUCCESS) core.loop();
    return EXIT_SUCCESS;
}
