/*
 * Prob: Five Dishes
 * File Created: Sunday, 12th May 2024 3:57:04 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    // given a, b, c, d, e, is food cooked in minute.
    // find smallest possible time to cook when customer can only place order in minute multiple 10 (0, 10, 20, ...)

    int data[5];
    for(int i = 0; i < 5; i++){
        cin >> data[i];
    }

    sort(data, data + 5, [](int a, int b){
        if(a % 10 == 0){
            return true;
        }

        if(b % 10 == 0){
            return false;
        }

        int muta = a / 10;
        int mutb = b / 10;
        return ((muta + 1) * 10 - a) < ((mutb + 1) * 10 - b);
    });

    int cnt = 0;
    for(int i = 0; i < 4; i++){        
        cnt += ((data[i] + 9) / 10) * 10;
    }
    cnt += data[4];

    cout << cnt << endl;



    return 0;
}