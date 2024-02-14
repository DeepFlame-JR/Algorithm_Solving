#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};
int N, Map[max_n][max_n];
string ans;

void go(int x, int y, int n){
    int cur = Map[x][y];

    for(int i = x ; i < x+n ; i ++){
        for(int j = y ; j < y+n ; j ++){
            if(cur != Map[i][j]){
                cout << '(';
                go(x, y, n/2);
                go(x, y+n/2, n/2);
                go(x+n/2, y, n/2);
                go(x+n/2, y+n/2, n/2);
                cout << ')';
                return;
            }
        }
    }

    cout << cur;
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            scanf("%1d", &Map[i][j]);
        }
    }
    
    go(0, 0, N);

    return 0;
}