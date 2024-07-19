#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<numeric>
 
#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;
 
using ll = long long;
 
int main(){

    /*
        given x street of lneght numbered 0 .. to x
        given n traffic lights, and n[i] traffic light at position between 0..x

        find most longest passage (no traffic lights) in the street after adding traffic light one after another

        sol
            using lower_bound or upper_bound to split traffic light distance between them, and erase the distance that have been splitted.
            then using multiset (sorted when insertion (may use priority queue)) to get most longest (*multiset.end())
    */

    // why this fast IO make verdict correct?
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
 
    int x, n;
    std::cin >> x >> n;
 
    std::set<int> lights({0, x});
    std::multiset<int> dist;
    dist.insert(x);
 
    for(int i = 0; i < n; i++){
        int p;
        std::cin >> p;
 
        auto it = lights.lower_bound(p);
        int l, r;
        if(it == lights.begin()){ // no need if using upper_bound(), maybe
            l = 0;
            r = 0;
        }else{
            r = *it - p;
            l = p - *--it;
        }
 
        // if(l + r == pq.top()){ // if using priority queue
        //     pq.pop(); // we need pop for specific segments (err)
        // }
 
        dist.erase(dist.find(l + r)); // will erased if available? maybe
        dist.insert(l);
        dist.insert(r);
 
        lights.insert(p);
 
        std::cout << *--dist.end() << std::endl;
    }
 
    return 0;
}