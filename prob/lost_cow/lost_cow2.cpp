#include<iostream>

using namespace std;
int main(){

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;

    int dist = 0;
    int move = 1;
    int curr = x;
    if(x < y){
        while(curr < y){
            dist += abs((x + move) - curr);
            // cout << "dist " << dist << endl;
            curr = x + move;

            move *= -2;
        }
        cout << dist - (curr - y) << endl;
    }else{
        while(curr > y){
            dist += abs((x + move) - curr);
            // cout << "dist " << dist << endl;
            curr = x + move;

            move *= -2;
        }
        cout << dist - abs(curr - y) << endl;
    }

    return 0;
}