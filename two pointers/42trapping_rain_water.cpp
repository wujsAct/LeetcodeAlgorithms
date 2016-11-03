class Solution {
public:
    int trap(vector<int>& height) {
        #��ʵ��Ŀһ�㶼���Ѱ�������Ҫ���ҵ�������Ȼ������߿�ʼ����������������ˮλֻ�����������Һ�Ŀǰ���������߶ȳ�ƽ��
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