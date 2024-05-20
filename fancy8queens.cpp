#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || (c - i) == abs(q[c] - q[i])) 
            return false; 
    }
    return true; 
}

void print(int q[])
{
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": ";
    cout << endl;
    
    int i, j, k, l;
    typedef char box[5][7]; //box now becomes a data type
    box bb, wb, *board[8][8]; //black box, white box, and a pointer array board that points to box
    
    //fill in the contents of each box
    for(i=0; i < 5; i++){
        for(j=0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
    }
    
    //Create both black and white queens as boxes
   static box bq = {
       {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
       {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
       {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
       {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
       {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
   };
               
   static box wq = {
       {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },  
       {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
       {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
       {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
       {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }
   };

    
    //determine whether we're printing a white or black box
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if((i+j)%2 == 0)
                board[i][j] = &wb;
            else
                board[i][j] = &bb;
        }
    }

    //place black queen on white square and white queen on black square based on their positions in the q[] array 
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(((i+j)%2 == 0) && q[j] == i){ 
                board[i][j] = &wq;
            }
            if(((i+j)%2 != 0) && q[j] == i){ 
                board[i][j] = &bq;
            }            
        }
    }
    
    //print upper border
    cout << " ";
    for(i=0; i < 7*8; i++){
        cout << '_';
    }
    cout << endl;
    
    //print the board
    for(i=0; i < 8; i++){
        for(k=0; k < 5; k++){
            cout << "|";
            cout << " " << char(179); //print left border 
            for(j=0; j < 8; j++){
                for(l=0; l < 7; l++){
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << char(179) << "|" << endl; //print bar and then newline
        }
    }
    
    //print lower border
    cout << " ";
    for(i=0; i < 7*8; i++){
        cout << char(196);
    }
    cout << endl;
    cout << endl;

}

int main(){
    int q[8]={0}, col = 0;
    q[0] = 0; 
    
    while(col >= 0){ //check the backtrack to determine when to stop
        col++; 
        
        if(col == 8){ //if we've moved beyond the last column print solution
            print(q);
            col--; //backtrack
        }
        
        else
            q[col] = -1; //reset the row behind the first row
            
        while(col >= 0){ //inner while loop, position check
            q[col]++; //go to the next row
            
            if(q[col] == 8) //if there are no more rows go to the previous col
                col--; 
                
            else if(ok(q, col)) //check position of a queen here is ok
                break; 
        }
    }
    return 0;
}
