#include<bits/stdc++.h>

using namespace std;

void print_vec(vector<int> v){
    for(int a:v) cout << a << " ";
    cout << "\n";
}

void Rotate(){
    vector<int> a {1,2,3,4,5};
    // 3 4 5 1 2 (앞에 값을 뒤로)
    rotate(a.begin(), a.begin()+2, a.end());
    print_vec(a);
    
    vector<int> b {1,2,3,4,5};
    // 4 5 1 2 3 (뒤에 값을 앞으로)
    rotate(b.begin(), b.begin()+b.size()-2, b.end());
    print_vec(b);
}

void RotateLeft90(vector<vector<int>> &v2){
    int N = v2.size();
    vector<vector<int>> temp(N, vector<int>(N,0));

    for(int i= 0; i < N; i++){
        for(int j=0; j < N; j++){
            temp[i][j] = v2[j][N-i-1];
        }
    }

    v2 = temp;
    for(int i= 0; i < N; i++){
        for(int j=0; j < N; j++){
            cout << v2[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    Rotate();
    vector<vector<int>> v2 {{1,2,3},{4,5,6},{7,8,9}};
    RotateLeft90(v2);
}