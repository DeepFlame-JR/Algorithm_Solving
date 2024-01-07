#include<bits/stdc++.h>
using namespace std;


int N, target, l, r, result, sum;

int main(){
    cin >> N;

    int arr[N];
    for(int i = 0 ; i < N ; i ++) cin >> arr[i];
    cin >> target;

    sort(arr, arr+N);
    l = 0; r = N-1;
    while(l < r){
        sum = arr[l]+arr[r];
        if(sum == target){
            result ++;
            r--;
        }
        else if(sum > target){
            r--;
        }
        else{
            l++;
        }
    }

    cout << result << '\n';

    return 0;
}