#include<iostream>

using namespace std;

int rec(int a){
    if(a == 0){
        return 1;
    }

    for(int i = 0; i < 3; i++){
        cout << "asede" << endl;
        rec(a - 1);

        cout << "bba" << endl;
    }

    return 0;
}

int main(){

    // backtracking
    rec(2);

    

    return 0;
}