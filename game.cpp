#include <ncurses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "enviorment.cpp"

class Game
{
public:
  Enviorment* envio;

  Game(int x, int y, int w, int h)
  {
    envio = new Enviorment(x, y, w, h);
  }

  void play()
  {
      envio->run();
  }

};

int main() {


  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  //w.ws_col, w.ws_row

  Game* test = new Game(2, 1, 60, 30);

  initscr();
  clear();

  noecho();
  cbreak();
  curs_set (0);
  nodelay(stdscr, TRUE);
  //keypad(stdscr, true);
  //getmaxyx(stdscr, test->height, test->width);

  test->play();
  // Clear ncurses data structures
  endwin();
 }
