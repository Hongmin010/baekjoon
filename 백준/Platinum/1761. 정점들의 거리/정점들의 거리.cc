#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<pair<int,int>> treeList[40001];
int arr[17][40001];
int depthFromRoot[40001];
int distanceFromRoot[40001];
void dfs(int startNode,int parentNode, int depth, int distance){
    depthFromRoot[startNode] = depth;
    distanceFromRoot[startNode] = distance;
    arr[0][startNode] = parentNode;

    for(int i=0; i<treeList[startNode].size();i++){
        int nextNode = treeList[startNode][i].first;
        int distanceToNextNode = treeList[startNode][i].second;
        if(nextNode != parentNode){
            dfs(nextNode,startNode,depth+1,distance+distanceToNextNode);
        }
    }
}

void fillArr(int n){
    for(int k = 1; k < 17 ; k++){
        for(int i = 1; i <= n ; i++){
            int ancestor = arr[k-1][i];
            if(ancestor != 0){
                arr[k][i] = arr[k-1][ancestor];
            }
        }
    }
}

int findLCA(int a, int b){
    if(depthFromRoot[a] < depthFromRoot[b]) swap(a,b);
    int diffOfDepth = depthFromRoot[a]-depthFromRoot[b];
    for(int k=0;diffOfDepth>0;k++){
        if(diffOfDepth % 2 == 1){
            a=arr[k][a];
        }
        diffOfDepth/=2;
    }
    if(a==b) return a;

    for(int k= 16; k >= 0 ; k--){
        if(arr[k][a]!=0 and arr[k][a]!=arr[k][b]){
            a=arr[k][a];
            b=arr[k][b];
        }
    }

    return arr[0][a];
}



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b,d;
        cin>>a>>b>>d;
        treeList[a].push_back({b,d});
        treeList[b].push_back({a,d});
    }
    dfs(1,0,0,0);
    fillArr(N);
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        cout<<distanceFromRoot[a] + distanceFromRoot[b]-2*distanceFromRoot[findLCA(a,b)]<<"\n";
    }
    return 0;
}

