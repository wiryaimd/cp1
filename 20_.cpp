/*
 * Prob: Collatz Problem
 * File Created: Saturday, 4th May 2024 1:19:22 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given int s
        generate value 'a' from s
        when a-ith is even, then a = a / 2
        when a-ith is odd, then a = 3 * a + 1

        check if theres same value generated in that a-ith

        sol:
        store seen value in boolean array
    */

    int s;
    cin >> s;
    
    bool a[1000000] = {false};
    int n = s;
    a[n] = true;
    int cnt = 1;
    while(true){
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = 3 * n + 1;
        }
        // cout << n << endl;
        
        cnt++;
        if(a[n]){
            break;
        }

        a[n] = true;
    }

    cout << cnt << endl;

    return 0;
}