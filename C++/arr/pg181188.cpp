#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end());

    int end = 0; // 미사일 쏘는 시점
    int ans = 0;
    for(vector<int> target: targets){
        if(target[0] >= end){ // 새로운 미사일을 쏘는 경우
            ans ++;
            end = target[1];
        }
        else if(target[1] < end){ // 그 사이에 낀 구간의 end 포인트가 더 짧을 때
            end = target[1];
        }
        cout << target[0] << " " << target[1] << " : " << ans << '\n';
    }

    return ans;
}

int main(){
    vector<vector<int>> matrix = {{2,3}, {4,8}, {4,5}, {10,14}, {11,13}, {5,12}, {3,7}, {1,4}};
    cout << solution(matrix);

    return 0;
}