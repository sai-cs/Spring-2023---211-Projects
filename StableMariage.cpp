#include <iostream>
using namespace std;
    
bool ok(int p[], int c){

    static int mp[3][3] = {
    //   W0 W1 W2
        { 0,2,1 },    //Man 0
        { 0,2,1 },    //Man 1
        { 1,2,0 }     //Man 2
    };
    
    static int wp[3][3] = {
    //   M0 M1 M2
        { 2,1,0 },    //Woman 0
        { 0,1,2 },    //Woman 1
        { 2,0,1 }     //Woman 2
    };
    
    for(int i=0; i < c; i++){
        /*If current man likes new woman AND new woman likes current man.. 
        OR 
        If new man likes current woman AND current woman likes new man.. it's an unstable marriage */
        
        if(p[c] == p[i] || mp[i][p[c]] < mp[i][p[i]] && wp[p[c]][i] < wp[p[c]][c] || mp[c][p[i]] < mp[c][p[c]] && wp[p[i]][c] < wp[p[i]][i]){
            return false; 
        }
    }
    return true;
}

void print(int p[]){
    static int pairing=0;
    cout << "Pairing #" << ++pairing << ":\nMan\tWoman\n";
    for(int i=0; i < 3; i++){
        cout << i << "\t" << p[i] << "\n";
    }
    cout << endl;
}


int main(){
    int p[3], c = 0;
    //For the pairings we will focus on man to woman through c.
    while(c >= 0){
        c++;
        if(c==3){
            print(p);
            c--;
        }
        
        else{
            p[c] = -1;
        }
        
        while(c >= 0){
            p[c]++;
            if(p[c] == 3){
                c--;
            } else if (ok(p, c)) {
                break;
            }
        }
    }
    
    return 0;
}