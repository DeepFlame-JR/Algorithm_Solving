#include<bits/stdc++.h>
using namespace std;

const int max_n = 100001;
int N, InOrder[max_n], PreOrder[max_n], PostOrder[max_n], Index[max_n];

void dfs(int inOrderStart, int inOrderEnd, int PostOrderStart, int PostOrderEnd){
    if(inOrderStart > inOrderEnd || PostOrderStart > PostOrderEnd) return;

    int root = PostOrder[PostOrderEnd];
    cout << root << ' ';
    int root_idx = Index[root];
    int left_size = root_idx-inOrderStart;
    
    dfs(inOrderStart, root_idx-1, PostOrderStart, PostOrderStart+left_size-1);
    dfs(root_idx+1, inOrderEnd, PostOrderStart+left_size, PostOrderEnd-1);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i ++) {
        cin >> InOrder[i];
        Index[InOrder[i]] = i;
    }
    for(int i = 0 ; i < N ; i ++) cin >> PostOrder[i];

    dfs(0, N-1, 0, N-1);
    return 0;
}