#include<bits/stdc++.h>
using namespace std;

int N, d, cnt;

int main(){

    while(scanf("%d", &N) != EOF){
        d = 1, cnt = 1;
        while(true){
            if(d % N == 0) break;

            d = (d*10) + 1;
            d %= N;
            cnt ++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}