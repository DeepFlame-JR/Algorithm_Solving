#include<bits/stdc++.h>
using namespace std;

const int max_n = 1004;
int N, C, arr[max_n];
map<int, int> mp_counter, mp_first;
vector<pair<int, int>> v;

// custom compare!!
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return mp_first[a.first] < mp_first[b.first]; // 2순위: 더 빨리 나온 순서 (오름차순)
    }
    return a.second > b.second; // 1순위: count가 더 많은 순서 (내림차순)
}

int main(){
    cin >> N >> C;

    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];

        mp_counter[arr[i]] ++;
        if(mp_first[arr[i]]==0) mp_first[arr[i]] = i+1; // 초기화 값이 0이기 때문에 "+1"을 해줌
    }

    for(auto it: mp_counter){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto it: v){
        for(int i = 0 ; i < it.second ; i++){
            cout << it.first << " ";
        }
    }

    cout << '\n';

    return 0;
}