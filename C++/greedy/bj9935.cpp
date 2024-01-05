#include<bits/stdc++.h>
using namespace std;

string sentence, result;
string bomb;

int main(){
    cin >> sentence;
    cin >> bomb;

    for(char c: sentence){
        result += c;
        if(result.length() >= bomb.length()){
            if(result.substr(result.length()-bomb.length(), bomb.length()) == bomb){
                result.erase(result.length()-bomb.length(), bomb.length());
            }
        }
    }
    
    if(result == "") cout << "FRULA" << '\n';
    else cout << result << '\n';

    return 0;
}