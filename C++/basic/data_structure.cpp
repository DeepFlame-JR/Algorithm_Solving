#include <bits/stdc++.h>
using namespace std;

/*
Vector
동적 요소를 할당할 수 있는 동적 배열
컴파일 시점에서 요소의 개수를 모를 때 사용
*/

vector<int> v;
vector<int> static_v(5, 77); // length, value
vector<vector<int>> v2(10, vector<int>(10,0));

void print_vec(vector<int> v){
    for(int a:v) cout << a << " ";
    cout << "\n";
}

void learn_vec(){


    cout << "===================\n" << "Learn Vector" << "\n";

    for(int i = 0; i < 10; i ++) v.push_back(i);
    print_vec(v);

    v.erase(v.begin(), v.begin() + 3);
    print_vec(v);

    auto a = find(v.begin(), v.end(), 100);
    if(a == v.end()) cout << "not found" << "\n";

    fill(v.begin(), v.end(), 100);
    print_vec(v);

    print_vec(static_v);
}

/*
Array
정적 배열. 크기를 설정해서 연산을 진행
*/

int a[3] = {1, 2, 3};
int a2[] = {1, 2, 3, 4};
int a3[10];

const int mx = 3;
const int my = 4;
int arr[mx][my];

void learn_arr(){
    cout << "===================\n" << "Learn Array" << "\n";

    for(int x = 0 ; x < mx; x ++){
        for(int y = 0 ; y < my; y ++){
            arr[x][y] = (x+y);
        }
    }

    for(int x = 0 ; x < mx; x ++){
        for(int y = 0 ; y < my; y ++){
            cout << arr[x][y] << " ";
        }
        cout << "\n";
    }
}

/*
List
연결 리스트. (순차접근 사용)
요소가 인접한 메모리 위치에 저장되지 않음.
*/
list<int> li;

void print_list(list <int> a){
    for(auto it : a) cout << it << " ";
    cout << '\n';
}

void learn_list(){
    cout << "===================\n" << "Learn List" << "\n";

    for(int i = 1; i <= 3; i++) li.push_back(i);
    for(int i = 1; i <= 3; i++) li.push_front(i);

    auto it = li.begin(); it++;
    li.insert(it, 1000);
    print_list(li);

    li.pop_front();
    li.pop_back();
    print_list(li);

    li.clear();
}



int main(){
    learn_vec();
    learn_arr();
    learn_list();

    return 0;
}