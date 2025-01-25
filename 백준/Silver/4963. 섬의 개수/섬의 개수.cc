#include<iostream>
#include<math.h>
using namespace std;
bool dfs(int,int);

int a[51][51];
bool visited[51][51];
int cnt=0;
int w,h;
int main(void){
    
    while(1){
        cin>>w;
        cin>>h;
        if(w==0 and h==0) return 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>a[i][j];   
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(dfs(j,i)) cnt++;  
            }
        }
        cout<<cnt<<"\n";

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                visited[i][j]=false;  
            }
        }
        cnt=0;
    }
    return 0;
}


bool dfs(int x, int y){
    if(x<0 or x>=w or y<0 or y>=h){
        return false;
    }
    if(!a[y][x]){
        return false;
    }
    if(visited[y][x]){
        return false;
    }
    visited[y][x]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x-1,y+1);
    dfs(x+1,y+1);
    dfs(x-1,y-1);
    dfs(x+1,y-1);
    return true;
}
