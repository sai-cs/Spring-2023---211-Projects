#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    int helper[8][5] =   
        {{ -1 },
        { 0, -1 }, 
        { 0, -1 },
        { 0, 1, 2, -1 }, 
        { 0, 1, 3, -1 },
        { 1, 4, -1 },
        { 2, 3, 4, -1 },
        { 3, 4, 5, 6, -1 }};

    
    for (int i = 0; i < c; i++) {   
        if (abs(q[i] == q[c]))  
            return false; 
    }
    
    for (int i = 0; helper[c][i] != -1; i++) {  
        if (abs(q[c] - abs(q[helper[c][i]])) == 1) 
            return false; 
    }
    
    return true;
}

void print(int q[]) {
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << endl;
}

int main(){
    int q[8] = {0};
    int c = 0;
    q[c] = 1;
    int solution = 0;

    while(c >= 0){
        c++;
        if (c == 8) {
            solution++; 
            cout << "Solution #" << solution << " :" << endl;
            print(q); 
            //We will backtrack by moving to the previous column.
            c--;
        }
        
        else{
            q[c] = 0;
        }
        
        while(c >= 0){
            q[c]++;
            if(q[c] > 8){
                //If we cannot continue, go back to previous column. 
                c--;
            } else if (ok(q, c)) {
                //If we can place a number here, we exit and continue.
                break;
            }
        }
    }
    
    return 0;
}