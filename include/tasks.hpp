// Created 5/5/2024
// Written by Sebastian Ibanez

#pragma once

#include <ncurses.h>
#include <string>
#include <ctime>

class Task {
private:
  WINDOW *win;
  int y, x;
  std::string title;
  std::string description;
  struct tm date;

public:
  Task(int columndWidth, int y, int x);
  void DrawWindow();
  void ResizeWindow(int y, int x);
  void SetTitle(std::string newTitle);
  std::string GetTitle();
  void SetDescription(std::string newDescription);
  std::string GetDescription();
  void SetDate(time_t newDate);
  struct tm GetDate();
};
