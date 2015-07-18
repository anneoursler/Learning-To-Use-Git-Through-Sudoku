#include <iostream>
#include "board.h"
using namespace std;

struct Possible{
  int x, y;
  int options[9];
  int length;
};

// TODO: add clause of imposible problems
// TODO: shorten main()
// BUG: Infinite Loop w/o final if statments
// BUG: cout << endl; after final print to prevent segfault

int main(){
  Board sudoku;
  sudoku.read_in();
  sudoku.print();
  int itts = 0;
  while (sudoku.finished() == false){
    for (int i=0; i<9; i++){
      for (int j=0; j<9; j++){
	if (sudoku.get_value(i,j)==0){//If blank, try to fill
	  Possible pos;
	  // pos.x=i;
	  // pos.y=j;
	  pos.length = 0;
	  for (int k=1; k<=9; k++){ //Find all possible numbers
	    if (!sudoku.search_horizontal(j,k) &&
		!sudoku.search_vertical(i,k)   &&
		!sudoku.search_square(i,j,k)){
	      pos.options[pos.length] = k;
	      pos.length++;
	    }
	  }
	  if (pos.length == 1){//Fill blank
	    sudoku.set_value(i,j,pos.options[0]);
	    // cout << endl;
	    //cout << i << "," << j << ":" << pos.options[0] << endl;
	    // sudoku.print();
	  }
	}
      }
    }
    if (itts == 1000){
      break;
    }
    itts++;
  }
  cout << "Solution: " << endl;
  sudoku.print(); 
  cout << endl;
  return 0;
}
