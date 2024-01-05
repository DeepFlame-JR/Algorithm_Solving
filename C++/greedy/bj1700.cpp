// Optimal Page Replacement
// 가장 미래에 참조되는 Page Swap

#include<bits/stdc++.h>
using namespace std;

int N, K, result, Plug[101], Visit[101];
vector<int> use;

int main(){
    cin >> N >> K;
    for(int i = 0 ;i < K ; i ++) cin >> Plug[i];

    for(int i = 0 ; i < K ; i ++){
        int target = Plug[i];
        if(Visit[target] == 0){ // 플러그를 사용 중이지 않음
            if(use.size() == N){ // 플러그 여유가 없다면 하나를 빼야함 (가장 가까운 plug가 가장 먼 물품)
                int un_plug = 0;
                int last_pick = 0;
                for(int use_plug : use){
                    int here_pick = K;
                    for(int j = i+1 ; j < K ; j ++){
                        if(Plug[j] == use_plug){ // 가장 가까운 plug 찾기
                            here_pick = j;
                            break;
                        }
                    }
                    if(last_pick < here_pick){
                        last_pick = here_pick;
                        un_plug = use_plug;
                    }
                }

                use.erase(find(use.begin(), use.end(), un_plug)); // un_plug될 물품 빼기
                Visit[un_plug] = 0;
                result ++;
            }

            use.push_back(target);
            Visit[target] = 1;
        }
    }

    cout << result << '\n';

    return 0;
}