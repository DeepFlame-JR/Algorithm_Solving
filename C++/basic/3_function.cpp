#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> v){
    for(int a:v) cout << a << " ";
    cout << "\n";
}

const int max_n = 1004;
int a[max_n];
int a2[max_n][max_n];
void init_arr(){
    fill(a, a+max_n, 10);
    fill(&a2[0][0], &a2[0][0] + max_n*max_n, 10);

    for(int i = 0 ; i < 10 ; i ++) cout << a2[i][0] << " ";
    cout << '\n';
}

void sort_arr(){
    vector<int> v{5,4,3,2,1};

    sort(v.begin(), v.end());
    print_vec(v); // 1 2 3 4 5

    int arr[5] = {5,4,3,2,1};
    sort(arr, arr+5);
    sort(arr, arr+5, less<int>()); // 내림차순
    sort(arr, arr+5, greater<int>()); // 오름차순
    for(int i : arr) cout << i << ' ';
    cout << '\n'; // 5 4 3 2 1

    vector<pair<int, int>> v2{{1,1},{2,2},{3,3}};
    sort(v2.begin(), v2.end(), greater<pair<int,int>>());
    for(auto i : v2) cout << i.first << ' ';
    cout << '\n';
}

void Unique(){
    // unique : 중복되는 요소들을 앞에서부터 정렬 후, "나머지 요소들은 그대로 둠"
    // 중복되는 값들을 모두 제거하고 싶다면 (sort > erase > unique)
    vector<int> c{3,2,6,3,1,2};

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for(int i:c) cout << i << ' ';
    cout << '\n';
}

void Accumulate(){
    vector<int> v{1,2,3,4,5};
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << '\n';
}

void Max_Element(){
    vector<int> v{1,2,3,4,5};
    int max = *max_element(v.begin(), v.end());
    cout << max << '\n';
}

void Bound(){
    // lower_bound(): 어떤 값 이상이 되는 위치 (이분탐색, O(nlogn))
    // upper_bound(): 어떤 값이 시작되기 전의 위치 (얘는 뒤에서 부터 찾음)
    vector<int> d{1,2,2,2,3,5};
    for(int i:d) cout << i << ' ';
    cout << '\n';

    printf("%d의 개수: %d, 시작점|값: %d|%d 끝점|값: %d|%d\n",
        2,
        (int)(upper_bound(d.begin(), d.end(), 2) - lower_bound(d.begin(), d.end(), 2)),
        (int)(lower_bound(d.begin(), d.end(), 2) - d.begin()),
        *lower_bound(d.begin(), d.end(), 2),
        (int)(upper_bound(d.begin(), d.end(), 2) - d.begin()), // 뒤에서 부터 확인했을 때, 2가 시작되기 전 값이 3을 출력
        *upper_bound(d.begin(), d.end(), 2)
        );

    cout << *lower_bound(d.begin(), d.end(), 4) << '\n'; // 이상이기 때문에 5를 출력
}

int main(){
    init_arr();
    sort_arr();
    Unique();
    Accumulate();
    Max_Element();
    Bound();

    return 0;
}

