#include<bits/stdc++.h>
using namespace std;


int N, M, ox, oy, rx, ry, bx, by;
int Map[11][11];
int dp[11][11][4];
string str;
queue<node> q;

struct node{
    int x1, y1, x2, y2, cnt;
}

int main(){
    cin >> N >> M ; 
    for(int i = 0 ; i < N ; i ++){
        cin >> str;
        for(int j = 0 ; j < M ; j ++){
            char c = str[j];
            Map[i][j] = c;
            if(c == 'R'){
                rx = i; ry = j;
            }
            else if(c == 'B'){
                bx = i; by = j;
            }
            else if(c == 'O'){
                ox = i ; oy = j;
            }
        }
    }

    q.




    return 0;
}