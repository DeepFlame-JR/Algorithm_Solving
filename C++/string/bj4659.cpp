#include<bits/stdc++.h>
using namespace std;

string str;
vector<char> mos = {'a','e','i','o','u'};
int ja_cnt, mo_cnt;
bool mo_flag, break_flag;
char prev_ch;

int main(){
    while(true){
        cin >> str;

        if(str == "end") break;

        ja_cnt = 0; mo_cnt = 0; mo_flag = false; prev_ch = 'A'; break_flag=false;

        for(char c:str){
            if( find(mos.begin(), mos.end(), c) == mos.end() ) ja_cnt += 1, mo_cnt = 0;
            else mo_cnt += 1, ja_cnt = 0, mo_flag = true;

            if(ja_cnt ==3 || mo_cnt == 3){
                break_flag = true;
                break;
            }           

            if(prev_ch == c && c != 'e' && c != 'o'){
                break_flag = true;
                break;
            }

            prev_ch = c;
        }

        if(!break_flag){
            if(mo_flag) cout << '<' << str << "> is acceptable." << '\n';
            else cout << '<' << str << "> is not acceptable." << '\n';
        }
        else{
            cout << '<' << str << "> is not acceptable." << '\n';
        }

    }

    return 0;
}