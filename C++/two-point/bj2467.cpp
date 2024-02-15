#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, arr[100001];
pair<ll, ll> result;

int main(){
    cin >> N;
    for(int i = 0 ;i < N ; i ++) cin >> arr[i];

    int left = 0;
    int right = N-1;
    ll minimum = abs(arr[left]+arr[right])+1;

    while(left < right){
        ll local_sum = arr[left]+arr[right];

        if(abs(local_sum) < minimum){
            minimum = abs(local_sum);
            result = {arr[left], arr[right]};
        }

        if(local_sum < 0){
            left ++;
        }
        else if(local_sum > 0){
            right --;
        }
        else{
            break;
        }
    }

    cout << result.first << ' ' << result.second << '\n';

    return 0;
}