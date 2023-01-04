#include<bits/stdc++.h>
using namespace std;

int N, rm, ans, parent, root;
map<int, vector<int>> tree;

void go(int n){
    int cnt = 0;
    for(int child : tree[n]){
        if(child != rm){
            cnt ++;
            go(child);
        }
    }

    if(cnt == 0) ans ++;
}


int main(){ 
    cin >> N;

    for(int i = 0 ; i < N ; i ++){
        cin >> parent;
        if(parent == -1) root = i;
        tree[parent].push_back(i);
    }

    cin >> rm;
    if(root == rm){
        cout << 0 << '\n';
        return 0;
    }

    go(root);
    cout << ans << '\n';

    return 0;
}