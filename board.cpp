#include "board.h"

Board::Board()
{
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      sudoku[i][j]=0;
    }
  }
}

void Board::read_in()
{
  int value;
  int divisor;
  for (int i=0; i<=9; i++){
    cin >> value;
    divisor = 100000000;
    for (int j=0; j<=9; j++){
      if (value < 100000000 && j == 0){ // fixes error caused by computer
	sudoku[i][j] = 0;               // throwing out leading 0's
	divisor = divisor/10;
      }else if (j == 9){
	sudoku[i][j] = value;
      }else{
	sudoku[i][j] = value/divisor;
	value = value%divisor;
	divisor = divisor/10;
      }
    }
  }
}

void Board::print()
{
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      cout << sudoku[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
void Board::set_value(int x, int y, int value)
{
  sudoku[x][y]=value;
}

int Board::get_value(int x, int y)
{
  return sudoku[x][y];
}

bool Board::search_horizontal(int y, int value)
{
  for (int i=0; i<9; i++){
    if(sudoku[i][y]==value){
      return true;
    }
  }
  return false;
}

bool Board::search_vertical(int x, int value)
{
  for (int i=0; i<9; i++){
    if (sudoku[x][i]==value){
      return true;
    }
  }
  return false;
}

bool Board::search_square(int x, int y, int value)
{
  if (x<3 && y<3){
    return search(0,3,0,3,value);
  }else if (x<3 && y<6){
    return search(0,3,3,6,value);
  }else if (x<3 && y<9){
    return search(0,3,6,9,value);
  }else if (x<6 && y<3){
    return search(3,6,0,3,value);
  }else if (x<6 && y<6){
    return search(3,6,3,6,value);
  }else if (x<6 && y<9){
    return search(3,6,6,9,value);
  }else if (x<9 && y<3){
    return search(6,9,0,3,value);
  }else if (x<9 && y<6){
    return search(6,9,3,6,value);
  }else if (x<9 && y<9){
   return search(6,9,6,9,value);
  }else{
    cout << "Error, Invalad Numbers" << endl;
    exit(1);
  }
}

bool Board::search(int xmin, int xmax, int ymin, int ymax, int value)
{
  for (int i=xmin; i<xmax; i++){
    for (int j=ymin; j<ymax; j++){
      if (sudoku[i][j]==value){
	return true;
      }
    }
  }
  return false;
}

bool Board::finished()
{
  for (int i=0; i<9; i++){
    for (int j=0; i<9; j++){
      if(sudoku[i][j] == 0){
	return false;
      }
    }
  }
  return true;
}
