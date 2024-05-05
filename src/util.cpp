// Created 5/5/2024
// Written by Sebastian Ibanez

#include "../include/util.hpp"

// Print a title in the top-center of a window.
void printCenterTitle(WINDOW* colWin, std::string title) {
  // Get window width and margin.
  int maxx = getmaxx(colWin);
  int margin = (maxx - title.length()) / 2;
  
  // Print title and refresh.
  mvwprintw(colWin, 1, margin, title.c_str());
  wrefresh(colWin);
  return;
}
