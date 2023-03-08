#include<bits/stdc++.h>
using namespace std;

int N, n;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    int S = 0;
    for(int i = 0 ; i < N ; i ++){
        cin >> s;
        if(s == "all") S = (1<<21)-1;
        else if(s == "empty") S = 0;
        else{
            cin >> n;
            if(s == "add") S |= (1<<n);
            else if(s == "remove") S &= ~(1<<n);
            else if(s == "check"){
                int temp = 0;
                if(S & (1<<n)) temp = 1;
                cout << temp << '\n';
            }
            else if(s == "toggle") S ^= (1<<n);
        }
    }

    return 0;
}