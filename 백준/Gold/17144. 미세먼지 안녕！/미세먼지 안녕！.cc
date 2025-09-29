    #include<iostream>
    #include<vector>
    #include<cstring>
    using namespace std;
    void dfs(int,int);
    void rot(void);
    int arr[51][51];
    int add[51][51];
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int R,C,T,sum=0;
    pair<int,int>ua;
    pair<int,int>da;
    bool b;
    int main(void){
        cin>>R>>C>>T;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>arr[i][j];
                if(arr[i][j]==-1 and !b){
                    ua.first=i;
                    ua.second=j;
                    b=true; 
                }
                else if(arr[i][j]==-1 and b){
                    da.first=i;
                    da.second=j;
                }
            }
        }
        while(T--){
            memset(add,0,sizeof(add));
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    dfs(j,i);
                }
            }
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    arr[i][j]+=add[i][j];
                }
            }
            rot();
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(arr[i][j]>0)sum+=arr[i][j];
            }
        }
        cout<<sum;
        return 0;
    }

void dfs(int x,int y){
    if(arr[y][x]<5) return;
    int darr=arr[y][x]/5;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(nx<0 or nx>=C or ny<0 or ny>=R or(ny==ua.first and nx==ua.second)or (ny==da.first and nx==da.second )) continue;
        add[y][x]-=darr;
        add[ny][nx]+=darr;
    }
}

void rot(void){
    for(int i=ua.first-1;i>-1;i--){
        arr[i+1][0]=arr[i][0];
    }
    arr[ua.first][0]=-1;
    for(int i=0;i<C-1;i++){
        arr[0][i]=arr[0][i+1];
    }
    for(int i=0;i<ua.first;i++){
        arr[i][C-1]=arr[i+1][C-1];
    }
    for(int i=C-1;i>1;i--){
        arr[ua.first][i]=arr[ua.first][i-1];
    }
    arr[ua.first][1]=0;
    for(int i=da.first+1;i<R-1;i++){
        arr[i][0]=arr[i+1][0];
    }
    for(int i=0;i<C-1;i++){
        arr[R-1][i]= arr[R-1][i+1];
    }
    for(int i=R-1;i>da.first; i--){
        arr[i][C-1]= arr[i-1][C-1];
    }
    for(int i=C-1;i>1;i--){
        arr[da.first][i]= arr[da.first][i-1];
    }
    arr[da.first][1]=0;
    arr[da.first][0]=-1;

}