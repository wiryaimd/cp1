/*
 * Prob: #
 * File Created: Friday, 3rd May 2024 4:00:27 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        just count most minimum cost, going left or going right
        when 'x' position as start point and 'a' position cost 1
    */

    int n, m, x;
    cin >> n >> m >> x;

    int l = 0;
    int r = 0;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        if(a < x){
            l++;
        }else{
            r++;
        }
    }

    cout << min(l, r) << endl;

    return 0;
}