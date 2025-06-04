class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        vector<string> strings;
        char max_char = word[0];

        for (int i = 1; i < word.size(); i++) {
            if (word[i] > max_char) {
                max_char = word[i];
            }
        }

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == max_char) {
                int friends_till_i = i;
                int friends_left = numFriends - friends_till_i - 1;
                int j = word.size() - friends_left;
                string s = word.substr(i, j - i);
                strings.push_back(s);
            }
        }

        string ans = strings[0];
        for (int i = 1; i < strings.size(); i++) {
            if (ans < strings[i]) {
                ans = strings[i];
            } 
        }
        return ans;
    }
};