#include<iostream>
#include<vector>
using namespace std;
void find_leaf(int n);
int A[50];
vector <int> a[50];
int N,n,head,ans=0;
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==-1){
            head=i;
            continue;
        }
        a[A[i]].push_back(i);
    }
    cin>>n;
    if(A[n]==-1) 
    {cout<<"0";
    return 0;
    }
    a[n].clear();
    for(int i=0;i<a[A[n]].size();i++){
        if(a[A[n]].at(i)==n) a[A[n]].erase(a[A[n]].begin()+i);
    }
    find_leaf(head);
    cout<<ans;
    return 0;
}

void find_leaf(int n){
    
    if(a[n].size()==0){
        ans++;
    }
    for(int i=0;i<a[n].size();i++){
        find_leaf(a[n].at(i));
    }
return;
}
