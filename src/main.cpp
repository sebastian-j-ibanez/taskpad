// Started 5/2/2024
// Written by Sebastian Ibanez

#include <ncurses.h>
#include <string>

#include "../include/tasks.hpp"
#include "../include/util.hpp"

int main(int argc, char **argv) {
  // Set basic settings.
  keypad(stdscr, TRUE);
  initscr();
  noecho();
  cbreak();

  // Create columns.
  int maxx, maxy;
  getmaxyx(stdscr, maxy, maxx);
  const int maxColumnX = (maxx/3);
  const int maxColumnY = 3;
  int currX = 0;

  // Title columns.
  WINDOW *todoTitleCol = newwin(maxColumnY, maxColumnX, 0, currX);
  currX += maxColumnX;
  box(todoTitleCol, 0, 0);

  WINDOW *progressTitleCol = newwin(maxColumnY, maxColumnX, 0, currX);
  currX += maxColumnX;
  box(progressTitleCol, 0, 0);

  WINDOW *doneTitleCol = newwin(maxColumnY, maxColumnX, 0, currX);
  box(doneTitleCol, 0, 0);

  // Body columns.
  currX = 0;
  WINDOW *todoCol = newwin(maxColumnY, maxColumnX, 0, currX);
  currX += maxColumnX;
  box(todoCol, 0, 0);

  WINDOW *progressCol = newwin(maxColumnY, maxColumnX, 0, currX);
  currX += maxColumnX;
  box(progressTitleCol, 0, 0);

  refresh();

  // Set column titles.
  const std::string todoTitle = "To Do";
  const std::string progressTitle = "In Progress";
  const std::string doneTitle = "Done";
  printCenterTitle(todoTitleCol, todoTitle);
  printCenterTitle(progressTitleCol, progressTitle);
  printCenterTitle(doneTitleCol, doneTitle);

  Task task(maxColumnX, maxColumnY, 0);
  task.SetTitle("Drink mate");
  refresh();
  task.DrawWindow();

  
  for(;;) {
    getch();
  }

  endwin();
  
  return 0;
}
