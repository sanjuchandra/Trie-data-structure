#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;


void print_array(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void secret_code(int arr[] , int n , int k){
    if(k <= 0){
        return;
    }
    int counter = n;
    unordered_map<int , int> m;
    for(int i = 0 ; i < n ; i++){
        m[arr[i]] = i;
    }
    for(int i =0 ; i < n ; i++){
        if(k <= 0){
            return;
        }
        if(arr[i] != counter){
            int idx = m[counter];
            m[counter] = i;
            m[arr[i]] = idx;
            swap(arr[i] , arr[idx]);
            k--;
        }
        //print_array(arr , n);
        counter--;
    }
    return;
}


 
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[1000000] = {0};
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    secret_code(arr , n , k);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
