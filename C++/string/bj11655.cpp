#include<bits/stdc++.h>
using namespace std;

string str;

int main(){
    getline(cin, str);

    for(char s: str){
        if(isupper(s)){
            if(s+13 > 90) cout << char(s-13);
            else cout << char(s+13);
        }
        else if(islower(s)){
            if(s+13 > 122) cout << char(s-13);
            else cout << char(s+13);
        }
        else{
            cout << s;
        }
    }

    cout << '\n';    
    return 0;
}