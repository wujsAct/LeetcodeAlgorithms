/***
 *@time: 2016/11/1 
 *@function:�����������������λ��
 *˼·���������ҵ���kС��������λ�����൱���ǵ�(m+n)/2С����
 * ��������A��B�ĳ��ȶ�������k/2
 * A[k/2-1] < B[k/2-1],��ôA[k/2-1]�����ܴ���������ϲ���ĵ�k�����ֵ,��˿��Խ���������
 * ͬ��A[k/2-1] > B[k/2-1];��ôB[k/2-1]�����ܴ���������ϲ���ĵ�k�����ֵ,��˿��Խ���������������ʹ�÷�֤��ȥ֤����
 * A[k/2-1] == B[k/2-1]���ҵ���k�����ֵ�ˡ�
 * �߽�������1�����A����BΪ�գ���ô����A[k-1], 2)kΪ1������A[0]��B[0]��С����һ����3�����A[k-1]==B[k-1]�򷵻�����һ����
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