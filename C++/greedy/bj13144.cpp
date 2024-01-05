#include <iostream>
using namespace std;

typedef long long ll;
ll N, l, r, result, arr[100009], cnt[100009];

int main() {
    cin >> N;
    for(int i = 0 ;i < N ; i ++) cin >> arr[i];
    
    cnt[arr[0]] ++;
    while(r < N){
        if(cnt[arr[r]] > 1){
            result += r-l;
            cnt[arr[l]]--;
            l++;
        }else{
            r++;
            cnt[arr[r]]++;
        }
    }
    result += (r-l)*(r-l+1)/2;
    cout << result << '\n';

    return 0;
}