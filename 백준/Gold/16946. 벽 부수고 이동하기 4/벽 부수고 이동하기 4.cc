    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <set>
    using namespace std;
    bool dfs(int n,int m, int groupId);
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int N,M;
    int num=0;
    int map[1001][1001];
    bool visited[1001][1001];
    int groupMap[1001][1001];
    int ansMap[1001][1001];
    vector<int> idNum;
    set<int> groupSet;
    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>N>>M;
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < M; j++){
                char c;
                cin>>c;
                map[i][j]= c-'0';
            }
        }
        int id = 0;
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < M; j++){
                if(dfs(i,j,id)){
                idNum.push_back(num);
                num=0;
                id++;
                }
            }
        }
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < M; j++){
                if(!map[i][j]) ansMap[i][j]=0;
                else{
                    for(int k = 0; k < 4; k++){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(ny < 0 or ny >= N or nx < 0 or nx >=M) continue;
                        if(map[ny][nx]) continue;
                        groupSet.insert(groupMap[ny][nx]);
                    }
                    for(int x : groupSet){
                        ansMap[i][j]+=idNum[x];
                    }
                    ansMap[i][j]++;
                    ansMap[i][j]=ansMap[i][j] % 10;
                    groupSet.clear();
                }
            }
        }
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < M; j++){
                cout<< ansMap[i][j];
            }
            cout<<"\n";
        }
        
        return 0;
    }

    bool dfs(int n,int m, int groupId){
        if(n<0 or n>=N or m<0 or m>=M) return false;
        if(map[n][m]) return false;
        if(visited[n][m]) return false;
        visited[n][m]=true;
        num++;
        groupMap[n][m]=groupId;
        dfs(n+1,m,groupId);
        dfs(n-1,m,groupId);
        dfs(n,m-1,groupId);
        dfs(n,m+1,groupId);
        return true;
    }