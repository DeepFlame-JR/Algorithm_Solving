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
    cout << "===================" << "Learn Vector" << "\n";

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
    cout << "===================" << "Learn Array" << "\n";

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
    cout << "===================" << "Learn List" << "\n";

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

map<string, int> mp; // 정렬이 됨. 레드블랙트리 기반. 탐색,삽입,삭제 O(logN)
unordered_map<string, int> ump; // 정렬이 안됨. 해시테이블 기반. 탐색,삽입,삭제 O(1) or 최악: O(N)

void learn_map(){
    cout << "===================" << "Learn Map" << "\n";

    mp["b"] = 1;
    mp["a"] = 2;

    cout << mp.size() << "\n";
    
    if(mp.find("c") == mp.end()) cout << "Not Exist" << '\n';

    for(auto it : mp) cout << (it).first << ":" << (it).second << '\n';

    mp.clear();

    ump["bcd"] = 1;
    ump["aaa"] = 1;
    ump["aba"] = 1;
    for(auto it : ump) cout << (it).first << ":" << (it).second << '\n';
}

void learn_set(){
    cout << "===================" << "Learn Set" << "\n";

    set<pair<string, int>> st;
    st.insert({"a", 1});
    st.insert({"a", 1});
    st.insert({"a", 2});
    cout << st.size() <<"\n";
    for(auto it : st) cout << (it).first << ":" << (it).second << '\n';
}


stack<int> st;
queue<int> q;
deque<int> dq;
void learn_deque(){
    cout << "===================" << "Queue" << "\n";

    for(int i = 0 ;i < 10 ; i++) st.push(i);

    while(st.size()){
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';

    cout << "===================" << "Stack" << "\n";
    for(int i = 0 ;i < 10 ; i++) q.push(i);

    while(q.size()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';

    cout << "===================" << "Deque" << "\n";
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << dq.front() << '\n';
    cout << dq.back() << '\n';
    cout << dq.size() << '\n';

    dq.pop_front();
    dq.pop_back();
    cout << dq.size() << '\n';
}

struct Point{
    int x,y;
    Point(int x, int y) : x(x), y(y) {}
    Point(){x=-1;y=-1;}
    // 오름차순 정렬
    bool operator < (const Point & a) const{
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
};
vector<Point> vp;

void learn_struct(){
    cout << "===================" << "Struct" << "\n";

    vp.push_back(Point(2,4));
    vp.push_back(Point(1,4));
    vp.push_back(Point(2,3));

    sort(vp.begin(), vp.end());
    for(auto p : vp) cout << p.x << ":" << p.y << "\n";
}

priority_queue<int, vector<int>, greater<int> > pq; //오름차순
priority_queue<int> pq2; // 내림차순
priority_queue<int, vector<int>, less<int> > pq3; // 내림차순
priority_queue<Point> pq1;
void learn_priority_queue(){
    cout << "===================" << "Priority Queue" << "\n";

    for(int i = 5; i >= 1; i--){
        pq.push(i); pq2.push(i); pq3.push(i);
    }

    while(pq.size()){
        cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << '\n';
        pq.pop(); pq2.pop(); pq3.pop();
    }

    pq1.push({1,3});
    pq1.push({2,1});
    pq1.push({1,1});

    cout << pq1.top().x << ":" << pq1.top().y << "\n";
}

int main(){
    // 비동기 처리 
    // 알고리즘 테스트에서 속도 이득을 볼 수 있음
    // 알고리즘은 싱글 스레드라서 에러가 날 확률도 적음
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    learn_vec();
    learn_arr();
    learn_list();
    learn_map();
    learn_set();
    learn_deque();
    learn_struct();
    learn_priority_queue();
    return 0;
}