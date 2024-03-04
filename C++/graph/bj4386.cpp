#include<bits/stdc++.h>
using namespace std;

const int max_n = 101;
int N, root[max_n];
float XY[max_n][2], result;

struct Node{
    float weight; int a, b;
    Node(float weight, int a, int b): weight(weight), a(a), b(b) { }
};

struct Cmp{
    bool operator()(Node a, Node b){
        return a.weight > b.weight;
    }
};
priority_queue<Node, vector<Node>, Cmp> pq;

int Find(int a){
    if(root[a] == a) return a;
    root[a] = Find(root[a]);
    return root[a];
}

void Union(int a, int b){
    int a_root = Find(a);
    int b_root = Find(b);
    root[a_root] = b_root;
}


int main(){
    cin >> N;

    for(int i = 1 ;i <= N ; i ++){
        cin >> XY[i][0] >> XY[i][1];
        root[i] = i;
    }

    for(int i = 1 ;i <= N ; i ++){
        for(int j = i+1 ;j <= N ; j ++){
            float dist = sqrt(pow((XY[i][0]-XY[j][0]),2) + pow((XY[i][1]-XY[j][1]),2));
            pq.push(Node(dist, i, j));
        }
    }

    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
        int a_root = Find(cur.a);
        int b_root = Find(cur.b);
        if (a_root == b_root) continue;

        result += cur.weight;
        Union(cur.a, cur.b);
    }

    cout << result <<'\n';
    return 0;
}