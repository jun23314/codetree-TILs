#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n, m;

void printing(){
    for(auto i: s){
        printf("%d ", i);
    }
    printf("\n");
}

void choose(int curr_idx, int now){
    if(curr_idx == m+1){
        printing();
        return;
    }

    for(int i = now + 1; i <= n; ++i){
        if(s.find(i) == s.end()) {
            s.insert(i);
            choose(curr_idx + 1, i);
            s.erase(i);
        }
    }
}



int main() {
    scanf("%d %d", &n , &m);
    choose(1, 0);
    return 0;
}