#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_parent(int);
int N,M,K;
int allCard[4000000];
int parent[4000000];
int enemyCard[10000];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        cin >> allCard[i];
        parent[i]=i;
    }
    sort(allCard,allCard+M);
    for(int i=0;i<K;i++){
        int n,idx,parent_idx;
        cin >> n;
        idx = upper_bound(allCard,allCard+M,n) - allCard;
        parent_idx = find_parent(idx);
        cout<<allCard[parent_idx]<<"\n";
        parent[idx] = parent_idx+1;
    }
    


    return 0;
}

int find_parent(int i){
    if(parent[i]==i) return i;
    return find_parent(parent[i]);
}