class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size(), n2=needle.size();
        bool ch;
        for (int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(needle[j]!=haystack[i+j]){
                    ch=false;
                    break;
                }
                else {
                    ch=true;
                }
            }
            if(ch==true){
                    return i;
                }
        }
        return -1;
    }
};