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
const int N = 100;

std::vector<int> adj[N];
bool visit[N];

// print graph by level
int bfs(int root){ // eg root is x
    int cnt = 0;

    // use queue to execute most nearest level
    std::queue<int> q;
    q.push(root); // add root
    debug(root);

    while (!q.empty()){ // check until all data is visited, which is make queue empty
        int curr = q.front(); // check most first added node
        q.pop(); // pop this already used
        for(auto u : adj[curr]){ // get all its child (or its next level)
            if(!visit[u]){
                debug(u);

                visit[u] = true;
                q.push(u); // then add its list data to be process in next queue
            }
        }

        cnt++;
    }

    return cnt;
}

int main(){

    adj[1].push_back(3);
    adj[2].push_back(5);
    adj[3].push_back(2);
    adj[5].push_back(4);
    adj[1].push_back(9);
    adj[9].push_back(6);

    int c = bfs(1);
    debug(c);

    

    return 0;
}