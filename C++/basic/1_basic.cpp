#include <bits/stdc++.h>
using namespace std;

int I;
double D;
char C;
string S;

void input_output(){
    scanf("%d %lf %c", &I, &D, &C);
    printf("%d\n", I);
    printf("%lf\n", D);
    printf("%c\n", C);

    // 한 줄 받기
    getline(cin, S);
    cout << S << '\n';
}


void string_util(){
    string sentence = "love is";
    sentence += " pain!";  // love is pain!

    sentence.pop_back();  // love is pain
    cout << char(* sentence.begin()) << '\n';      // l
    cout << char(* (sentence.end() - 1)) << '\n';  // n

    sentence.insert(0, "test ");  // test love is pain
    sentence.erase(0, 5); // love is pain

    auto it = sentence.find("love");
    if (it != string::npos){
        cout << "Included" << '\n';
    }

    reverse(sentence.begin(), sentence.end());
    cout << sentence << '\n';  // niap si evol

    // 문자열을 숫자인지 확인 (숫자라면 숫자, 문자라면 0 반환)
    string s = "1";
    atoi(s.c_str());
}


vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}


int main()
{
    // input_output();
    string_util();
    return 0;
}