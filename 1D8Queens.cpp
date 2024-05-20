#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
    for(int i = 0; i < c; i++)
        if(q[c] == q[i] || (c-i) == abs(q[c]-q[i]))
            return false;
    return true;
}

void print(int q[], int &s){
    cout << "Solution #" << s << " :" << endl;
    s++;
    
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(q[i] == j)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int board[8]={0}, col = 0, solution = 1;
    //put the queen in the upper left square
    board[0] = 0; //b[0][0] = 1 in 2D version
    
    while(col >= 0){// if we backtrack beyond the first col, we are done
     
        // if we have moved beyond the last column
        if(col == 8){
            // print the board
            // backtrack
            print(board, solution);
            col--;
        }
        
        // If we have moved beyond the last row 
        else if(board[col] == 8){
            // reset queen
            // backtrack
            board[col] = 0;
            col--;
        }
        
       // Check if the placed queen is ok.
        else{
            // move to next column if ok, move to next row if not ok
            board[col]++;
            if(ok(board, col)){
                col++;
            }
        } 

    }
    return 0;
}