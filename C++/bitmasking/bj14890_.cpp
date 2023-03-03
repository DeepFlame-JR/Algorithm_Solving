#include<bits/stdc++.h>
using namespace std;

int N, K, words[51];
string s;

int go(int index, int k, int mask){
    if(k < 0) return 0;
    if(index == 26){
        int cnt = 0;
        for(int word:words){
            if(word && (word & mask) == word) cnt ++; // if문에 괄호 조심
        }
        return cnt;
    }
    
    int ret = go(index+1, k-1, mask | (1<<index)); // 배움
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') { // anta tica는 안 배울 수 없음
        ret = max(ret, go(index+1, k, mask)); // 안 배움
    }
    return ret;
}

int main(){
    cin >> N >> K;
    for(int n = 0 ; n < N ; n ++){
        cin >> s;
        for(char c : s) words[n] |= (1 << c-'a');
    }

    if(K < 5){
        cout << 0;
        return 0;
    }

    cout << go(0, K, 0);

    return 0;
}