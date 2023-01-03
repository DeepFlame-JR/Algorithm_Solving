#include<bits/stdc++.h>
using namespace std;

/*
100 글자? long long = 10^18 >> 커버 불가능
ASCII 코드를 활용하자!
*/

vector<string> ans;
int N;
string str, temp;

void push_temp(){
    while(true){
        if(temp.size() > 0 && temp.front()=='0') temp.erase(temp.begin());
        else break;
    }
    if(temp.size()==0) temp = "0";

    ans.push_back(temp);
    temp="";
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a<b; // 문자열의 경우 첫번째 수부터 하나씩 ASCII를 비교한다.
    return a.size()<b.size();
}

int main(){
    cin >> N;

    for(int n = 0 ; n < N ; n ++){
        cin >> str;
        temp = "";
        for(char c:str){
            if(c < 65){  // 65 외우세요. ASCII가 65보다 작으면 숫자입니다.
                temp += c;
            }
            else if (temp != "") push_temp();
        }

        if(temp != "") push_temp();
    }

    sort(ans.begin(), ans.end(), cmp);
    for(string a : ans){    
        cout << a <<'\n';
    }

    return 0;
}