class Solution {
public:    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image[0].size();
        for(int i=0; i<n; i++){

            for(int j=0; j<=n-j-1; j++){
                swap(image.at(i).at(j),image.at(i).at(n-j-1));
            }
            for(int k=0; k<n; k++){
                if(image.at(i).at(k)==1){
                   image.at(i).at(k)=0;
                }
                else if(image.at(i).at(k)==0){
                    image.at(i).at(k)=1;
                }
            }
        }
        return image;
    }
};