#include<bits/stdc++.h>
using namespace std;

int K, tree[10000], cnt, accum, height;
vector<int> ans[10];

void go(int s, int e, int h){
    int mid = (s+e)/2;
    ans[h].push_back(tree[mid]);

    if(s==e) return;
    go(s, mid-1, h+1);
    go(mid+1, e, h+1);
}

int main(){
    cin >> K;
    int length = pow(2, K);
    for(int i = 1 ; i <= length-1 ; i++){
        cin >> tree[i];
    }

    go(1, length-1, 0);

    for(int k = 0 ; k < K ; k ++){
        for(int i = 0 ; i < ans[k].size() ; i++){
            cout << ans[k][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}