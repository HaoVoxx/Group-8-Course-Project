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
    s = 

    return 0;
}