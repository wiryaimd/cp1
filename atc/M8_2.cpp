/*
 * Prob: Colorful Leaderboard
 * File Created: Tuesday, 21st May 2024 1:10:44 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<set>

using namespace std;

int main(){

    int n;
    cin >> n;

    set<int> s;
    int over = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a >= 3200){
            over++;
            continue;
        }

        s.insert(a / 400);
    }

    cout << max(1, (int)s.size()) << " " << s.size() + over << endl;


    return 0;
}