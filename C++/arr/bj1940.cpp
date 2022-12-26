#include<bits/stdc++.h>
using namespace std;

int N, M, t, ans;
map<int, int> sub;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N; 
    cin >> M;

    if(M > 200000){ // 고유한 수가 최대 10만이기때문에 20만이 필요하면 못 만듬
        cout << 0 << '\n';
        return 0;
    }

    for(int n = 0; n < N; n++){
        cin >> t;
            
        if(sub.find(M-t) != sub.end()) ans ++;
        sub[t]=1;
    }

    cout << ans << '\n';
    return 0;
}