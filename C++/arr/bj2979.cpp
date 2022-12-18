#include<bits/stdc++.h>
using namespace std;

int A, B, C, arr[100], ans, a, b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    for(int i = 0 ; i < 3; i++){
        cin >> a >> b;
        for(int i=a; i<b; i++) arr[i] += 1;
    }

    int ans = 0;
    for(int i : arr){
        if(i == 1) ans += A;
        else if(i == 2) ans += 2*B;
        else if(i == 3) ans += 3*C;
    }

    cout << ans << '\n';

    return 0;
}