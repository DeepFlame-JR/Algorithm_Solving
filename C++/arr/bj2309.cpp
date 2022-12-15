#include<bits/stdc++.h>
using namespace std;


int Height[9], Sum, a, b;

void find(int sub){
    for(int i = 0; i < 9 ; i ++){
        for(int j = 0 ;j < 9 ; j++){
            if(i != j && Height[i] + Height[j] == sub){
                a = i; b = j;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0 ; i < 9 ; i ++){
        cin >> Height[i];
        Sum += Height[i];
    }

    sort(Height, Height+9);
    find(Sum-100);

    for(int i = 0 ;i < 9 ;i ++){
        if(i == a || i == b) continue;
        cout << Height[i] << '\n';
    }
    
    return 0;
}