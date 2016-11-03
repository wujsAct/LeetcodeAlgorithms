/**
@time:2016/10/23
@funtion Pow(x,n)
@need to attention： n is negative number(-1), time out case(0.00001 2147483647)
**/
//way1: using recursive methods! log(n)的复杂度！
class Solution {
public:
    int MinInt=(numeric_limits<int>::min)();
    int MaxInt=(numeric_limits<int>::max)();
    double myPow(double x, int n) {
        if(n==0)
          return 1;
        
        if(n<0){
            if (n == MinInt)
                return 1/(myPow(x,MaxInt)*x);
            else
                return 1/myPow(x,-n);
         }
        else{
            if (n%2==0){
                double temp = myPow(x,n>>1);
                return temp*temp;
            }
            else{
                double temp = myPow(x,(n-1)>>1);
                return x*temp*temp;
            }
        }
    }
};
//way2:该方法通过扫描n的二进制表示形式里不同位置上的1，来计算x的幂次
class Solution {
public:
    int MinInt=(numeric_limits<int>::min)();
    int MaxInt=(numeric_limits<int>::max)();
    double myPow(double x, int n) {
        if(n==0)
          return 1;
        
        if(n<0){
            if (n == MinInt)
                return 1/(myPow(x,MaxInt)*x);
            else
                return 1/myPow(x,-n);
         }
        double ans = 1.0;
        for(;n>0;x*=x,n>>=1){
            if (n&1 ==1)
                ans *= x;
        }
        return ans;
    }
};