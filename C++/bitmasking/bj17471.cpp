#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, pop[10], cnt, ans = INF, temp;
vector<int> Map[11];

int main(){
    cin >> N;
    for(int n = 0 ; n < N ; n++) cin >> pop[n];

    for(int n = 0 ; n < N ; n++){
        cin >> cnt;
        for(int t = 0 ; t < cnt ; t++) {
            cin >> temp;
            Map[n].push_back(temp-1);
        }
    }

    for(int i = 0 ; i < (1<<N) ; i++){
        bool Visit[10];
        int area[N];
        int area_1 = -1;
        int area_2 = -1;

        for(int n = 0 ; n < N ; n++){
            if(i & (1<<n)) {
                area[n] = 1;
                area_1 = n;
            }
            else{
                area[n] = 2;
                area_2 = n;
            }
        }
        
        // 모두 같은 지역인지 확인
        if(area_1 == -1 || area_2 == -1) continue;

        // BFS
        queue<int> q1;
        q1.push(area_1);
        Visit[area_1] = true;
        while(!q1.empty()){
            int cur = q1.front() ; q1.pop();
            for(int nxt : Map[cur]){
                if(Visit[nxt] == false && area[nxt] == 1){
                    q1.push(nxt);
                    Visit[nxt] = true;
                }
            }
        }
        
        queue<int> q2;
        q2.push(area_2);
        Visit[area_2] = true;
        while(!q2.empty()){
            int cur = q2.front() ; q2.pop();
            for(int nxt: Map[cur]){
                if(Visit[nxt] == false && area[nxt] == 2){
                    q2.push(nxt);
                    Visit[nxt] = true;
                }
            }
        }
        
        // 모두 방문했는지 확인
        bool plag = true;
        for(int n = 0 ; n < N ; n ++){
            if(Visit[n] == false){
                plag = false;
            }
        }

        if(plag){
            int sum_1 = 0, sum_2 = 0;
            for(int n = 0 ; n < N ; n++){
                if(area[n] == 1) sum_1 += pop[n];
                else if(area[n] == 2) sum_2 += pop[n];
            }

            ans = min(ans, abs(sum_1 - sum_2));
        }
    }

    if(ans==INF) cout << -1;
    else cout << ans;

    return 0;
}