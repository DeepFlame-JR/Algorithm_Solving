#include<bits/stdc++.h>
using namespace std;

/*
20억이기 때문에 for문을 돌리면 시간초과

아래 내용을 활용 (log2 N)
2^14 = 2^7 * 2^7
2^7 = 2^3 * 2^3 * 2
2^3 = 2^1 * 2^1 * 2
*/

typedef long long ll;
ll a, b, c;

ll go(ll a, ll b){
    if(b == 1) return a%c;

    ll ret = go(a, b/2);
    ret = (ret*ret)%c;
    if(b%2==1) ret=(ret*a)%c; 
    return ret; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;

    cout << go(a, b) << '\n';

    return 0;
}