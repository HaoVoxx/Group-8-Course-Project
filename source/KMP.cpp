#include "KMP.h"
vector <int> prefix_function (string t){
    int m = t.size();
    int j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++){
        if (t[i] == t[j]){
            pi[i] = ++j;
        }
        else{
            while (t[i] != t[j] && j > 0)
                j = pi[j - 1];
            if (t[i] == t[j])
                pi[i] = ++j;
        }
    }
    return pi;
 }
bool StringMatching(string s, string t){
    int m = t.size();
    int n = s.size();
    int j = 0;
    vector <int> pi = prefix_function(t);
    for(int i = 0; i < n; i++){
        while(j > 0 && s[i] != t[j]) j = pi[j - 1];
        if(s[i] == t[j]){
            j++;
        }
        if(j == m){
            return true;
        }
    }
    return false;
}