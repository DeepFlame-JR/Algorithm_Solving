#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N, M, Map[10][10], Visit[10][10], x, y, nx, ny, ans;
vector<pair<int, int>> virus_list;
vector<pair<int, int>> empty_list;

void solve(){
    fill(&Visit[0][0], &Visit[0][0]+100, 0);
    int cnt = empty_list.size()-3;
    queue<pair<int, int>> q;

    for(auto v: virus_list){
        Visit[v.first][v.second] = 1;
        q.push(v);
    }

    while(!q.empty()){
        tie(x, y) = q.front() ; q.pop();
        for(int i = 0 ; i < 4 ; i ++){
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            if(Map[nx][ny] == 0 && Visit[nx][ny] == 0){
                Visit[nx][ny] = 1;
                q.push({nx, ny});
                cnt--;
            }
        }
    }
    ans = max(ans, cnt);
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N ; i ++){
        for(int j = 0 ; j < M ; j ++){
            cin >> Map[i][j];
            if(Map[i][j] == 2) virus_list.push_back({i, j});
            else if(Map[i][j] == 0) empty_list.push_back({i, j});
        }
    }

    for(int i = 0 ; i < empty_list.size() ; i ++){
        for(int j = 0 ; j < i ; j++){
            for(int k = 0 ; k < j ; k ++){
                Map[empty_list[i].first][empty_list[i].second] = 1;
                Map[empty_list[j].first][empty_list[j].second] = 1;
                Map[empty_list[k].first][empty_list[k].second] = 1;
                solve();
                Map[empty_list[i].first][empty_list[i].second] = 0;
                Map[empty_list[j].first][empty_list[j].second] = 0;
                Map[empty_list[k].first][empty_list[k].second] = 0;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}