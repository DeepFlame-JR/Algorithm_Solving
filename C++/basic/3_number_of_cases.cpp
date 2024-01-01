#include<bits/stdc++.h>
using namespace std;


int arr[] = {3,1,2};
void permutation(){
    sort(arr, arr+3);
    do{
        for(int i:arr) cout << i << " ";
        cout << '\n';
    }while(next_permutation(arr, arr+3));
}

void makePermutation(int n, int r, int depth){
    if(depth == r){
        for(int i = 0 ; i < r ; i ++)
            printf("%d ", arr[i]);
        printf("\n");
        return;    
    }

    for(int i = depth ; i < n ; i ++){ // depth와 나머지 값들 간에 스왑
        swap(arr[i], arr[depth]);
        makePermutation(n, r, depth+1);
        swap(arr[i], arr[depth]);
    }
}


int main(){
    // permutation();
    makePermutation(3, 2, 0);
    return 0;
}