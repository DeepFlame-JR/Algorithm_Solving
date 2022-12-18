#include<bits/stdc++.h>
using namespace std;

int alpha_arr[26];
string word;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> word;

    for(char ch : word){
        alpha_arr[ch - 'a'] += 1;
    }

    for(int cnt : alpha_arr){
        cout << cnt << ' ';
    }
    cout << '\n';
}