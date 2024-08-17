#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

void f(int curr, int end, std::vector<int>& pred, std::vector<int>& ori, std::vector<int>& a, std::vector<int>& b, bool& possb){
    if(curr == end){
        if(pred == ori){
            possb = true;
        }
        return;
    }

    // debug("pred");
    // for(int i = 0; i < pred.size(); i++){
        // std::cout << pred[i] << " ";
    // }

    int ai = a[curr];
    int bi = b[curr];

    pred[ai] += 3;
    f(curr + 1, end, pred, ori, a, b, possb);
    pred[ai] -= 3;

    pred[bi] += 3;
    f(curr + 1, end, pred, ori, a, b, possb);
    pred[bi] -= 3;

    pred[ai] += 1;
    pred[bi] += 1;
    f(curr + 1, end, pred, ori, a, b, possb);
    pred[ai] -= 1;
    pred[bi] -= 1;

}

int main(){

    int t;
    std::cin >> t;
    
    while(t--){
        int n;
        std::cin >> n;

        std::vector<int> score(n);
        for(int i = 0; i < n; i++){
            std::cin >> score[i];
        }

        std::vector<int> a, b;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                a.push_back(i);
                b.push_back(j);
            }
        }

        bool possb = false;
        int match = n * (n - 1) / 2;
        std::vector<int> pred(n, 0);
        f(0, match, pred, score, a, b, possb);

        std::cout << (possb ? "YES" : "NO") << std::endl;
    }

    return 0;
}