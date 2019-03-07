class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int lmax=0, rmax = 0;

        int container = 0;

        while(i<j){
            lmax = height[i] > lmax? height[i]:lmax;
            rmax = height[j] > rmax? height[j]:rmax;

            if(lmax < rmax){
                container += lmax - height[i];
                i++;
            }else{
                container += rmax - height[j];
                j--;
            }
        }
        
        return container;
    }
};