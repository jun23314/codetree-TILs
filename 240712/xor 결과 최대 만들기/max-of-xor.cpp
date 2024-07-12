#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int num[21];
int max_val = 0;
unordered_set<int> v;

void checkXor(){
    int result = 0;
    for(auto i: v) result = result^i;
    if(result > max_val) max_val = result;
}

void choose(int curr_idx){
    if(curr_idx == m + 1){
        checkXor();
        return ;
    }
    
    for(int i = 0; i < n; ++i){
        if(v.find(num[i]) == v.end()){
            v.insert(num[i]);
            choose(curr_idx+1);
            v.erase(num[i]);
        }
        
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