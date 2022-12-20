#include<bits/stdc++.h>
using namespace std;

int N;
string name;
vector<char> ans;

int main(){
    cin >> N;
    map<char, int> nameCounter;

    for(int i=0; i < N; i++){
        cin >> name;
        char first = name[0];

        if(nameCounter.find(first) == nameCounter.end()) nameCounter[first] = 1;
        else nameCounter[first] += 1;

        if(nameCounter[first]==5) ans.push_back(first);
    }

    sort(ans.begin(), ans.end());
    if(ans.size() == 0) {
        cout << "PREDAJA";
    }
    else{
        for(char a:ans) cout << a;
    } 
    cout << '\n';

    return 0;
}