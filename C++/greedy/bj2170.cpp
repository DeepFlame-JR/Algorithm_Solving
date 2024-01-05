#include<bits/stdc++.h>
using namespace std;

int N, s, e, result;
vector<pair<int, int>> lines;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i = 0 ; i < N ; i ++){
        cin >> s >> e;
        lines.push_back({s, e});
    }

    sort(lines.begin(), lines.end());
    s = lines[0].first;
    e = lines[0].second;

    for(int i = 1 ; i < N ; i ++){
        if(e < lines[i].first){
            result += e-s;
            s = lines[i].first;
            e = lines[i].second;
        }
        else if(lines[i].second > e){  // 범위에 포함되는 경우도 있음
            e = lines[i].second;
        }
    }
    result += e-s;

    cout << result << '\n';
    
    return 0;
}