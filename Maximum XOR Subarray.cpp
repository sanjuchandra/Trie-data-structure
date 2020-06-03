#include <iostream>
#include <cstring>
#include <unordered_map>
#include <climits>
using namespace std;
class node{
    public:
    bool data;
    unordered_map<bool, node*> children;
    int data_value;
    node(char ch){
        data = ch;
        //data_value = INT_MIN;
        //children.insert(make_pair(1 , ))
    }
};

class trie{
    node *root;
    public:
    trie(){
        root = new node('\0');
    }
    void insert_bits(int n){
        node *temp = root;
        //int l = 32; //by default
        for(int i = 31 ; i >= 0 ; i--){
            bool bit = (n>>i) & 1;
            if(temp->children.count(bit)){
                temp = temp->children[bit];
            }
            else{
                node *n = new node(bit); //n is local scope
                temp->children[bit] = n;
                temp = n;
            }
        }
        temp->data_value = n;
    }

    int search_and_return_data_value(node *root , int n){
        //binary = decimal_to_binary(n);
        for(int i = 31 ; i >= 0 ; i--){
            int bit = (n>>i)&1;
            if(root->children.count(!bit)){
                root = root->children[!bit];
            }
            else if(root->children.count(bit)){
                root = root->children[bit];
            }
        }
        return root->data_value;
    }

    int max_xor_subarray(int arr[] , int n){
        if(n <= 1){
            return 0;
        }
        int curr_xor = 0;
        for(int i = 0 ; i < n ; i++){
            arr[i] = curr_xor ^ arr[i];
            curr_xor = arr[i];
        }
        int ans = INT_MIN;
        insert_bits(arr[0]);
        for(int i  = 1 ; i < n ; i++){
            //node *temp = root;
            int val = search_and_return_data_value(root , arr[i]);
            ans = max(ans , (arr[i] ^ val));
            //cout<<ans<<" ";
            insert_bits(arr[i] );
        }
        return ans;
    }
};


int main(){
    int n;
    cin>>n;
    trie t;
    int arr[1000000] = {0};
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<t.max_xor_subarray(arr , n)<<endl;
    return 0;
}
