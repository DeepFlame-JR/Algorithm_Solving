#include<bits/stdc++.h>
using namespace std;

int N;
string pattern, f, b, temp;

int main(){
    cin >> N;
    cin >> pattern;

    int center = pattern.find('*');
    f = pattern.substr(0, center);
    b = pattern.substr(center+1);

    for(int i = 0; i < N ; i ++){
        cin >> temp;

        if(temp.length() < pattern.length()-1) cout << "NE" << '\n';
        else if(f == temp.substr(0, f.length()) && b == temp.substr(temp.length()-b.length())) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }

    return 0;
}