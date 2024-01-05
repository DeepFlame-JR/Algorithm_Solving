// 보석 도둑
// Solve Again
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, K, m, v, result;
vector<pair<ll, ll>> jewels;
vector<ll> backs;
priority_queue<ll> pq;

int main(){
    cin >> N >> K ; 
    for(int i = 0 ; i < N ; i ++){
        cin >> m >> v;
        jewels.push_back({m, v});
    }
    for(int i = 0 ; i < K ; i ++){
        cin >> m;
        backs.push_back(m);
    }

    sort(jewels.begin(), jewels.end());
    sort(backs.begin(), backs.end());

    int idx = 0;
    for(int i = 0 ;i < K ; i++){
        while(idx < N && jewels[idx].first <= backs[i]){ // 가방에 넣을 수 있는 것은 다넣음
            pq.push(jewels[idx++].second);
        }
        if(pq.size()){
            result += pq.top(); pq.pop();  // 가장 값비싼 것만 고름
        }
    }

    cout << result << '\n';

    return 0;
}