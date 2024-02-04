#include<bits/stdc++.h>
using namespace std;

string word;
int arr[30];

int main(){
    cin >> word;
    
    int max_count = 0;
    for(char ch : word){
        int i = int(ch);
        if(97<=i && i <= 122) i -= 97;
        else i -= 65;
        arr[i] +=1 ;
        
        max_count = max(max_count, arr[i]);
    }

    int idx = -1;
    for(int i = 0 ; i < 30 ; i ++){
        if(arr[i] == max_count){
            if(idx != -1){
                cout << '?' << '\n';
                return 0;
            }
            idx = i;
        }
    }

    cout << char(idx+65) << '\n';
    return 0;
}