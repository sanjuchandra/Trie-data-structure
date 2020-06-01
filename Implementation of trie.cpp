#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class node{
    public:
    char data;
    unordered_map<char , node *> children;
    bool terminal;
    node(char ch){
        data = ch;
        terminal = false;
    }
};

class trie{
    node *root;
    int cnt;
    public:
    trie(){
        root = new node('\0');
        cnt = 0;
    }
    void insert(char *w){
        node *temp = root;
        for(int i = 0 ; w[i] != '\0' ; i++){
            char ch = w[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                node *n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool search(char *w){
        node *temp = root;
        for(int i = 0 ; w[i] != '\0' ; i++){
            char ch = w[i];
            if(temp->children.count(ch) == 0){
                //pahle hi pakada gya bc
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        return temp->terminal; //aakhrui mein check kro terminal hai ki nahi
    }
};

int main(){
    trie t;
    char w[][10] = {"a" , "hello" , "not" , "news" , "apple"};
    int n = 5;
    for(int i = 0 ; i < n ; i++){
        t.insert(w[i]);
    }
    char x[100];
    cin>>x;
    if(t.search(x)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
    return 0;
}
