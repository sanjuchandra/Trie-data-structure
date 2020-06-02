#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <unordered_map>
#include <cstring>
#include <iostream>
using namespace std;

class node{
    public:
    char data;
    unordered_map<char , node*> children;
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
    void insert(string s){
        node *temp = root;
        for(int i = 0 ; s[i] != '\0' ; i++){
            char ch = s[i];
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

    bool search(string s){
        node *temp = root;
        for(int i = 0 ; s[i] != '\0' ; i++){
            char ch = s[i];
            if(temp->children.count(ch) == 0){
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }

};

int main(){
    int n;
    cin>>n;
    trie t;
    while(n--){
        string str;
        cin>>str;
        t.insert(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        if(t.search(str)){
            cout<<"Present"<<endl;
        }
        else{
            cout<<"Absent"<<endl;
        }
    }
}
