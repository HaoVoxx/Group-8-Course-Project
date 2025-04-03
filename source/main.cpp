#include <iostream>
#include "Aho_Corasick.h"
#include "KMP.h"

int main(){
    // KMP
    string s = "ABXABABABAA";
    string t = "ABABAA";
    if(StringMatching(s, t)) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';

    s = "AAAAAAAAAAB";
    t = "AAB";
    if(StringMatching(s, t)) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';

    // Aho - Corasick
    trie a;
    s = "DI";
    a.add(s);
    s = "DIDU";
    a.add(s);
    s = "DIDI";
    a.add(s);
    s = "DU";
    a.add(s);
    s = "DUDUA";
    a.add(s);
    s = "DUADI";
    a.add(s);
    s = "DIDUDUADI";
    a.preprocessing();
    int ans = a.countPattern(s);
    std::cout << ans << '\n';
    a.release();
    return 0;
}