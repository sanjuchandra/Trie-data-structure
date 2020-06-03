#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int , int> m;
        for(int i = 0 ; i < n ; i++){
            int d;
            cin>>d;
            m[d]++;
        }
        int q;
        cin>>q;
        while(q--){
            int d;
            cin>>d;
            if(m.count(d)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
