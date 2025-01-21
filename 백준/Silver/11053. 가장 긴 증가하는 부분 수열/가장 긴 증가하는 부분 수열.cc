#include<iostream>
using namespace std;

int N,mx=0;
int arr[1001];
int D[1001];
int main(void){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(D[i]<=D[j])D[i]=D[j]+1;
                if(D[i]>mx)mx=D[i];
            }
        }
    }
    cout<<mx;
    return 0;
}


