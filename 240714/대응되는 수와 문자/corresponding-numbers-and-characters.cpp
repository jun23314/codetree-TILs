#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<char, char> um;
int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        char c;
        cin >> c;

        um[c] = i + '0';
        um[i + '0'] = c;
    }

    for(int i = 0; i < m; ++i){
        char c;
        cin >> c;

        cout << um[c] << endl;
    }

    return 0;
}