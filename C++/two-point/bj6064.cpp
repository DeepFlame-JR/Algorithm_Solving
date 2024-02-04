#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, M, N, X, Y;

ll go(ll x, ll y, ll last){
    while(x <= last && y <= last){
        if(x<y) x+=M;
        else if(x>y) y+=N;
        else return x;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    
    for(int _ = 0; _ < T ; _++){
        cin >> M >> N >> X >> Y;
        ll last = go(M, N, 91600000000);
        cout << go(X, Y, last) << '\n';
    }

    return 0;
}