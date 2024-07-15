#include <iostream>
#include <set>

using namespace std;

int n;
int num;
set<int> s;
set<int> :: iterator it;
int mini = 1000000001;
int main() {
    cin >> n;
    s.insert(0);

    for(int i = 0; i < n; ++i){
        cin >> num;
        s.insert(num);

        it = s.lower_bound(num);
        it--;
        if(num-*it < mini) mini = num-*it;

        if(s.upper_bound(num) != s.end() && *s.upper_bound(num)-num < mini) mini = *s.upper_bound(num) - num;
        

        cout << mini << "\n";
    }


    return 0;
}