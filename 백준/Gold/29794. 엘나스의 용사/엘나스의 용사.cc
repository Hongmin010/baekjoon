#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N,M,K;
long long ansA;
long long sum=0,DeSum;
int currentLevel[201];
int monsterLevel[200];
long long sumOfVisited[200];
pair<int,int> sortMonsterLevel[200];
int properHuntingMap[201];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        currentLevel[temp]++;
    }
    for(int i=0;i<M;i++){
        cin>>monsterLevel[i];
        sortMonsterLevel[i].first=monsterLevel[i];
        sortMonsterLevel[i].second=i;
    }
    sort(sortMonsterLevel,sortMonsterLevel+M);
    for(int i=1;i<M;i++){
        for(int j=sortMonsterLevel[i-1].first;j<sortMonsterLevel[i].first;j++){
            properHuntingMap[j]=sortMonsterLevel[i-1].second;
        }
    }
    for(int i=sortMonsterLevel[M-1].first;i<201;i++){
        properHuntingMap[i]=sortMonsterLevel[M-1].second;
    }
    for(int i=0;i<K;i++){
        for(int j=1;j<201;j++){
            if(j+i>=200) break;
            sumOfVisited[properHuntingMap[j+i]]+=currentLevel[j];
            sum+=currentLevel[j]*properHuntingMap[j+i];
        }
    }
    DeSum=sum;
    for(long long i=1;i<M;i++){
        long long temp=0;
        for(long long j=0;j<M;j++){
            temp+=min(sumOfVisited[j]*j,sumOfVisited[j]*abs(i-j));
        }
        DeSum=min(temp,DeSum);
        if(DeSum==temp) ansA=i;
    }
    cout<<1<<" "<<ansA+1<<"\n";
    cout<<sum-DeSum;
    return 0;
}

