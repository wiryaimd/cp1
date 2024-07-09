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

int parent[30];
int rank[0];

void make_set(int v){
    parent[v] = v;
    rank[v] = 0; // if using union by rank
}

int find_set(int v){
   if(v == parent[v]) return v;
//    return find_set(parent[v]) // without path compression
   return parent[v] = find_set(parent[v]); // with path compression
   // which is this will set its root as parent (instead of its ancestors)
}

void union_set(int a, int b){ // combine it and make one graph (ancestors)
    a = find_set(a);
    b = find_set(b);
    if(a != b){ // if ancestors already same, then no need do any
        parent[a] = b; // or parent[b] = a; also correct

        // with union by rank
        // if(rank[a] < rank[b]) {
            // swap(a, b);
        // }

        // parent[b] = a;
        // if(rank[a] == rank[b]){
        //     rank[a]++;
        // }
    }

}

int main(){

    

    return 0;
}