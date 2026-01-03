#include <iostream>
using namespace std;
int V,E;
int map[401][401];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    int ans=10000000;
    cin>>V>>E;
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            map[i][j]=10000000;
        }
    }
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        map[a][b]=c;
    }
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){          
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
            }
        }
    }
    for(int i=1;i<=V;i++){
        ans=min(ans,map[i][i]);    
    }
    if(ans==10000000) {
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}

