#include<bits/stdc++.h>
using namespace std;

// unsigned int: 0~4294967295 => 10자리
// unsigned long long: 0~9223372036854775807 => 20자리
typedef unsigned long long ull;
const int max_n = 50000;
ull A[max_n], B[max_n], ans[max_n], division=1000000000, up, n;
string A_str, B_str;


void setList(string str, ull l[]){
    int i = 0, decimal = 1, l_index = 0;
    int str_length = str.length();

    while(i < str_length){
        l[l_index] += (str[str_length-1-i] - '0') * decimal;
        decimal *= 10;
        i++;
        if(i%9 == 0){
            decimal = 1;
            l_index += 1;
        } 
    }
}


int main(){
    cin >> A_str >> B_str;
    setList(A_str, A);
    setList(B_str, B);

    up = 0;
    for(int i = 0 ; i < max_n ; i++){
        if(A[i] == 0) break;
        for(int j = 0 ; j < max_n ; j++){
            if(B[j] == 0 && up == 0) break;
            n = A[i]*B[j];
            ans[i+j] += n + up;
            up = ans[i+j] / division;
            ans[i+j] %= division;
        }
    }

    string temp="";
    for(int i = 0 ; i < max_n ; i++){
        if(ans[i] == 0) break;
        temp = to_string(ans[i]) + temp;
    }
    cout << temp;

    return 0;
}