#include<iostream>
#include<cmath>

using namespace std;
int main(){

    int n;
    cin >> n;

    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        cin >> y[i];
    }

    int maxx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ // atau bisa pakai j = i + 1 instead, karena memabndingkan each i dan j yang berbeda
            if(i == j){
                continue;
            }

            // problem menginginkan maksimum pangkat euclidean distance, 
            // oleh karena itu tidak di pangkat
            // d^2 = (x2 - x1)^2 + (y2 - y1)^2
            int d = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
            maxx = max(maxx, abs(d));
        }
    }

    cout << maxx << endl;

    return 0;
}
