/*
 * Prob: Friendly Rabbits
 * File Created: Saturday, 11th May 2024 5:55:23 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    /*
        given n array with xi value
        check if rabbit like each other
        
        eg.
        Rabbit i likes rabbit j and rabbit j likes rabbit i

        count the total
    */

    int n;
    cin >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    int cnt = 0;
    bool p[n] = {false};
    for(int i = 0; i < n; i++){
        if(p[i]){
            continue;
        }

        // if(data[i] == i + 1){ // rabbit cant like itself
        //     continue;
        // }

        if(data[data[i] - 1] - 1 == i){
            p[data[i] - 1] = true;
            p[i] = true;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}