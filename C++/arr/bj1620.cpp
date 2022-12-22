#include<bits/stdc++.h>
using namespace std;

int N, M;
string arr[100004], temp;
map<string, int> indexer;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    for(int i = 1 ; i <= N ;i ++){
        cin >> temp;
        arr[i] = temp;
        indexer[temp] = i;
    }

    for(int i = 0; i < M; i ++){
        cin >> temp;
        if(atoi(temp.c_str()) == 0){
            cout << indexer[temp] << '\n';
        }
        else{
            cout << arr[atoi(temp.c_str())] << '\n';
        }
    }

    return 0;
}