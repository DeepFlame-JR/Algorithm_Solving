#include<bits/stdc++.h>
using namespace std;

int N, M, s, e, inDegree[32001];
vector<int> Problem[32001], result;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> N >> M; 

    for(int i = 0 ;i < M ; i++){
        cin >> s >> e;
        Problem[s].push_back(e);
        inDegree[e]++;
    }

    for(int i = 1 ; i <= N ; i++){
        if(inDegree[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        for(int nxt:Problem[cur]){
            inDegree[nxt]--;
            if(inDegree[nxt] == 0){
                pq.push(nxt);
            }
        }
        result.push_back(cur);
    }

    for(int re : result){
        cout << re << ' ';
    }

    return 0;
}