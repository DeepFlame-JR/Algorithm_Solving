#include<bits/stdc++.h>
using namespace std;

const int max_n = 987654321;
int N, ans_total=max_n, rule[4];
int info[16][5];
vector<vector<int>> ans_v;

int main(){
    cin >> N;
    for(int i = 0 ; i < 4 ; i++) cin >> rule[i];

    for(int n = 0 ; n < N ; n ++){
        for(int i = 0 ; i < 5 ; i ++) cin >> info[n][i];
    }

    for(int n = 0 ; n < (1<<N) ; n ++){
        int temp[4] = {0,0,0,0};
        int total = 0;
        vector<int> temp_v;
        for(int i = 0 ; i < N ; i++){
            if(n & (1<<i)){
                temp_v.push_back(i);
                for(int j = 0 ; j < 4 ; j++){
                    temp[j] += info[i][j];
                }
                total += info[i][4];
            }
        }

        bool plag = true;
        for(int j = 0 ; j < 4 ; j++){
            if(rule[j] > temp[j]){
                plag = false;
                break;
            }
        }

        if(plag){
            if(total < ans_total){
                ans_v.clear();
                ans_v.push_back(temp_v);
                ans_total = total;
            }
            else if(total == ans_total){
                ans_v.push_back(temp_v);
            }
        }
    }

    if(ans_total == max_n) cout << -1;
    else{
        sort(ans_v.begin(), ans_v.end());
        cout << ans_total << '\n' ;
        
        for(int a : ans_v[0]) cout << a+1 << ' ';
    }

    return 0;
}