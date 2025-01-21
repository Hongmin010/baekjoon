#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,mx=0;
pair<int,int> arr[1001];
int D[1001];
int main(void){
    cin>>N;
    int a,b;
    for(int i=1;i<=N;i++){
        cin>>a>>b;
        arr[i].first=a;
        arr[i].second=b;
    }
    sort(arr+1,arr+1+N);
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            if(arr[i].first>arr[j].first and arr[i].second>arr[j].second){
                if(D[i]<=D[j])D[i]=D[j]+1;
                if(D[i]>mx)mx=D[i];
            }
        }
    }
    cout<<N-mx;
    return 0;
}


