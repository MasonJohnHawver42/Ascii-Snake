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

  int updateApples(int snake_x, int snake_y)
  {
    int n = 0;
    for(int i = 0; i < num_apples; i++)
    {
      if(abs((apples + i)->x - snake_x) == 0 & (apples + i)->y - snake_y == 0)
      {
        *(apples + i) = *Apple::rndApple(x_max, x_min, y_max, y_min);
        n++;
      }
    }
    return n;
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
