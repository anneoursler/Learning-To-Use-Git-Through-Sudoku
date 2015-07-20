#include <iostream>
#include "board.h"
using namespace std;

struct Possible{
  int x, y;
  int options[9];
  int length;
};

Board find_values(Board sudoku);
// TODO: add clause of imposible problems?
// BUG: cout near print to prevent segfault.

int main(){
  Board sudoku;
  sudoku.read_in();

  cout << "Puzzle: " << endl;
  sudoku.print();
 
 while (sudoku.finished() == false){
    sudoku = find_values(sudoku);
  }

  cout << "Solution: " << endl;
  sudoku.print();
  return 0;
}

Board find_values(Board sudoku){
  for (int x=0; x<9; x++){
    for (int y=0; y<9; y++){
      if (sudoku.get_value(x,y)==0){//0 stands for a blank square  
	Possible pos;
	pos.length = 0;
	for (int num=1; num<=9; num++){ //Find all valid values
	  if (!sudoku.search_horizontal(y,num) &&
	      !sudoku.search_vertical(x,num)   &&
	      !sudoku.search_square(x,y,num)){
	    pos.options[pos.length] = num;
	    pos.length++;
	  }
	}
	if (pos.length == 1){//Fill blank if only one option remains
	  sudoku.set_value(x,y,pos.options[0]); 
	}
      }
    }
  }
  return sudoku;
}
