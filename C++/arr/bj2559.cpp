#include<bits/stdc++.h>
using namespace std;

int N, K, psum[100005], a, b, ans, temp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> temp;
        psum[i+1]=psum[i]+temp;
    }

    ans = INT_MIN;
    for(int i=K; i <= N ; i++){
        ans = max(ans, psum[i]-psum[i-K]);    
    }
    
    cout << ans << '\n';
    return 0;
}