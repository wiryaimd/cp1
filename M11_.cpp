/*
 * Prob: B - Checkpoint
 * File Created: Thursday, 23rd May 2024 11:20:09 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given coordinate 
            N: x1, y1 and
            M: x2, y2
        
        find which x2, y2 is most smallest mahattan distance with x1, y1

        solution:
            just brute force because constraints up to 50
            
            |a[i].x - b[j].x| + |a[i].y - b[j].y|

    */

    int n, m;
    cin >> n >> m;

    pair<int, int> a[n], b[m];
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        a[i] = make_pair(x, y);
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        
        b[i] = make_pair(x, y);
    }

    for(int i = 0; i < n; i++){
        int minn = INT32_MAX;
        int pos = 0;
        for(int j = 0; j < m; j++){
            int dist = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);
            if(dist < minn){
                minn = dist;
                pos = j;
            }
        }
        cout << pos + 1 << endl;
    }

    return 0;
}