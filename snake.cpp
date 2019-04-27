#include "node.cpp"
#include <ncurses.h>

class Snake
{
public:
  Node* head;
  Node* tail;

  int length = 1;

  bool dead = false;

  Snake(int len, int x, int y, int x_dir, int y_dir)
  {
    Node* Nodehead = new Node(x, y, x_dir, y_dir);
    head = Nodehead;
    tail = Nodehead;

    for(int i = 0; i < len - 1; i++) { addNode(); }
  }

  void addNode()
  {
    Node* new_node = new Node(tail);
    tail->addChild(new_node);
    tail = new_node;

    length++;
  }

  bool selfCollistion()
  {
    Node* curr = head;

    for(int i = 0; i < length; i++)
    {

      if(curr->colliding(head) && i != 0) { return TRUE; }
      curr = curr->child;
    }

    return false;
  }

  void reverseSnake()
  {
    Node * tmp;

    Node * curr = head;
    for(int i = 0; i < length; i++)
    {
      if(i != length - 1)
      {
        curr->x_dir = curr->child->x_dir;
        curr->y_dir = curr->child->y_dir;
      }


      curr->invertDir();

      tmp = curr->parent;
      curr->parent = curr->child;
      curr->child = tmp;

      curr = curr->parent;
    }

    tmp = tail;
    tail = head;
    head = tmp;

    clearDrawing();
  }

  void updateLifeStatus()
  {
    dead = selfCollistion();
  }

  void updateNodes(int x_lim, int x_min, int y_lim, int y_min)
  {
    Node* curr = tail;

    for(int i = 0; i < length; i++)
    {
      curr->update(x_lim, x_min, y_lim, y_min);
      curr = curr->parent;
    }
  }


  void move(int x_dir, int y_dir)
  {
    if(head->x_dir * -1 != x_dir || head->y_dir * -1 != y_dir)
    {
      head->x_dir = x_dir;
      head->y_dir = y_dir;
    }
  }

  void updateIO(char key)
  {
    switch (tolower(key)) {
      case 'w':
      move(0, -1);
      break;

      case 's':
      move(0, 1);
      break;

      case 'a':
      move(-2, 0);
      break;

      case 'd':
      move(2, 0);
      break;

      case 'r':
      reverseSnake();
      break;
    }
  }


  void updateDrawing()
  {
    char headChar = '@';
    if(dead) { headChar = 'X'; }

    mvaddch(head->y, head->x, headChar);

    if(head->child){mvaddch(head->child->y, head->child->x, '#');}
  }

  void clearDrawing()
  {
    //mvaddch(head->y, head->x, '#');
    mvaddch(tail->y, tail->x, ' ');
  }

  void update(int xmax, int xmin, int ymax, int ymin)
  {
    clearDrawing();
    updateIO(getch());
    updateNodes(xmax, xmin, ymax, ymin);
    updateLifeStatus();
    updateDrawing();
  }


  void updateLen(int new_nodes)
  {
    for(int i = 0; i < new_nodes; i++) { addNode(); }
  }

  int getScore()
  {
    return (length - 1) * 10;
  }

  void drawSnake()
  {
    Node* curr = head;

    for(int i = 0; i < length; i++)
    {
      mvaddch(curr->y, curr->x, '#');
      curr = curr->child;
    }

    mvaddch(head->y, head->x, '@');
  }


  std::string toString()
  {
    std::string state = "";

    Node* curr = head;

    for(int i = 0; i < length; i++)
    {
      state += curr->toString() + " | ";
      curr = curr->child;
    }

    return state;
  }

};
