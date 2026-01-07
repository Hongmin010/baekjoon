    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    int V,E,N=1;
    char gend[1001];
    int parent[10001];
    int result;
    vector<pair<int,pair<int,int>>>v;

    int getParent(int x) {
        if(parent[x]!=x) parent[x]=getParent(parent[x]);
        return parent[x];
    }
    void unionParent(int a, int b) {
        a=getParent(a);
        b=getParent(b);
        if(a<b) parent[b]=a;
        else parent[a]=b;
    }

    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int a,b,c;
        cin>>V>>E;
        for(int i=1;i<=V;i++){
            cin>>gend[i];
        }
        for(int i=0;i<E;i++){
            cin>>a>>b>>c;
            v.push_back({c,{a,b}});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<=V;i++){
            parent[i]=i;
        }
        for(int i=0;i<v.size();i++){
            int cost=v[i].first;
            int a=v[i].second.first;
            int b=v[i].second.second;
            if(gend[a]!=gend[b]){
            if(getParent(a)!=getParent(b)){
                unionParent(a,b);
                result+=cost;
                N++;
            }}
        }
        if(N!=V){
        cout<<-1;
        return 0;
    }
        cout<<result;
        return 0;
    }

