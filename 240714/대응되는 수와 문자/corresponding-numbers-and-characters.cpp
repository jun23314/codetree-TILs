#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> um;
int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        string c;
        cin >> c;
        
        um[c] = to_string(i);
        um[to_string(i)] = c;
    }

    for(int i = 0; i < m; ++i){
        string c;
        cin >> c;

        cout << um[c] << endl;
    }

    return 0;
}