#include<bits/stdc++.h>
using namespace std;

int N, a, b, result;
vector<pair<int, int>> arr;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    result = arr[0].first + arr[0].second;
    for(int i = 1 ; i < N ; i ++){
        if(result > arr[i].first){  // 늦게 끝난 경우
            result += arr[i].second;
        }
        else{
            result = arr[i].first + arr[i].second;
        }
    }
    cout << result << '\n';

    return 0;
}