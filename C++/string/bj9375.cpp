#include<bits/stdc++.h>
using namespace std;

int T, N, ans;
map<string, set<string>> clothes;
string name, kind;

int main(){
    cin >> T;

    for(int t = 0 ; t < T; t++){
        clothes.clear();
        cin >> N;
        for(int n = 0 ; n < N; n++){
            cin >> name >> kind;
            if(clothes.find(kind) == clothes.end()){
                clothes[kind] = set<string>{name};
            }
            else{
                clothes[kind].insert(name);
            }
        }

        ans = 1;
        for(auto it : clothes){
            ans *= it.second.size()+1;
        }
        cout << ans-1 << '\n';
    }

    return 0;
}