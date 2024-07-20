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

std::multiset<int> gaps;
// gaps.insert(len);
std::set<int> pos;

void modify(int x, int len){
    if(x == 0 || x == len) return;

    auto it = pos.find(x);
    if(it == end(pos)){
        it = pos.insert(x).first;
        int l = *std::prev(it), r = *std::next(it); 

        gaps.insert(x - l);
        gaps.insert(r - x);
        gaps.erase(gaps.find(r - l));
        debug(x);
    }else{
        int l = *std::prev(it), r = *std::next(it);
        gaps.erase(gaps.find(x - l));
        gaps.erase(gaps.find(r - x));
        gaps.insert(r - l);
        pos.erase(it);
        debug(*it);
    }
}

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::string s;
    std::cin >> s >> n;

    int len = s.length();
    pos.insert(0);
    pos.insert(len);

    int curr = s[0];
    for(int i = 1; i < len; i++){
        if(curr != s[i]){

            // auto r = pos.upper_bound(i);
            // auto l = r;
            // --l;

            // gaps.insert(*r - i);
            // gaps.insert(i - *l);
            // gaps.erase(gaps.find(*r - *l));

            pos.insert(i);
        }
        curr = s[i];
    }

    for(auto it = pos.begin(); std::next(it) != pos.end(); it++){
        gaps.insert(*std::next(it) - *it);
    }

    for(auto i : gaps){
        debug(i);
    }

    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        x--;
        
        modify(x, len);
        modify(x + 1, len); // call modify twice for check next position that contain diff in pos[], eg. 001011. here 00(10)11 will have two diff in each other side, then we need to recalculate the length
        
        // *--gaps.end() === *gaps.rbegin()
        std::cout << *--gaps.end() << std::endl;
    }

    return 0;
}