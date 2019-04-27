#include <ncurses.h>
#include <unistd.h>
#include "snake.cpp"
#include "appleManager.cpp"

class GameManager
{
public:

  Snake* snake;
  AppleManager* appleMnger;

  int x;
  int y;

  int width;
  int height;

  GameManager(int x1, int y1, int w, int h)
  {
    x = x1;
    y = y1;

    width = w;
    height = h;

    int n = 5;
    snake = new Snake(n, (n * 2) + 1 + x, 1 + y, 2, 0);

    int apple_num = 5;
    appleMnger = new AppleManager(apple_num, width + x + 1, x + 1, height + y, y + 1);
  }

  void drawBorder()
  {
    for(int i = 0; i <= width; i++)
    {
      mvaddch(y, i + x, '-');
      mvaddch(height + y, i + x, '-');
    }

    for(int i = 0; i <= height; i++)
    {
      mvaddch(i + y, x, '|');
      mvaddch(i + y, width + x, '|');
    }

    mvaddch(y, x, '+');
    mvaddch(y, width + x, '+');
    mvaddch(height + y, x, '+');
    mvaddch(height + y, width + x, '+');

  }

  void putScore()
  {

    std::string line ("Score: " + std::to_string(snake->getScore()));

    int n = max(1, (int)line.length() / (width - 2));

    for (int i = 0; i < n; i++)
    {
      mvaddch(height + i + 1 + y, x, '|');
      mvaddch(height + i + 1 + y, width + x, '|');
    }

    for(int i = 0; i <= width; i++)
    {
      mvaddch(height + n + 1 + y, i + x, '-');
    }

    mvaddch(height + n + 1 + y, x, '+');
    mvaddch(height + n + 1 + y, width + x, '+');


    for(int i = 0; i<n; i++)
    {
      move(height + 1 + i + y, x + 1);
      printw((line.substr(i * (width - 1), width - 1)).c_str());
    }
  }

  void update()
  {
    snake->update(width + x - 1, x + 1, height + y - 1, y + 1);

    int applesEaten = 0;
    appleMnger->update(snake->head->x, snake->head->y, &applesEaten);

    snake->updateLen(applesEaten);

    putScore();
  }

  void init()
  {
    drawBorder();
    putScore();

    snake->drawSnake();
    appleMnger->drawApples();
  }

  void run()
  {
    refresh();
    init();

    while (!snake->dead)
    {
      update();

      refresh();
      usleep(100000);
    }

    usleep(1000000);
  }

};
