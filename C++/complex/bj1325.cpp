#include<bits/stdc++.h>
using namespace std;

int N, M, a, b, ans[10001], Visit[10001], m;
vector<int> Map[10001]; // map 대신에 이런 자료형도 생각해보자 !

int dfs(int cur){
    int ret = 1;
    Visit[cur] = 1;

    for(int n : Map[cur]){
        if(Visit[n]==1) continue;
        ret += dfs(n);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    while(M--){
        cin >> a >> b;
        Map[b].push_back(a);
    }

    for(int i = 1; i <= N ; i++){
        fill(Visit, Visit+10001, 0);
        ans[i] = dfs(i);
        m = max(m, ans[i]);
    }

    for(int i = 1 ; i <= N ; i++){
        if(ans[i] == m) cout << i << " ";
    }

    return 0;
}