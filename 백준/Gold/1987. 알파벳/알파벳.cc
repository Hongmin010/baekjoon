#include<iostream>
#include<vector>
using namespace std;

void dfs(int,int);
char arr[20][20];
bool visited[20][20];
int R,C,tmp=1,ans=1;
vector<char>vec;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(void){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
    visited[0][0]=true;
    vec.push_back(arr[0][0]);
    dfs(0,0);
    cout<<ans;
    return 0;
}

void dfs(int x,int y){
    
    if(tmp>ans)ans=tmp;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(ny>=R or ny<0 or nx>=C or nx<0) continue;
        if(visited[ny][nx]) continue;
        bool s=false;
        for(int j=0;j<vec.size();j++){
            if(vec[j]==arr[ny][nx]){
                s=true;
                break;
            }
        }
        if(s) continue;
        visited[ny][nx]=true;
        tmp++;
        vec.push_back(arr[ny][nx]);
        dfs(nx,ny);
        tmp--;
        visited[ny][nx]=false;
        vec.pop_back();
    }
}
