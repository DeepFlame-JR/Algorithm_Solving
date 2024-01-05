#include<bits/stdc++.h>
using namespace std;

int N;
double score, result[7];
priority_queue<double> pq;

int main(){
    cin >> N;

    for(int n = 0 ; n < N ;n ++){
        cin >> score;
        pq.push(score);
        if(pq.size() > 7) pq.pop();
    }

    for(int i = 0 ; i < 7 ; i ++){
        result[7-i-1] = pq.top(); pq.pop();
    }

    for(int i = 0 ; i < 7 ; i ++){
        printf("%.3lf\n", result[i]);
    }

    return 0;
}