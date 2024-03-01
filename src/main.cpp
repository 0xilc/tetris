#include "app/App.h"

int main() 
{
    App tetris;
    try
    {
        tetris.Init();
        tetris.Run();
    }
    catch (std::string exception)
    {
        std::cerr << exception << std::endl;
    }
    return 0;
}
