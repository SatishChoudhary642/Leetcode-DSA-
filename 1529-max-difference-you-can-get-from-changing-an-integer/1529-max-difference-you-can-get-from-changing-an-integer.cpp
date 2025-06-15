class Solution {
public:
    int toInt(vector<int>& v) {
        int ans = 0, n = v.size()-1;
        
        if (v.size() == 1) {
            return v[0];
        }
        for (int i = 0; i < v.size(); i++) {
            int temp=v[i]*pow(10,n);
            ans+=temp;
            n--;
        }
        return ans;
    }
    vector<int> toVec(int n) {
        vector<int> v;
        if(n==0){
            return {0};
        }
        while (n > 0) {
            v.push_back(n % 10);
            n = n / 10;
        }
        reverse (v.begin(), v.end());
        return v;
    }
    int replace(vector<int> v, int n) {
        int temp=v[0];
        if(n==9){
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != n) {
                    temp=v[i];
                    break;
                }
            }
        }
        if(n==1 && v.size()>1){
            if(v[0]==1){
                for (int i = 0; i < v.size(); i++) {
                    if (v[i] != 1 && v[i] != 0) {
                        temp=v[i];
                        n=0;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == temp) {
                v[i] = n;
            }
        }

        return toInt(v);
    }
    int maxDiff(int num) {
        vector<int> v;
        int s, b;
        v = toVec(num);
        b = replace(v, 9);
        s = replace(v, 1);
        return b-s;
    }
};