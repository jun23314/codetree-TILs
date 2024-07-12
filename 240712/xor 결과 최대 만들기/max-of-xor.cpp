#include <iostream>
#include <vector>

using namespace std;

int n, m;
int num[21];
int max_val = 0;
vector<int> v;

void checkXor(){
    int result = 0;
    for(auto i: v) result = result^i;
    if(result > max_val) max_val = result;
}

void choose(int curr_idx, int curr_val, int result){
    if(curr_idx == m + 1){
        if(result > max_val) max_val = result;
        return ;
    }
    
    for(int i = curr_val; i < n; ++i){
        v.push_back(num[i]);
        result = result^num[i];
        choose(curr_idx+1, curr_val+1, result);
        v.pop_back();
    }
}
int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i){
        scanf("%d", &num[i]);
    }

    choose(1, 0, 0);
    printf("%d", max_val);
    return 0;
}