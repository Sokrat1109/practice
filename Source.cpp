#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Timer.hpp"

int main()
{
    mt::Game game(1920, 1080, "Game"); // диалоговое окно  
    game.Setup(10);

    //if (!game.Setup(3))
      //  return -1;

    game.LifeCycle();  // начинаем цикл

    return 0;
}
