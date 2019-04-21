#include <iostream>

using namespace std;
;
class Node
{
public:
        Node* parent;
        Node* child;

        int x_dir;
        int y_dir;

        int x;
        int y;

        Node(Node* prnt)
        {
                parent = prnt;

                x_dir = prnt->x_dir;
                y_dir = prnt->y_dir;

                x = prnt->x - x_dir;
                y = prnt->y - y_dir;
        }

        Node(int x1, int y1, int xd, int yd)
        {
                x_dir = xd;
                y_dir = yd;

                x = x1;
                y = y1;
        }

        void addChild(Node* chld)
        {
                child = chld;
        }

        void update(int x_lim, int x_min, int y_lim, int y_min)
        {

                int new_x = x_dir + x;
                if (new_x < x_min) {x = x_lim;}
                else if (new_x > x_lim) {x = x_min;}
                else {x = new_x;}

                int new_y = y_dir + y;
                if (new_y < y_min) {y = y_lim;}
                else if (new_y > y_lim) {y = y_min;}
                else {y = new_y;}

                if(parent)
                {
                  x_dir = parent->x_dir;
                  y_dir = parent->y_dir;
                }
        }

        std::string toString()
        {
          return "Node[x:" + std::to_string(x) + ", y:" + std::to_string(y) + ", xd:" + std::to_string(x_dir) + ", yd:" + std::to_string(y_dir) +"]";
        }
};
