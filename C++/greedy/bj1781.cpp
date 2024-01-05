#include<bits/stdc++.h>
using namespace std;

int N, result, a, b;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> arr;

int main(){
    cin >> N;

    for(int i = 0 ; i < N ; i ++){
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < N ; i ++){
        pq.push(arr[i].second);
        if(pq.size() > arr[i].first) pq.pop();
    }

    while(pq.size()) {
        result += pq.top(); pq.pop();
    }
    cout << result << '\n';

    return 0;
}