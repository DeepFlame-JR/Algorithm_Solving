#include<bits/stdc++.h>
using namespace std;

int N, ans=-987654321;
string s;
vector<int> nums;
vector<char> opers;

int oper(int a, char c, int b){
    if(c == '+') return a+b;
    else if(c == '-') return a-b;
    else if(c == '*') return a*b;
}

void dfs(int idx, int accum){
    if(idx == nums.size()-1){
        ans = max(ans, accum);
        return;
    }

    dfs(idx+1, oper(accum, opers[idx], nums[idx+1])); 
    if(idx+2 < nums.size()){
        int temp = oper(nums[idx+1], opers[idx+1], nums[idx+2]);
        dfs(idx+2, oper(accum, opers[idx], temp));
    }
}

int main(){
    cin >> N;
    cin >> s;
    for(int i = 0 ; i < N ; i ++){
        if(i%2 == 0) nums.push_back(s[i]-'0');
        else opers.push_back(s[i]);
    } 

    dfs(0, nums[0]);

    cout << ans;
    return 0;
}