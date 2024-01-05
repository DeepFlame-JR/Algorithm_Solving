// solve again

#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

int N, d, p, result;
vector<pair<int, int>> Pay;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> N;
    for(int n = 0 ; n < N ; n ++){
        cin >> p >> d;
        Pay.push_back({d, p});
    }
    sort(Pay.begin(), Pay.end());

    for(int i = 0 ;i < N ; i ++){
        pq.push(Pay[i].second);
        if(pq.size() > Pay[i].first){
            pq.pop();
        }
    }

    while(pq.size()){
        result += pq.top(); pq.pop();
    }

    cout << result << '\n';
    return 0;
}