#include "node.cpp"


class Snake
{
public:
  Node* head;
  Node* tail;

  int length = 1;

  bool dead = false;

  Snake(int x, int y, int x_dir, int y_dir)
  {
    Node* Nodehead = new Node(x, y, x_dir, y_dir);
    head = Nodehead;
    tail = Nodehead;
  }

  void addNode()
  {
    Node* new_node = new Node(tail);
    tail->addChild(new_node);
    tail = new_node;

    length++;
  }

  void updateAll(int x_lim, int x_min, int y_lim, int y_min)
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

  int getScore()
  {
    return (length - 1) * 10;
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
