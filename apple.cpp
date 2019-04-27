#include <stdlib.h>
#include <ncurses.h>
#include <string>

using namespace std;

class Apple
{
public:
  int x;
  int y;

  Apple()
  {}

  Apple(int x1, int y1)
  {
    x = x1;
    y = y1;
  }

  static Apple * rndApple(int xmax, int xmin, int ymax, int ymin)
  {
    int x1 = ((rand() % ((xmax - xmin) / 2)) * 2) + xmin;
    int y1 = (rand() % (ymax - ymin)) + ymin;

    return new Apple(x1, y1);
  }

  bool coliding(int x1, int y1)
  {
    return x - x1 == 0 && y - y1 == 0;
  }

  void drawApple()
  {
    mvaddch(y, x, '$');
  }

  std::string toString()
  {
    return "Apple=[x:" + std::to_string(x) + ", y:" + std::to_string(y) + "]";
  }

};
