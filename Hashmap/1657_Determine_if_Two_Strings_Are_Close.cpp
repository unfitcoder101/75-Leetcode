#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        unordered_map<char,int> mp1, mp2;

        for(char c : word1) mp1[c]++;
        for(char c : word2) mp2[c]++;

        // Both strings must have the same number of distinct characters
        // since frequency groups cannot be split or merged
        if(mp1.size() != mp2.size()) return false;

        // Condition 1: Same character set must exist
        for(auto &p : mp1){
            if(mp2.find(p.first) == mp2.end())
                return false;
        }

        // Condition 2: The multiset of character frequencies must match
        vector<int> f1, f2;
        for(auto &p : mp1) f1.push_back(p.second);
        for(auto &p : mp2) f2.push_back(p.second);

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2;
    }
};
