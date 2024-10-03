#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector <string> v;
vector <int> t;
vector <string> vec;

int main(void)
{
    int n=0,num=0;
    bool a;
    string S;
    cin>>S;
    for(int i=0;i<S.size();i++){
        if(S.at(i)=='+'){
            v.push_back(S.substr(n,i-n));
            vec.push_back(S.substr(i,1));
            n=i+1;
        }
        else if(S.at(i)=='-'){
            v.push_back(S.substr(n,i-n));
            vec.push_back(S.substr(i,1));
            n=i+1;
        }
        else if(i==S.size()-1){
            v.push_back(S.substr(n));
        }}
        n=1;
        for(auto x : v){
         t.push_back(stoi(x));
        }
        if(vec.size()==0){
            cout<<t[0];
            return 0;
        }
        num=t[0];
        if(vec[0]=="+") a=false;
        else a=true;
        for(string x: vec){
            if(x=="-") a=true;
            if(a){
            num-=t[n];
            n++;
            }
            else{
            num+=t[n];
            n++;
            }
        }
        cout<<num;
    return 0;
}


