#include<bits/stdc++.h>
using namespace std;

const int max_n = 1004;
int T, N, E, Visit[max_n], a, b;
vector<int> Map[max_n];

int DFS(int n){
    if(Visit[n] == 1) return 0;
    Visit[n] = 1;
    int ret = 1;
    for(int nxt : Map[n]) ret += DFS(nxt);
    return ret;
}

int main(){
    scanf("%d", &T);
    for(int t = 0 ; t < T ; t++){
        for(int n = 1 ; n <= N ; n ++){
            Visit[n] = 0;
            Map[n].clear();
        }

        scanf("%d %d", &N, &E);

        for(int e = 0 ; e < E ; e++){
            scanf("%d %d", &a, &b);
            Map[a].push_back(b);
            Map[b].push_back(a);
        }

        if(E != N-1){
            printf("graph\n");
            continue;
        }

        if(DFS(1) != N) printf("graph\n");
        else printf("tree\n");
    }

    return 0;
}