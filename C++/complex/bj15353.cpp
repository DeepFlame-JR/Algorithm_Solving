#include<bits/stdc++.h>
using namespace std;

string N, M, L, S;

int main(){
    scanf("%s %s", N, M);

    int n = N.length();
    int m = M.length();
    int diff =0;
    if(n >= m){
        L = N ; S = M ; diff = n-m;
    }
    else{
        L = M ; S = N ; diff = m-n;
    }

    int prev = 0;
    for(int i = 0 ; i < max(n, m) ; i ++){
        int a = int(L[i]);
        int b = (i<diff) ? 0 : int(M[i-diff]);

        int t = a+b;
        
    }


}