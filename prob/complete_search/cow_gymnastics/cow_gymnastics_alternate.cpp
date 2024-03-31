#include <iostream>
using namespace std;

/*
    the solution is count and store all pair (var better[][]) 
    that meet a consistent condition
    and count how much that counted equal to k (or all k sessions is consistent)
*/

int N, K;
int rankings[10][20], better[20][20];

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    // reading in input
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> rankings[i][j];
            rankings[i][j]--;
        }
    }
    // calculating the amount of times that cow a comes before cow b
    for (int i = 0; i < K; i++) {              // looping over the trials
        for (int j = 0; j < N; j++) {          // rankings[i][j] = cow a
            for (int k = j + 1; k < N; k++) {  // rankings[i][k] = cow b
                better[rankings[i][j]][rankings[i][k]]++; // count consistent pair
            }
        }
    }
    // calculating answer
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (better[i][j] == K)  // if cow i comes before cow j K times then
                                    // increment our answer
                ans++;
        }
    }
    // print answer
    cout << ans;

    return 0;
}