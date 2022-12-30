#include<bits/stdc++.h>
using namespace std;

int N, M, T, l=1, r, temp, ans;

int main(){
    cin >> N >> M >> T; 

    for(int t = 0; t < T; t++){
        cin >> temp;

        r = l + M - 1;
        int move=0;
        if(temp < l){
            move = l-temp;
            l -= move;
        } 
        else if(temp > r){
            move = temp-r;
            l += move;
        }

        ans += move;
    }

    cout << ans << '\n';
    return 0;
}