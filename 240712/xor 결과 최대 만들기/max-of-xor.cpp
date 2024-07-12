#include <iostream>
#include <vector>

using namespace std;

int n, m;
int num[21];
int max_val = 0;
vector<int> v;

void checkXor(){
    int result = 0;
    for(auto i: v)result = result^i;
    if(result > max_val) max_val = result;
}

void choose(int curr_idx){
    if(curr_idx == m + 1){
        checkXor();
        return ;
    }

    for(auto i: num){
        v.push_back(i);
        choose(curr_idx+1);
        v.pop_back();
    }
}
int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i){
        scanf("%d", &num[i]);
    }
    choose(1);
    printf("%d", max_val);
    return 0;
}