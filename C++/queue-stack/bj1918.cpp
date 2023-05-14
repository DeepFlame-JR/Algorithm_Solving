#include<bits/stdc++.h>
using namespace std;

string formula, ans;
stack<char> stk;

// void append(char *array, char c){
//     printf("append start");
//     size_t len = std::strlen(array);
//     printf("%d", len);
//     array[len] = c;
//     array[len+1] = '\0';
//     printf("append!");
// }

int main(){
    cin >> formula;

    for(char& c : formula){
        if(c>='A' && c<='Z')ans += c;
        else{ // 수식이다 +, -, *, /, (, )
            if(c == '*' || c == '/'){
                while(!stk.empty()){
                    if(stk.top() == '*' || stk.top() == '/'){ // 우선순위가 같거나 낮은 *, / 계산
                        ans += stk.top(); stk.pop();
                        continue;
                    }
                    break;
                }
                stk.push(c);
            }
            else if(c == '+' || c == '-'){
                while(!stk.empty()){
                    if(stk.top() != '('){ // 우선순위가 같거나 낮은 *, /, +, - 계산
                        ans += stk.top(); stk.pop();
                        continue;
                    }
                    break;
                }
                stk.push(c);
            }
            else if(c == ')'){
                while(!stk.empty()){
                    char top = stk.top(); stk.pop();
                    if(top == '(') break;
                    ans += top;
                }
            }
            else{
                stk.push(c);
            }
        }
    }

    while(!stk.empty()){
        ans += stk.top(); stk.pop();
    }

    cout << ans;

    return 0;
}