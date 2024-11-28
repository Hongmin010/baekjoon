#include <iostream>
#include <algorithm>
using namespace std;
int m,n,k,cnt=0;
int **graph;
bool dfs(int,int);

int main(void){
    int T,y,x;
    cin >> T;
    for(int i=0;i<T;i++){
    cin >> m >> n >> k;
    graph= new int*[n];
    for(int i=0;i<n;i++ ){
    graph[i]= new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            graph[i][j]=0;
        }
    }
    while(k--){
        cin>> x >>y;
        graph[y][x]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(dfs(j,i)){
               cnt++;
           }
        }
    }
    cout << cnt << endl;
    for(int i=0;i<n;i++){
        delete[]graph[i];
    }
    delete graph;
    cnt=0;
    }

return 0;
}

bool dfs(int x,int y){
    if (x<=-1|| x>=m||y<=-1||y>=n){
        return false;
    }
    if (graph[y][x]==1){
        graph[y][x]=0;
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x,y+1);
        return true;
    }
   return false; 
}

