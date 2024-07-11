#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> v;

void printing(){
    for(int i = 0; i < v.size(); ++i){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void choose(int curr_num){
    if(curr_num == n+1){
        printing();
        return ;
    }

    for(int i = 1; i <= k; ++i){
        v.push_back(i);
        choose(curr_num + 1);
        v.pop_back();
    }
    return ;
}



int main() {
    scanf("%d %d", &k, &n);
    choose(1);

    return 0;
}