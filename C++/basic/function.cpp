#include <bits/stdc++.h>
using namespace std;

const int max_n = 1004;
int a[max_n];
int a2[max_n][max_n];

int main(){
    // fill(first, last, value): 배열 초기화

    fill(a, a+max_n, 10);
    fill(&a2[0][0], &a2[0][0] + max_n*max_n, 10);
    
    for(int i = 0 ; i < 10 ; i ++) cout << a2[i][0] << " ";
    cout << '\n';

    // sort(first, last, *커스텀 비교함수)
    vector<int> b1;
    int b2[5];

    for(int i = 5; i >= 1; i--) b1.push_back(i);
    for(int i = 5; i >= 1; i--) b2[i - 1] = i;

    sort(b1.begin(), b1.end());
    sort(b2, b2+5);

    for(int i : b1) cout << i << ' ';
    cout << '\n'; // 1 2 3 4 5

    sort(b1.begin(), b1.end(), greater<int>());
    sort(b2, b2+5, greater<int>());

    for(int i : b1) cout << i << ' ';
    cout << '\n'; // 5 4 3 2 1

    // unique : 중복되는 요소들을 앞에서부터 정렬 후, "나머지 요소들은 그대로 둠"
    // 중복되는 값들을 모두 제거하고 싶다면 (sort > erase > unique)
    vector<int> c{3,2,6,3,1,2};

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for(int i:c) cout << i << ' ';
    cout << '\n';

    // lower_bound(): 어떤 값 이상이 되는 위치 (이분탐색, O(nlogn))
    // upper_bound(): 어떤 값이 시작되기 전의 위치 (얘는 뒤에서 부터 찾음)
    vector<int> d{1,2,2,2,3,5};

    printf("%d의 개수: %d, 시작점|값: %d|%d 끝점|값: %d|%d\n",
        2,
        (int)(upper_bound(d.begin(), d.end(), 2) - lower_bound(d.begin(), d.end(), 2)),
        (int)(lower_bound(d.begin(), d.end(), 2) - d.begin()),
        *lower_bound(d.begin(), d.end(), 2),
        (int)(upper_bound(d.begin(), d.end(), 2) - d.begin()), // 뒤에서 부터 확인했을 때, 2가 시작되기 전 값이 3을 출력
        *upper_bound(d.begin(), d.end(), 2)
        );

    cout << *lower_bound(d.begin(), d.end(), 4) << '\n'; // 이상이기 때문에 5를 출력

    return 0;
}

