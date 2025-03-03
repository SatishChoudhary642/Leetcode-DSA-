class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr1, arr2, arr3;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                arr1.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                arr2.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                arr3.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        arr1.insert(arr1.end(), arr3.begin(), arr3.end());
        return arr1;
    }
};