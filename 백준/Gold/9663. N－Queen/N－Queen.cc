#include<iostream>
#include<algorithm>
using namespace std;
void NQ(int cnt);
bool check(int);
int N,n=0;
int arr[16];
int main(void){
    cin>>N;
    NQ(1);
    cout<<n;
    
    return 0;
}

bool check(int cnt){
    for(int i=1;i<cnt-1;i++){
            if (arr[i]==arr[cnt-1] or cnt-1-i == abs(arr[cnt-1]-arr[i])) return true;
            
    }
    return false;
}


void NQ(int cnt){
    if(check(cnt)){
        return;
    }
    if(cnt==N+1){
        n++;
        return;
    }

    for(int i=1;i<=N;i++){
            arr[cnt]=i;
            NQ(cnt+1);
        }
}