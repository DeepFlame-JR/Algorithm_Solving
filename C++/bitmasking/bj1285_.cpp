#include<bits/stdc++.h>
using namespace std;

int N, Map[21], ans=987654321;
string s;

void go(int cur){
    if(cur == N+1){
        // 열을 체크해보자
        int sum = 0;
        for(int i = 1 ; i <= (1 << (N-1)); i *= 2){  // 각 열에 대해서 확인해본다
            int cnt = 0;
            for(int j = 0 ; j < N ; j++) if(Map[j] & i) cnt++;
            sum += min(cnt, N-cnt);  // 열을 뒤집을지 말지 결정해본다
        }

        ans = min(ans, sum);        
        return;
    }

    go(cur+1); // 안 뒤집음
    Map[cur] = ~Map[cur];
    go(cur+1);  // 뒤집음
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        cin >> s;

        // 비트 마스킹을 이용 HHT > 4, THT > 5
        int temp = 0;
        for(int j = 0 ; j < N ; j ++){
            if(s[j] == 'T') temp += (1 << j) ;
        }
        Map[i] = temp;
    }

    go(0);
    cout << ans ;
    return 0;
}