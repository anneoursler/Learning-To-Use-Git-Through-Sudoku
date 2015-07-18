#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
using namespace std;

class Board{
 public:
  Board();
  void read_in();
  void print();
  void solve(int x, int y);
  void set_value(int x, int y, int value);
  int get_value(int x, int y);
  bool search_horizontal(int y, int value);
  bool search_vertical(int x, int value);
  bool search_square(int x, int y, int value);
  bool finished();
 private:
  int sudoku[9][9];
  bool search(int xmin, int xmax, int ymin, int ymax, int value);
};

#endif
