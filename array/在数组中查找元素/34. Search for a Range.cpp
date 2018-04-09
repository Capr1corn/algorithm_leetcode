/*
给定一个已经升序排序的整形数组，找出给定目标值的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果在数组中找不到目标，返回 [-1, -1]。

例如:
给出 [5, 7, 7, 8, 8, 10] 和目标值 8，
返回 [3, 4]。



解题思路：
因为题目限制时间复杂度，基本可以确定为使用二分法
使用两次二分法，第一次查找左边界，第二次查找右边界




首先，建立二元结果数组res，起点start，终点end。
二分法求左边界：
当中点小于target，start移向中点，否则end移向中点；
先判断起点，再判断终点是否等于target，如果是，赋值给res[0]。
二分法求右边界：
当中点大于target，end移向中点，否则start移向中点；
先判断终点，再判断起点是否等于target，如果是，赋值给res[1]。
返回res。

*/


//代码实现

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);//初始化数组，为（-1，-1）
        if(nums.empty()) return res;

        int left=0,right=nums.size()-1;


        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]<target)left=mid+1;
            else right=mid;   //以后的二分法就是  right=mid 了
        }
        //以上求的结果，mid为小于target中最大的值

        if(nums[right]!=target)return res; //
        res[0]=right;
        right=nums.size();
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]<=target)left=mid+1;
            else right=mid;
        }
        res[1]=left-1;
        return res;
        
    }
};