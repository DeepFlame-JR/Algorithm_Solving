#include<bits/stdc++.h>
using namespace std;

string str, ans, t;
int counter[26], odd_count;
char odd_c;

int main(){
    cin >> str;
    for(char c : str){
        counter[c-'A'] += 1;
    }

    for(int i=0; i<26; i++){
        if(counter[i]%2 == 1){
            if(str.length()%2==1 && odd_count==0){
                odd_count += 1;
                odd_c = (char)(i+'A');
            }
            else{
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }

        for(int c=0; c<counter[i]/2; c++){
            t += (char)(i+'A');
        }
    }
    ans += t;
    if(odd_count == 1) ans += odd_c;
    reverse(t.begin(), t.end());
    ans += t;

    cout << ans << '\n';
    return 0;
}