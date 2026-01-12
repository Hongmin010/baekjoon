#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int N,floor=0;
int stringNum[1000];
string headString;
string s[1000][15];

class Node{
    public: map<string, Node*>children;
    Node(){

    };
};
Node* Head;
Node* recP;

void printNode(Node* currentNode){
    if(currentNode==NULL) return;
    for (auto const& pair : currentNode->children) {
        string foodName = pair.first;
        Node* nextNode = pair.second;
        cout <<string(floor * 2, '-')<< foodName <<endl; 
        floor++;
        printNode(nextNode);
        floor--;
}


}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Head=new Node();
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>stringNum[i];
        cin>>headString;
        if(!Head->children.count(headString)){
            Head->children[headString]=new Node();
        }
        recP=Head->children[headString];
        for(int j=1;j<stringNum[i];j++){
            cin>>s[i][j];
            if(!recP->children.count(s[i][j])){
                recP->children[s[i][j]]= new Node();
            }
            recP=recP->children[s[i][j]];
        }
    }
    printNode(Head);

    return 0;
}

