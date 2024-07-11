#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int cnt = 0;

bool checkBeautiful(){
    for(int i = 0; i < v.size(); ++i){
        int num = v[i];
        int count = 1;
        for(int j = 1; j < num; ++j) if(v[i+j] == num) count++;
        if(count != num) return false; 
    }
    return true;
}

void choose(int curr_idx){
    if(curr_idx == n+1){
        if(checkBeautiful()) cnt++;
        return ;
    }

    for(int i = 1; i <= 4; ++i){
        v.push_back(i);
        choose(curr_idx + 1);
        v.pop_back();
    }

    return ;
}

int main() {
    scanf("%d", &n);
    choose(1);
    printf("%d", cnt);
    return 0;
}