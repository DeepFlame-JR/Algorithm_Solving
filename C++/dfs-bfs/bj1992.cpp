#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};
int N, Map[max_n][max_n];
string ans;

string go(int n, int x, int y){
    n /= 2;
    string t;

    if(n==1){
        for(int i = 0 ; i < 4; i ++){
            t += std::to_string(Map[x+dx[i]][y+dy[i]]);
        }
    }
    else{
        for(int i = 0 ; i < 4; i ++){
            t += go(n, x+dx[i]*n, y+dy[i]*n);
        }
    }

    if(t == "0000") t = "0";
    else if(t == "1111") t = "1";
    else t = '(' + t + ')';

    return t;
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            scanf("%1d", &Map[i][j]);
        }
    }
    
    cout << go(N, 0, 0) << '\n';

    return 0;
}