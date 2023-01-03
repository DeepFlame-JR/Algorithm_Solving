#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, n, ans;
ll d;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i ++){
        cin >> n;
        ans = 0, d = 5;
        while(n >= d){
            ans += n / d;
            d *= 5;
        }

        cout << ans << '\n';
    }

    return 0;
}