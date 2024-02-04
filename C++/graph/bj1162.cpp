#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const ll MAX = numeric_limits<ll>::max();

struct Node{
    ll weight; ll id; ll k;
    Node(ll weight, ll id, ll k): weight(weight), id(id), k(k) { }
};

struct Cmp{
    bool operator()(Node a, Node b){
        return a.weight > b.weight;
    }
};


ll N, M, K, a, b, c, Visit[10001][21];
vector<P> Map[10001];
priority_queue<Node, vector<Node>, Cmp> pq;

int main(){
    cin >> N >> M >> K;
    for(int m = 0 ; m < M ; m ++){
        cin >> a >> b >> c;
        Map[a].push_back({b, c});
        Map[b].push_back({a, c});
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j <= K ; j++){
            Visit[i][j] = MAX;
        }
    }

    pq.push(Node(0, 1, K));
    Visit[1][K] = 0;
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();

        if(Visit[cur.id][cur.k] < cur.weight) continue;
        if(cur.id == N){
            cout << cur.weight << '\n';
            return 0;
        }

        for(P next : Map[cur.id]){
            if(Visit[cur.id][cur.k] + next.second < Visit[next.first][cur.k]){
                Visit[next.first][cur.k] = Visit[cur.id][cur.k] + next.second;
                pq.push(Node(Visit[cur.id][cur.k] + next.second, next.first, cur.k));
            }

            if(cur.k > 0){
                if(Visit[cur.id][cur.k] < Visit[next.first][cur.k-1]){
                    Visit[next.first][cur.k-1] = Visit[cur.id][cur.k];
                    pq.push(Node(Visit[cur.id][cur.k], next.first, cur.k-1));
                }
            }
        }
    }

    // ll result = MAX;
    // for(int k = 0 ; k <= K ; k ++)
    //     result = min(result, Visit[N][k]);

    // cout << result << '\n';
    return 0;
}