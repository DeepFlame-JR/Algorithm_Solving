#include<bits/stdc++.h>
using namespace std;

int N, t, ans;
stack<char> stk;
string str;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    for(int n = 0; n < N ; n ++ ){
        cin >> str;
        
        for(char ch:str){
            if(stk.empty() || stk.top() != ch) stk.push(ch);
            else stk.pop();
        }
        
        if(stk.size() == 0) ans ++;
        while(!stk.empty()) stk.pop();
    }
    
    cout << ans << '\n';

    return 0;
}