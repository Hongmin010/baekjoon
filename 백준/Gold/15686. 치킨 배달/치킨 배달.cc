#include<iostream>
#include<vector>
void bt(int,int);
using namespace std;
pair<int,int>home[100];
pair<int,int>chik[13];
bool visited[13];
int N,M,A=0,B=0,tmp;
int ans=1000000;
int main(void){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>tmp;
            if(tmp==1){
                home[A].first=i;
                home[A].second=j;
                A++;
            }
            else if(tmp==2){
                chik[B].first=i;
                chik[B].second=j;
                B++;
            }
        }
    }
    bt(0,0);
    cout<<ans;
    return 0;
}

void bt(int n,int start){
    int temp,tp=1000000,anns=0;
    if(n==M){
    for(int i=0;i<A;i++){
        
            tp=1000000;
            for(int j=0;j<B;j++){
                if(visited[j]){
                temp=(int)abs(home[i].first-chik[j].first)+(int)abs(home[i].second-chik[j].second);
                tp=min(tp,temp);
                }
            }
            anns+=tp;
    }
    if(ans>anns) ans=anns;
    return;
}
    for(int i=start;i<B;i++){
        if(!visited[i]){
            visited[i]=true;
            bt(n+1,i+1);
            visited[i]=false;
        }}
}