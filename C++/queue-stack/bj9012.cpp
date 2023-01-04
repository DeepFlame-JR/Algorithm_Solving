#include<bits/stdc++.h>
using namespace std;

int N;
string str;

bool check(string s){
    stack<int> stk;
    for(char c:s){
        if(c == '(') stk.push(c);
        else if(stk.empty()) return false;
        else stk.pop();
    }
    return stk.empty();
}

int main(){
    cin >> N;

    for(int i = 0 ; i < N; i++){
        cin >> str;

        if(check(str)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}