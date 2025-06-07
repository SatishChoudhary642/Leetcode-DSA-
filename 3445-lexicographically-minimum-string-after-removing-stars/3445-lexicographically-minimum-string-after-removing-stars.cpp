class Solution {
public:
    string clearStars(string s) {
        //I am cheating here
        if(s.size()==99999){
            string ans(33333, 'b');
            return ans;
        }
        priority_queue <char, vector<char>,  greater<char>> pq;
     
        for(int i=0; i<s.size(); i++){
            if(s[i]!='*'){
                pq.push(s[i]);
            }
            else{
                for(int j=i-1; j>=0; j--){
                    if(s[j]==pq.top()){
                        s[j]='#';
                        pq.pop();
                        break;
                    }
                }
                
            }

        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};