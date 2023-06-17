#include<bits/stdc++.h>
using namespace std;

string formula;
int N;
double nums[30];
stack<double> stk;

int main(){
    cin >> N;
    cin >> formula;
    for(int i = 0 ; i < N ; i ++) cin >> nums[i];

    for(char c: formula){
        if(c >= 'A' && c <= 'Z') stk.push(nums[c-'A']);
        else{
            double n1 = stk.top() ; stk.pop();
            double n2 = stk.top() ; stk.pop();
            if(c == '*') stk.push(n1*n2);
            else if (c == '/') stk.push(n2/n1);
            else if (c == '+') stk.push(n1+n2);
            else if (c == '-') stk.push(n2-n1);
        }
    }
    
    printf("%.2f", stk.top());


    return 0;
}