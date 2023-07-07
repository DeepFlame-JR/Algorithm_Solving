#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    map<int, vector<vector<int>>> count_mapper;
    int left = 0, sum = 0;

    for(int right = 0 ; right < sequence.size() ; right ++){
        sum += sequence[right];
        while(left <= right && sum > k){
            sum -= sequence[left++];
        }
        if(sum == k){
            count_mapper[right-left].push_back({left, right});
        }
        // cout << left << ' ' << right << ' ' << sum << '\n';
    }

    auto first_item = *(count_mapper.begin());
    return first_item.second[0];
}

int main(){
    solution({1,2,3,4,5}, 7) ;
    solution({1,1,1,2,3,4,5}, 5) ;
    solution({2,2,2,2,2}, 6) ;

    return 0;
}