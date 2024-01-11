#include <iostream>
#include <vector>

using namespace std; 

vector<int> arr[51];
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr[a].push_back(i);
    }

    int del;
    cin >> del;

    int start = 0;
    int cnt = 0;
    vector<int>::iterator it;
    while(1){
        if(!arr[start].empty()){
            if(start != del) cnt++;
            cout << cnt;
            return 0;
        }
        for(it = arr[start].begin(); it != arr[start].end(); ++it){
            if(*it != del) {
                start = *it;
                break;
            }
        }
    }


    

    return 0;
}