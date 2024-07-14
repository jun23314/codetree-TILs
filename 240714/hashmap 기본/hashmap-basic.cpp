#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

int n;
int main() {
    cin >> n;

    for(int i = 0; i < n; ++i){
        string cmd;
        cin >> cmd;
        
        if(cmd == "add"){
            int a, b;
            cin >> a >> b;

            m[a] = b;
        }
        else if(cmd == "remove" || cmd == "find"){
            int a;
            cin >> a;

            if(m.find(a) == m.end()) {
                cout << "None\n";
                continue;
            }

            if(cmd == "remove") m.erase(a);
            else cout << m[a] << endl;
        }
    }
    
    return 0;
}