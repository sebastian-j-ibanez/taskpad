// Started 5/2/2024
// Written by Sebastian Ibanez

#include <ncurses.h>

int main(int argc, char** argv) {
  initscr();

  printw("Hello taskpad!");

  refresh();

  getch();

  endwin();
  return 0;
}
