#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,Q;
int N=0,T=-1;
long long co=0;
int parent[200001];
vector<pair<pair<int,int>,pair<int,int>>>v;
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
    cin>>n>>Q;
    for(int i=0;i<Q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back({{c,d},{a,b}});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<v.size();i++){
        if(N==n-1) break;
        int cost=v[i].first.first;
        int time=v[i].first.second;
        int start=v[i].second.first;
        int end=v[i].second.second;
        if(getParent(start)!=getParent(end)){
            unionParent(start,end);
            N++;
            T=max(T,time);
            co+=cost;
        }
    }
    if(N!=n-1){
        cout<<-1;
        return 0;
    }
    cout<<T<<" "<<co;
    return 0;
}

