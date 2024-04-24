/*
 * Author: Wiryaimd
 * File Created: Sunday, 31st March 2024 12:42:29 pm
 * USACO diamond collector, 15mins
 */


#include<iostream>
#include<algorithm>

using namespace std;
int main(){

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data, data + n);

    int maxx = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1; // == 1 because i also counted with j at same time
        for(int j = i + 1; j < n; j++){
            if(data[j] - data[i] > k){
                // cnt = j - i; // use cnt++ instead of this
                break;
            }
            cnt++;
        }

        maxx = max(maxx, cnt);
    }

    cout << maxx << endl;

    return 0;
}