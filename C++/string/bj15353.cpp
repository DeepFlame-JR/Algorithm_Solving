#include<bits/stdc++.h>
using namespace std;

char a[10003], b[10003], ans[10003];
int al, bl, p, n1, n2, idx;

int main(){
    scanf("%s %s", a, b);
    al = strlen(a); bl = strlen(b);
    while(al||bl||p){
        n1 = 0 ; n2 = 0;
        if(al) n1 = (a[--al]-'0');
        if(bl) n2 = (b[--bl]-'0');
        ans[idx++]=(n1+n2+p)%10;

        if((n1+n2+p)/10 > 0) p = 1;
        else p = 0;
    }

    while(idx){
        printf("%d", ans[idx-- - 1]);
    }

    return 0;
}