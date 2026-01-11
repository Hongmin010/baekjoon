#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int minCost=0;
int cost[301][301];
int parent[301];
vector<pair<int,pair<int,int>>>v;
int getParent(int x){
    if(parent[x]!=x) parent[x]=getParent(parent[x]);
    return parent[x];
}
void unionParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cost[i][n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back({cost[i][j],{i,j}});
        }
    }    
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int tempCost=v[i].first;
        int start=v[i].second.first;
        int end=v[i].second.second;
        if(getParent(start)!=getParent(end)){
            unionParent(start,end);
            minCost+=tempCost;
        }
    }
    cout<<minCost;
    return 0;
}

