/*
 * Author: Wiryaimd
 * File Created: Sunday, 31st March 2024 10:29:11 am
 * USACO milk pails, 14mins
 */

#include<iostream>

using namespace std;
int main(){

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    // the solution is just try all possible combinations and find its maximum

    int times = m / y;
    int maxx = 0;
    for(int i = 0; i <= times; i++){
        int total = y * (times - i);
        while(total + x <= m){
            total += x;
        }

        maxx = max(maxx, total);
    }

    cout << maxx << endl;


    // other solution
    /*
        for (int first = 0; first <= order; first++) {
            if (buck1 * first > order) { break; }
            for (int second = 0; second <= order; second++) {
                int n = (buck1 * first) + (buck2 * second); // try all combination
                if (n > order) { break; }
                closest = max(closest, n);
            }
        }
    */

    return 0;
}