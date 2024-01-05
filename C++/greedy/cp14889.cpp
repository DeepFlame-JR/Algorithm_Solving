// 비트 마스킹

#include<bits/stdc++.h>
using namespace std;

int N, Map[21][21];
int result = 987654321;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            cin >> Map[i][j];
        }
    }

    for(int i = 1 ; i < (1 << N) ; i ++){
        int masking = 0;
        for(int j = 0 ; j < N ; j++){
            if((i & (1<<j)) != 0) masking++;
        }
        if(masking != N/2) continue;

        vector<int> start_team;
        vector<int> link_team;
        for(int j = 0 ; j < N ; j++){
            if((i & (1<<j)) != 0) start_team.push_back(j);
            else link_team.push_back(j);
        }

        int start_sum = 0;
        int link_sum = 0;
        for(int j = 0 ; j < N/2 ; j++){
            for(int k = 0 ; k < N/2 ; k++){
                if(j == k) continue;
                start_sum += Map[start_team[j]][start_team[k]];
                link_sum += Map[link_team[j]][link_team[k]];
            }
        }
        result = min(result, abs(start_sum-link_sum));
    }
    
    cout << result << '\n';
    
    return 0;
}
