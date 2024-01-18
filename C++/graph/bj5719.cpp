#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MAX = numeric_limits<int>::max();
const int max_i = 501;
int N, M, s, e, a, b, w;
vector<vector<int>> prv;  // 최단 거리 시에 경로를 저장하기 위한 vector
vector<vector<P>> Map;
bool Check[max_i][max_i];

void init(){
    prv.clear(); Map.clear();
    prv = vector<vector<int>>(max_i);
    Map = vector<vector<P>>(max_i);
    memset(Check, false, sizeof(Check));

    cin >> s >> e;
    for(int i = 0 ; i < M ; i ++){
        cin >> a >> b >> w;
        Map[a].push_back({w, b});
    }
}

int dijkstra(){
    int Visit[501];
    for(int i = 0 ; i < N ; i ++){
        Visit[i] = MAX;
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    Visit[s] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first; pq.pop();

        if(cost > Visit[cur]) continue;
        if(cur == e){
            return cost;
        }

        for(P x : Map[cur]){
            int next = x.second;
            int ncost = x.first;
            if(Check[cur][next]) continue;

            if(Visit[next] > Visit[cur]+ncost){
                Visit[next] = Visit[cur]+ncost;
                pq.push({Visit[next], next});
                prv[next].clear();
                prv[next].push_back(cur);
            }
            else if(Visit[next] == Visit[cur]+ncost)
                prv[next].push_back(cur);
        }
    }

    return -1;
}

void erase(int cur){
    for(int x:prv[cur]){
        if(!Check[x][cur]){
            Check[x][cur] = true;
            erase(x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        init();
        dijkstra();
        erase(e);
        cout << dijkstra() << '\n';
    }

    return 0;
}