class Solution {
public:
    int mySqrt(int x) { 
        long beg=0, end=x/2;
        long mid=(beg + end)/2;
        while(beg<=end){
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid>x){
                end=mid-1;
            }
            else if(mid*mid<x){
                beg=mid+1;
            }
                mid=(beg + end)/2;
        }
        return (x==1) ? 1 : mid;
    }
};