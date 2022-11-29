#include<bits/stdc++.h>
using namespace std;

int main(){

    // auto
    vector<pair<int, int>> v;

    for(int i = 1; i <= 5; i++){
        v.push_back({i, i});
    }
    // pair <int, int>와 같은 복잡한 자료형을 짧게 선언할 수 있음
    for(auto it : v){
        cout << it.first << " : " << it.second << '\n';
    }
    //


    // 타입 변환
    double ret = 2.12345;
    int n = 2;
    int a = (int) round(ret / double(n));

    return 0;
}
