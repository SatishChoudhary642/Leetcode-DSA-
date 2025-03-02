class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0, j=0;  
        vector <vector <int> > ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i][0]==nums2[j][0]){
                vector <int> v={nums1[i][0], nums1[i][1]+nums2[j][1]};
                ans.push_back(v);
                i++;
                j++;
            }
            else if(nums1[i][0]<nums2[j][0]){
                vector <int> v={nums1[i][0], nums1[i][1]};
                ans.push_back(v);
                i++;
            }
            else if(nums1[i][0]>nums2[j][0]){
                vector <int> v={nums2[j][0], nums2[j][1]};
                ans.push_back(v);
                j++;
            }
        }
        while(i<nums1.size()){
            vector <int> v={nums1[i][0], nums1[i][1]};
                ans.push_back(v);
                i++;
        }
        while(j<nums2.size()){
            vector <int> v={nums2[j][0], nums2[j][1]};
                ans.push_back(v);
                j++;
        }
        return ans;

    }
};