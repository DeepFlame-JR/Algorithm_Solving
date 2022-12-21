#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos=0;
    string token="";
    while((pos=input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main(){
    string a = "love is";
    a += " pain!";

    a.pop_back();   // 문자열의 끝을 지움
    cout << a << " : " << a.size() << "\n"; // 문자열의 사이즈
    cout << char(* a.begin()) << '\n';      // 첫번째 요소를 가리키는 Interator 반환
    cout << char(* (a.end() - 1)) << '\n';  // 마지막 요소를 가리키는 Interator 반환

    // 특정 위치에 문자열 삽입
    a.insert(0, "test "); 
    cout << a << " : " << a.size() << "\n";

    // 특정 위치에 크기만큼 지움
    a.erase(0, 5);
    cout << a << " : " << a.size() << "\n";

    // 문자열을 찾아서 반환 (반환하지 못하면 string::npos 반환)
    auto it = a.find("love");
    if (it != string::npos){
        cout << "포함되어 있다." << '\n';
    }
    cout << it << '\n';
    cout << string::npos << '\n';

    reverse(a.begin(), a.end());

    // 특정 위치에서 크기만큼 문자열 추출
    cout << a.substr(5, 2) << '\n';
    return 0;
}
