// 소수의 연속합
#include<bits/stdc++.h>
using namespace std;

int N, l, r, sum, result;
vector<int> sosu;

int main(){
    cin >> N;

    // 소수 구하기
    bool isPrime[N+1];
    for(int i = 0 ; i <= N ; i ++) isPrime[i] = true;

    for(int i = 2 ; i <= N ; i ++){
        if(isPrime[i]){
            sosu.push_back(i);
            for(int j = 2*i ; j <= N ; j += i){
                isPrime[j] = false;
            }
        }
    }

    l = 0; r = 0; sum = 2;
    while(r < sosu.size()){
        if(sum == N) {
            result ++;
            sum += sosu[++r];
        }
        else if(sum < N) {
            sum += sosu[++r];
        }
        else if(sum > N){
            sum -= sosu[l++];
        }
    }
    cout << result << '\n';
    return 0;

}