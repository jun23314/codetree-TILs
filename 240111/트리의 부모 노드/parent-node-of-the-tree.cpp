#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans[100001] = {0,};
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ans[b] = a;
    }

    for(int i = 2; i <= n; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}