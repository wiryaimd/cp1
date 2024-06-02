#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int a[n];
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }

        int curr = a[0] + a[1];
        int last = a[1];
        bool valid = true;
        for(int j = 2; j < n; j++){
            debug(last);
            if(curr != last + a[j]){
                valid = false;
                break;
            }

            curr = last + a[j];
            last = a[j];
        }

        cout << (valid ? "YES" : "NO") << endl;
    }

    return 0;
}