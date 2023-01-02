#include<bits/stdc++.h>
using namespace std;

int N, M, cloud;
string str;

int main(){
    cin >> N >> M;
    for(int n = 0 ; n < N ; n ++){
        cin >> str;
        cloud = -1;
        for(char c : str){
            if(c == '.'){
                if(cloud == -1) cout << cloud << ' ';
                else cout << ++cloud << ' ';
            }
            else{
                cloud = 0;
                cout << cloud << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}