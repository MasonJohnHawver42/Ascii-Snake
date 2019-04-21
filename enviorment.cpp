#include <ncurses.h>
#include <unistd.h>
#include "snake.cpp"
#include "appleManager.cpp"

class Enviorment
{
public:

  Snake* snake;
  AppleManager* appleMnger;


  int x;
  int y;

  int width;
  int height;

  Enviorment(int x1, int y1, int w, int h)
  {
    x = x1;
    y = y1;

    width = w;
    height = h;

    int n = 5;
    snake = new Snake(n + 2 + x, 1 + y, 0, 0);
    for(int i = 0; i < n; i++) { snake->addNode(); }

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

  void putScore(int score)
  {

    std::string line ("Score: " + std::to_string(score));

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

  void drawSnake()
  {
    Node* curr = snake->head;

    for(int i = 0; i < snake->length; i++)
    {
      mvaddch(curr->y, curr->x, '#');
      curr = curr->child;
    }
  }

  void drawApples()
  {
    for(int i = 0; i < appleMnger->num_apples; i++)
    {
      mvaddch((appleMnger->apples + i)->y, (appleMnger->apples + i)->x, '$');
    }
  }

  void tick(char key)
  {
    switch (key) {
      case 'w':
      snake->move(0, -1);
      break;

      case 's':
      snake->move(0, 1);
      break;

      case 'a':
      snake->move(-2, 0);
      break;

      case 'd':
      snake->move(2, 0);
      break;
    }

    snake->updateAll(width - 1 + x, 1 + x, height - 1 + y, 1 + y);
    int n = appleMnger->updateApples(snake->head->x, snake->head->y);

    for(int i = 0;  i < n; i++) { snake->addNode(); }
  }

  void run()
  {
    refresh();
    drawSnake();
    drawBorder();

    while (!snake->dead)
    {
      refresh();
      mvaddch(snake->tail->y, snake->tail->x, ' ');

      char key = getch();
      tick(key);

      mvaddch(snake->head->child->y, snake->head->child->x, '#');
      mvaddch(snake->head->y, snake->head->x, '@');

      drawApples();

      putScore(snake->getScore());

      usleep(100000);
    }

    mvaddch(snake->head->y, snake->head->x, 'X');
  }


};
