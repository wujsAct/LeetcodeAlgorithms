class Solution {
public:
    int trap(vector<int>& height) {
        #其实题目一点都不难啊，咱们要先找到塔顶，然后从两边开始往塔顶遍历，这样水位只会增长，并且和目前遇到的最大高度持平！
        int n=height.size();
        int left =0;
        int right=n-1;
        int secondHeight=0;
        int totalWater=0;
        while(left<right){
            if(height[left]<height[right]){
                secondHeight = (secondHeight>height[left]?(secondHeight):(height[left]));
                totalWater += secondHeight-height[left];
                left ++;
            }
            else{
                secondHeight = (secondHeight>height[right]?(secondHeight):(height[right]));
                totalWater += secondHeight-height[right];
                right--;
            }
        }
        return totalWater;  
    }
};