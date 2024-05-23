#include<iostream>
#include<cstring>

using namespace std;

int main(){

    
    // NB
    // int a = 3;
    // for(int i = a * a; i < 100; i += a){ // init = a * a, then i += a
    //     cout << i << endl;
    // }

    
    // for(int i = 0; i * i < 100; i++){ // i < sqrt(100)
    //     cout << "give " << i << endl;
    // }

    /*
        generate prime number up to N

        nb. its different with checking is it a prime number or not (using % 2 == 0)
    */

    int n = 100;
    bool mark[n];
    memset(mark, true, sizeof(mark));

    for(int i = 2; i * i <= n; i++){
        if(mark[i]){
            for(int j = i * i; j <= n; j += i){
                mark[j] = false;
            }
        }
    }

    for(int i = 2; i < n; i++){
        if(mark[i]){
            cout << i << endl;
        }
    }


    return 0;
}