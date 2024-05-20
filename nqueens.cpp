#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // Reuse the ok function from your 1D 8 queens program.
   for (int i = 0; i < c; i++)
       if (q[i] == q[c] || (c-i) == abs(q[c]-q[i])) //3 tests in one line
            return false; 

    return true; 
}

// This function should return the number of solutions for the given board size
// (you don't need to print the solutions).

int nqueens(int n) {
    
   // Dynamically declare an array of size n and initialize the first element to 0.
   int* board = new int[n];
   board[0] = 0;
   int solutions=0, col=0;
   
   // Reuse the code from your 1D 8 queens program to find the solutions (may need updates).
   
   while(col >= 0){// if we backtrack beyond the first col, we are done
   

        // if we have moved beyond the last column
        if(col >= n){
            solutions++; // print the board
            col--; // backtrack
            board[col]++;
        }

        // If we have moved beyond the last row 
        if(board[col] >= n){
            board[col] = 0; // reset queen
            col--; // backtrack
            if (col != -1) board[col]++;
        }

        // Check if the placed queen is ok.
        else if( ok(board, col) ){
            col++; // move to next column if ok
            if (col < n) board[col] = 0;
        } 
        else{
            board[col]++; // move to next row if not ok
        }
    }
    
   // Delete the array.
   delete[] board;
   
   // Return the number of solutions.
   return solutions;
}

int main() {
   int n;
   cout << "Enter the amount of Queens : ";
   cin >> n;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}