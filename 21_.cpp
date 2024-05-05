/*
 * Prob: Next Prime
 * File Created: Saturday, 4th May 2024 1:45:03 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given int x
        check the next prime more than or equal x

        using normal prime checker, and increment x until found

        need to know that:
        constrainst x < 100k but it will not loop more than 100th,
        because theres will always at least one prime number between 100th times
    */

    int x;
    cin >> x;

    while(true){
        bool prime = true;
        for(int i = 2; i < x; i++){ 
            if(x % i == 0){
                prime = false;
                break;
            }
        }

        if(prime){
            break;
        }

        x++;
    }

    cout << x << endl;

    return 0;
}