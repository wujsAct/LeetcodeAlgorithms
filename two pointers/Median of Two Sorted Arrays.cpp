/***
 *@time: 2016/11/1 
 *@function:找两个有序数组的中位数
 *思路：核心是找到第k小的数，中位数就相当于是第(m+n)/2小的数
 * 假设数组A和B的长度都超过了k/2
 * A[k/2-1] < B[k/2-1],那么A[k/2-1]不可能大于两数组合并后的第k大的数值,因此可以将其抛弃；
 * 同理A[k/2-1] > B[k/2-1];那么B[k/2-1]不可能大于两数组合并后的第k大的数值,因此可以将其抛弃；（可以使用反证法去证明）
 * A[k/2-1] == B[k/2-1]就找到第k大的数值了。
 * 边界条件，1）如果A或者B为空，那么返回A[k-1], 2)k为1，返回A[0]和B[0]较小的那一个。3）如果A[k-1]==B[k-1]则返回其中一个！
 ***/

class Solution {
public:
    double findkth(vector<int>& A,int m,vector<int>& B, int n,int k){
        if(m>=A.size()){
            return B[n+k-1];
        }
        if(n>=B.size()){
            return A[m+k-1];
        }
        if(k==1) return A[m]>B[n]?B[n]:A[m];
        int A_key = m + k / 2 - 1 >= A.size() ? INT_MAX : A[m + k / 2 - 1];
        int B_key = n + k / 2 - 1 >= B.size() ? INT_MAX : B[n + k / 2 - 1];
        if(A_key<B_key){
            return findkth(A,m+k/2,B,n,k-k/2);
        }
        else{
            return findkth(A,m,B,n+k/2,k-k/2);
        }
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m+n;
        cout<<total<<endl;
        if(total%2==0){
            return (findkth(nums1,0,nums2,0,total/2)+findkth(nums1,0,nums2,0,total/2+1))/2.0;
        }
        else{
            cout<<total<<endl;
            return findkth(nums1,0,nums2,0,total/2+1);
        }
        
    }
};