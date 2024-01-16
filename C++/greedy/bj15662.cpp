#include<bits/stdc++.h>
using namespace std;

int N, K, Map[1001][8], seq, dir, result, i, _dir;
string line;
queue<pair<int,int>> q;

void rotate_clock(int target){
    int temp = Map[target][7];
    for(int i = 7 ; i >= 1 ; i --){
        Map[target][i] = Map[target][i-1];
    }
    Map[target][0] = temp;
}

void rotate_clock_reverse(int target){
    int temp = Map[target][0];
    for(int i = 0 ; i < 7 ; i ++){
        Map[target][i] = Map[target][i+1];
    }
    Map[target][7] = temp;
}

void rotate(int target, int dir){
    if(dir == 1) rotate_clock(target);
    else rotate_clock_reverse(target);
}


int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> line;
        for(int j = 0 ; j < 8 ; j ++){
            Map[i][j] = line[j]-48;
        }
    }
    cin >> K;
    for(int k = 0 ; k < K ; k ++){
        cin >> seq >> dir;
        seq--;
        q.push({seq,dir});

        i = seq;
        _dir = dir;
        while(i < N-1){
            if(Map[i][2]+Map[i+1][6] != 1) break;
            i++;
            _dir *= -1;
            q.push({i, _dir});
        }

        i = seq;
        _dir = dir;
        while(i > 0){
            if(Map[i][6]+Map[i-1][2] != 1) break;

            i--;
            _dir *= -1;
            q.push({i, _dir});
        }

        while(!q.empty()){
            seq = q.front().first;
            dir = q.front().second;
            q.pop();

            rotate(seq, dir);
        }
    }

    for(int i = 0 ; i < N ; i ++){
        result += Map[i][0];
    }
    cout << result << '\n';


    return 0;
}