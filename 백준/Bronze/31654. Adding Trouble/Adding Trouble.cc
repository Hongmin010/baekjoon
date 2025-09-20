#include<iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c){
        cout<<"correct!";
    }
    else{
        cout<<"wrong!";
    }
    return 0;
}




