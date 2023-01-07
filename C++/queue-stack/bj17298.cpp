#include<bits/stdc++.h>
using namespace std;

const int max_n = 1000004;
int N, a[max_n], ans[max_n];
stack<int> stk;

int main(){
    cin >> N;
    fill(ans, ans+max_n, -1);
    for(int i = 0 ; i < N ; i ++){
        cin >> a[i];

        while(stk.size() > 0 && a[stk.top()] < a[i]){
            ans[stk.top()] = a[i]; stk.pop();
        }
        stk.push(i);
    }

    for(int i = 0 ; i < N ; i ++) cout << ans[i] << ' ';
    return 0;
}