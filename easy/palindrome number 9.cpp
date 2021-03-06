/**
**@time:2016/11/4
**/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int base=1;
        while(x/base >=10){
            base *=10;
        }
        cout<<"base:"<<base<<endl;
        while(x>0){
            int left = x/base;
            int right = x%10;
            if(left != right){
                return false;
            }
            x -= base*left;
            base /=100;
            x/=10;
        }
        return true;
    }
};