#include <iostream>
#include <unordered_map>
#include <cstring>
#include <climits>
using namespace std;

string string_window_of_minimum_size(string str , string pattern ){
    int n = str.length();
    int m = pattern.length();
    //cout<<n<<"  "<<m<<endl;
    if(n < m){
        return "No String";
    }
    int total_unique_characters = 0;
    unordered_map<char , int> str_freq;
    unordered_map<char , int> patt_freq;
    for(int i = 0 ; i < m ; i++){
        if(patt_freq.count(pattern[i]) == 0){
            total_unique_characters++;
        }
        patt_freq[pattern[i]]++;
    }
    //int total_unique_characters = patt_freq.size();
    //cout<<total_unique_characters<<endl;
    int s = 0 , e = 0;
    int start = 0 , end = 0;
    int i = 0;
    int matched_characters = 0;
    for( ; i < n ; i++){
        
        str_freq[str[i]]++;
        if(str_freq[str[i]] == patt_freq[str[i]] and patt_freq[str[i]] != 0){
            matched_characters++;
            if(matched_characters == total_unique_characters){
                e = i;
                break;
            }
        }
    }
    //cout<<i<<endl;
    if(i == n){
        return "No String";
    }
    while(str_freq[str[s]] != patt_freq[str[s]]){
        str_freq[str[s]]--;
        s++;
    }
    int min_len = INT_MAX;
    if(min_len > e - s + 1){
        start = s;
        end = e;
        min_len = e - s +1;
    }
    int idx = e+1;
    while(idx < n){
        //cout<<"Start "<<start<<" "<<"End "<<end<<endl;
        while(idx < n and str[idx] != str[s]){
            str_freq[str[idx]]++;
            idx++;
        }
        if(idx < n and str[idx] == str[s]){
            e = idx;
            str_freq[str[idx]]++;
            while(str_freq[str[s]] != patt_freq[str[s]]){
                str_freq[str[s]]--;
                s++;
            }
        }
        if(min_len > e - s + 1){
            min_len = e - s + 1;
            start = s;
            end = e;
        }
        idx++;
    }
    /*string ans = "";
    for( ; start <= end ; start++){
        ans += str[start];
    }
    return ans;*/
    return str.substr(start , min_len);
}

int main(){
    string str , pattern;
    getline(cin , str);
    getline(cin , pattern);
    //cout<<str<<" "<<pattern<<endl;
    cout<<string_window_of_minimum_size(str , pattern)<<endl;
}
