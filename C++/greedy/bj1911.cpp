#include<bits/stdc++.h>
using namespace std;

int N, L, s, e, result;
vector<pair<int, int>> Map;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    for(int n = 0 ; n < N ; n ++){
        cin >> s >> e;
        Map.push_back({s, e});
    }
    sort(Map.begin(), Map.end());

    e = 0;
    for(int i = 0 ; i < N ; i ++){
        if(Map[i].second <= e) continue;
        if(Map[i].first <= e){
            Map[i].first = e;
        }

        int diff = Map[i].second-Map[i].first;
        int div = diff/L;
        int rest = diff%L;

        if(rest > 0) div += 1;
        result += div;

        e = Map[i].first + div*L;
        // cout << Map[i].first << ' ' << Map[i].second << ' ' << e << ' ' << result << '\n';
    }

    cout << result << '\n';

    return 0;
}