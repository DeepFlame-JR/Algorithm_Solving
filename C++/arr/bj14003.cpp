#include<bits/stdc++.h>
using namespace std;

const int max_n = 1000001;
int N, arr[max_n], idx_list[max_n];
vector<int> LIS; // 최장증가부분수열

int main(){
    cin >> N; 
    for(int i = 0 ;i < N ; i++) cin >> arr[i];

    for(int i = 0 ; i < N ; i++){
        int item = arr[i];
        if(LIS.size() == 0 || LIS[LIS.size()-1] < item){
            LIS.push_back(item);
            idx_list[i] = LIS.size()-1;
        }
        else{
            int left = 0;
            int right = LIS.size()-1;
            while(left < right){
                int mid = (left+right)/2;

                if(LIS[mid] >= arr[i]) right = mid;
                else left = mid+1;
            }
            LIS[left]=item;
            idx_list[i] = left;
        }
    }

    cout << LIS.size() << '\n';

    vector<int> result;
    int idx = LIS.size()-1;
    for(int i = N-1 ; i >= 0 ; i --){
        if(idx_list[i] == idx){
            idx --;
            result.push_back(arr[i]);
        }
    }

    for(int i = LIS.size()-1 ; i >= 0 ; i--){
        cout << result[i] << ' ';
    }

    return 0;
}