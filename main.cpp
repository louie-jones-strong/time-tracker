#include "src/Core/Core.cpp"

#include "src/GUI/Gui.cpp"

using namespace TimeTracker;

int main()
{
    printf("Time Tracker running...\n");

    printf("\n");

    // auto core = Core::Core();
    // core.Run();

    auto gui = GUI::Gui();
    gui.Run();

    return 0;
}
