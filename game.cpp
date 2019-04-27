#include <ncurses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "gameManager.cpp"

class Game
{
public:
  GameManager* gameMnger;

  Game(int x, int y, int w, int h)
  {
    gameMnger = new GameManager(x, y, w, h);
  }

  void play()
  {
    initscr();
    clear();

    noecho();
    cbreak();
    curs_set (0);
    nodelay(stdscr, TRUE);

    gameMnger->run();

    endwin();
  }

};

int main() {

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  int width = min((int)(w.ws_col * .8), 60), height = min((int)(w.ws_row * .8), 30);

  Game* test = new Game((w.ws_col / 2) - (width / 2), (w.ws_row / 2) - (height / 2), width, height);
  test->play();
 }
