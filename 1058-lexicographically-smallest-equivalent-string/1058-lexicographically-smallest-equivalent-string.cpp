class UnionFindChar {
public:
    vector<char> parent;
    vector<int> rank;

    UnionFindChar() {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; ++i)
            parent[i] = 'a' + i;  
    }

    char find(char x) {
        int idx = x - 'a';
        if (parent[idx] != x)
            parent[idx] = find(parent[idx]);  
        return parent[idx];
    }

    void unionSet(char a, char b) {
        char rootA = find(a);
        char rootB = find(b);
        if (rootA == rootB) return;
        if (rootA < rootB)
            parent[rootB - 'a'] = rootA;
        else
            parent[rootA - 'a'] = rootB;
    }

    bool isConnected(char a, char b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFindChar u;
        string ans;
        for(int i=0; i<s1.size(); i++){
            u.unionSet(s1[i], s2[i]);
        }
        for(int i=0; i<baseStr.size(); i++){
            ans.push_back(u.find(baseStr[i]));
        }
        return ans;
    }
};