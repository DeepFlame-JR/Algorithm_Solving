#include <bits/stdc++.h>
using namespace std;
string a1, b1;
int a2;
double b2;
char c2;
string s;

int main(){
    // 개행 문자로 두 변수가 받아짐
    cin >> a1 >> b1;
    cout << a1 << "\n";
    cout << b1 << "\n";

    // 매개변수로 받을 자료형을 정의함 
    // d < int
    // c < char
    // s < string 
    // lf < double
    // ld < long long    
    scanf("%d %lf %c", &a2, &b2, &c2);
    printf("%d\n", a2);
    printf("%lf\n", b2);
    printf("%c\n", c2);


    // 한 줄 받기
    getline(cin, s);
    cout << s << "\n";

    // 여러 줄 받기
    string bufferflush;
    getline(cin, s);
    for(int i = 0; i < 1 ; i++){
        getline(cin, s);
    }
    cout << s << "\n";

    return 0;
}