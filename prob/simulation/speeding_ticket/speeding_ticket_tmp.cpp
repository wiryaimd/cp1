/*
 * Author: Wiryaimd
 * File Created: Monday, 25th March 2024 4:13:32 pm
 * CF 24-13
 */

#include<iostream>

using namespace std;
int main(){

    int n, m;
    cin >> n >> m;
    pair<int, int> limit[n], speed[m];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        limit[i] = {a, b};
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        speed[i] = {a, b};
    }

    
    int i = 0, k = 0;
    int maxx = 0;
    int len_limit = limit[k].first;
    int len_speed = speed[i].first;
    while(true){
        if(i == m){
            break;
        }

        printf("lim %d w %d\n", len_limit, len_speed);

        if(len_limit < len_speed){
            k++;
            len_limit += limit[k].first;
            continue;
        }

        if(speed[i].second > limit[k].second){
            maxx = max(maxx, speed[i].second - limit[k].second);
        }

        i++;
        len_speed += speed[i].first;
    }

    cout << maxx << endl;

    return 0;
}