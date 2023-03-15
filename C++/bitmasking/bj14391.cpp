#include<bits/stdc++.h>
using namespace std;

const int max_n = 5;
int N, M, Map[max_n][max_n], Dir[max_n][max_n], Visit[max_n][max_n], ans;

int DFS(int x, int y, int dir, int prev){
    if(x < 0 || x > N-1 || y < 0 || y > M-1 || Visit[x][y] || Dir[x][y] != dir) return prev;
    Visit[x][y] = 1;

    int ret = Map[x][y] + 10*prev;
    if(Dir[x][y] == 0) ret = DFS(x+1, y, dir, ret);
    else ret = DFS(x, y+1, dir, ret);

    return ret;
}

int main(){
    cin >> N >> M;
    int T = N*M;

    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j ++){
            scanf("%1d", &Map[i][j]);
        }
    }

    for(int i = 0 ; i < (1<<T) ; i ++){
        fill(&Dir[0][0], &Dir[0][0]+max_n*max_n, 0);
        fill(&Visit[0][0], &Visit[0][0]+max_n*max_n, 0);
        for(int j = 0 ; j < T ; j ++){
            if(i & (1<<j)){
                Dir[j/M][j%M] = 1;
            }
        }

        int sum = 0;
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                if(!Visit[x][y]){
                    sum += DFS(x, y, Dir[x][y], 0);
                } 
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}