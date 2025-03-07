class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int A=0, B=numbers.size()-1;
        while( A<B){
            if(numbers[A] + numbers[B] == target){
                ans.push_back(A+1);
                ans.push_back(B+1);
                break;
            }
            else if(numbers[A] + numbers[B] < target){
                A++;
            }
            else{
                B--;
            }
            
        }
        
        return ans;
    }
};