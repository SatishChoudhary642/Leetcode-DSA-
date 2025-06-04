class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        int size=(word.size() -  numFriends) + 1;
        vector<string> s;
        char max=word[0];

        for(int i=1; i<word.size(); i++){
            if(word[i]>max){
                max=word[i];
            }
        }
        for(int i=0; i<word.size(); i++){
            if(word[i]==max){
                int ni=i;
                int fl=numFriends -ni -1;
                int j=word.size() -fl;
                string w=word.substr(i,j-i);
                s.push_back(w);
            }
        }

        string ans=s[0];
        for(int i=1; i<s.size(); i++){
            for(int j=0; j<s[i].size(); j++){
                if(ans[j]<s[i][j]){
                    ans=s[i];
                    break;
                }
                else if(ans[j]>s[i][j]){
                    break;
                }
            }
        }
        return ans;
    }
};