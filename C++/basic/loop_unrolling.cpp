#include<bits/stdc++.h>
using namespace std;

// 참고: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=acwboy&logNo=50083036889

const int SIZE = 100;
int X[SIZE], Y[SIZE];

// 1. for문에서 i값과 size를 비교하고 조건이 맞다면 1증가 (100)
// 2. sum += x[i] + y[i] 실행 (100)
// 총 200번 수행
int normal_add(int x[], int y[]){
    int sum = 0;
    for(int i = 0 ; i < SIZE ; i++){
        sum += x[i] + y[i];
    }
    
    return sum;
}

// 1. for문에서 i값과 size를 비교하고 조건이 맞다면 8만큼 증가 (12)
// 2~9. sum += x[i] + y[i] ~ sum += x[i+7] + y[i+7] 실행 (96)
// 108+8(나머지) 회 실행
// 배수를 너무 늘린다면 성능이 하락 > 루프 내 코드가 많을수록 코드 사이즈가 증가되는데 이는 오버헤드를 발생시킴

int unroll_add(int x[], int y[]){
    int sum = 0 ;
    int i = 0;
    int ssize = (SIZE/8)*8; // 8번씩 할 것으로 8의 배수로 만듬

    for(i = 0 ; i < ssize ; i+=8 ){
        sum += x[i] + y[i];
        sum += x[i+1] + y[i+1];
        sum += x[i+2] + y[i+2];
        sum += x[i+3] + y[i+3];
        sum += x[i+4] + y[i+4];
        sum += x[i+5] + y[i+5];
        sum += x[i+6] + y[i+6];
        sum += x[i+7] + y[i+7];
    }

    for(i; i < SIZE ; i++){ // 나머지 부분
        sum += x[i]+y[i];
    }
    return sum;
}

int main(){
    fill(X, X+SIZE, 1);
    fill(Y, Y+SIZE, 2);

    cout << normal_add(X, Y) << '\n';
    cout << unroll_add(X, Y) << '\n';

    return 0;
}