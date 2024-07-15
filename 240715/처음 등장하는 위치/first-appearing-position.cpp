#include <iostream>
#include <map>

using namespace std;

int n;
int k;
map<int, int> m;
int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
        scanf("%d", &k);
        if(m.find(k) == m.end()) m[k] = i;
    }

    for(auto i: m){
        printf("%d %d\n", i.first, i.second);
    }
    
    return 0;
}