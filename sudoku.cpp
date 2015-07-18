#include <iostream>
#include "board.h"
using namespace std;

struct Possible{
  int x, y;
  int options[9];
  int length;
};

int main(){
  Board sudoku;
  sudoku.read_in();
  sudoku.print();
  while (!sudoku.finished()){
    for (int i=0; i<9; i++){
      for (int j=0; j<9; j++){
	if (sudoku.get_value(i,j)==0){
	  Possible pos;
	  pos.length = 0;
	  for (int k=0; k<9; k++){
	    if (!sudoku.search_horizontal(j,k) &&
		!sudoku.search_vertical(i,k)   &&
		!sudoku.search_square(i,j,k)){
	      pos.options[pos.length] = k;
	      pos.length++;
	    }
	  }
	  if (pos.length == 0){
	    if (sudoku.finished()){
	      sudoku.print();
	    }else{
	      cout << "Puzzle is imposible!" << endl;
	    }
	    sudoku.print();
            
	    return 0;
	  }else if (pos.length == 1){
	    sudoku.set_value(i,j,pos.options[0]);
	  }
	}
      }
    }
  }
  sudoku.print();
  return 0;
}
