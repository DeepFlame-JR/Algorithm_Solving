#include <bits/stdc++.h>

using namespace std;
string a;
typedef int i;
#define PI 3.14159
#define loop(x,n) for(int i=0; i <n; i++)

int main()
{
    // 선언 후 출력 (cin, cout)
    cin >> a;  
    cout << a << "\n";

    // typedef를 통한 자료형 별칭 사용
    i a=1;

    // define을 통한 매크로 활용
    cout << PI << "\n";
    loop(i, 10){
        cout << i << "\n";
    }

    return 0;
}