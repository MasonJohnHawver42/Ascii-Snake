#include "apple.cpp"
#include <iostream>

class AppleManager
{
public:
  int x_min;
  int x_max;

  int y_min;
  int y_max;

  int num_apples;
  Apple * apples;

  AppleManager(int n, int xmax, int xmin, int ymax, int ymin)
  {
    x_max = xmax;
    x_min = xmin;

    y_max = ymax;
    y_min = ymin;

    num_apples = n;
    apples = new Apple[num_apples];

    for(int i = 0; i < n; i++)
    {
      *(apples + i) = *Apple::rndApple(x_max, x_min, y_max, y_min);
    }
  }

  void update(int snake_x, int snake_y, int * applesEaten)
  {
    int n = 0;
    for(int i = 0; i < num_apples; i++)
    {
      if((apples + i)->coliding(snake_x, snake_y))
      {
        Apple * new_apple = Apple::rndApple(x_max, x_min, y_max, y_min);
        *(apples + i) = *new_apple;
        new_apple->drawApple();
        *applesEaten += 1;
      }
    }
  }

  void drawApples()
  {
    for(int i = 0; i < num_apples; i++)
    {
      (apples + i)->drawApple();
    }
  }

  std::string toString()
  {
    std::string state = "| ";

    for(int i = 0; i < num_apples; i++)
    {
      state += (apples + i)->toString() + " | ";
    }

    return state;
  }
};
