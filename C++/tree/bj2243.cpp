// Segment Tree

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int max_n = 1000001;
int N, c;
ll a, b, cnt, arr[max_n], tree[4*max_n];


/*
node: 트리 내에 노드 번호
node의 값은 s~e의 합을 의미함
목표는 idx에 해당하는 값을 변경하고 싶음
*/
void update(int node, int s, int e, int idx, ll value){ 
    if(idx < s || idx > e) return;
    if(s == e){
        tree[node] = value;
        return;
    } 
    
    int mid = (s+e)/2;
    update(2*node, s, mid, idx, value);
    update(2*node+1, mid+1, e, idx, value);
    tree[node] = tree[2*node] + tree[2*node+1];
}

/*
k번째로 맛있는 사탕 찾기
*/
int find(int node, int s, int e, int k){
    if(s == e) return s;

    int mid = (s+e)/2;
    if(tree[2*node] >= k) return find(2*node, s, mid, k); // 왼쪽에 K보다 개수가 많다면 맛있는 사탕이 왼쪽에 있다는 뜻
    else return find(2*node+1, mid+1, e, k-tree[2*node]); // 만약 아니라면 오른쪽에서 K-(왼쪽 개수)의 사탕을 찾아야 함
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int n = 0 ; n < N ; n ++){
        cin >> c;
        if(c == 1){
            cin >> b;
            a = find(1, 1, max_n, b);
            arr[a]--;
            update(1, 1, max_n, a, arr[a]);
            cout << a << '\n';
        }
        else{
            cin >> a >> b;
            arr[a] += b;
            update(1, 1, max_n, a, arr[a]);
        }
    }
    

    return 0;
}