#include<iostream>
using namespace std;
void sudo(int);
bool check(int,int);
int arr[9][9];
int ans[9][9];
bool fin;
int main(void){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    char a;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>a;
            arr[i][j]= a-'0';
        }
    }
    sudo(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}

bool check(int N,int k){
    int y= N/9;
    int x= N%9;
    int X=x/3*3;
    int Y=y/3*3;
    for(int i=0;i<9;i++){
        if(arr[y][i]==k) return true;
    }
    for(int i=0;i<9;i++){
        if(arr[i][x]==k) return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[Y+i][X+j]==k) return true;
        }
    }
    return false;
}


void sudo(int N){  
    if(fin) return;
    if(N==81){
        fin=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                ans[i][j]=arr[i][j];
            }
        }
        return;
    }
    for(int i=1;i<=9;i++){
        if(arr[N/9][N%9]!=0){
            sudo(N+1);
            return;
        }
        if(check(N,i)) continue;
        arr[N/9][N%9]=i;
        sudo(N+1);
        arr[N/9][N%9]=0;
    }
}