#include<bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    int cnt = 0;
    for(int i = 0 ; i <= 6 ; i ++){
        if(N & (1<<i)) cnt++;
    }

    cout << cnt;
    return 0;
}