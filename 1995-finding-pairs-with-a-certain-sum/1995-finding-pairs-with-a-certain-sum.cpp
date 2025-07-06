class FindSumPairs {
public:
vector<int> nums1, nums2;
unordered_map <int, int> m1;
unordered_map <int, int> m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int i=0; i<nums2.size(); i++){
            m2[nums2[i]]++;
        }
        for(int i=0; i<nums1.size(); i++){
            m1[nums1[i]]++;
        }
    }
    
    void add(int index, int val) {
        m2[nums2[index]]--;
        nums2[index]+=val;
        m2[nums2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto i: m1){
            cnt+=(i.second*m2[(tot-i.first)]);
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */