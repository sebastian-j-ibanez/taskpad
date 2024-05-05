// Started 5/5/2024
// Writen by Sebastian Ibanez

#include "../include/tasks.hpp"
#include "../include/util.hpp"

#include <ctime>
#include <ncurses.h>
#include <string>

// Parameterized constructor.
Task::Task(int columnWidth, int y, int x) {
  this->y = y;
  this->x = x;

  // Set window.
  const int defaultHeight = 5;
  this->win = newwin(defaultHeight, columnWidth, this->y, this->x);
  box(win, 0, 0);

  // Initialize title and description.
  this->title = "";
  this->description = "";
}

// Resize the task window.
void Task::ResizeWindow(int y, int x) {
  wresize(this->win, y, x);
}

// Draw and print task data to window.
void Task::DrawWindow() {
  printCenterTitle(this->win, this->title);
}

// Setters and getters for title, description, and date.
void Task::SetTitle(std::string newTitle) {
  this->title = newTitle;
}

std::string Task::GetTitle() {
  return this->title;
}

void Task::SetDescription(std::string newDescription) {
  this->description = newDescription;
}

std::string Task::GetDescription() {
  return this->description;
}

void Task::SetDate(time_t newDate) {
  this->date = *localtime(&newDate);
}

struct tm Task::GetDate() {
  return this->date;
}
