#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int x, y;
unordered_map<int, int> m;
int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &x, &y);
        
        if(m.find(x) == m.end() || m.find(x)->second > y) m[x] = y;
        
    }

    int sum = 0;
    for(auto i: m){
        sum += i.second;
    }
    
    printf("%d", sum);
    return 0;
}