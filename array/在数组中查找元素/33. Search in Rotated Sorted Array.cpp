/*
假设按照升序排序的数组在预先未知的某个关键点上旋转。

（即 0 1 2 4 5 6 7 将变成 4 5 6 7 0 1 2）。

给你一个目标值来搜索，如果数组中存在这个数则返回它的索引，否则返回 -1。

你可以假设数组中不存在重复。



解题思路：
如果是个普通的递增数组，那么直接用二分查找就ok了。本题并不是一个严格递增的序列，但是仍然可以用二分查找去做。

二分查找的核心是取两端元素的中间节点mid，
本题可以在获取了mid之后和两端元素对比。如果左边元素小于mid，那么mid一定是落在了右面的递增序列中；
反之一定是落在了左边。
target是要查找的值，知道了mid在哪边之后，就可以拿边界值和target做对比得到两种特殊情况：

落在右端时，如果target大于右端最大值，那么要查找的一定在左端；
落在左端时，如果target小于左端最小值，那么要查找的一定在右端。
除去这两种特殊情况之后，直接简单的用二分查找进行处理就可以了。

*/


//实现代码


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
      //  int length=nums.size();
        while(left<=right){  //开始时采用普通的二分查找法
           int mid=(left+right)/2;
            
            if(target==nums[mid])
                return mid;

            if(nums[mid]>nums[right]){//因为有反转存在，所以需要判断下中值与右值的大小
            	//如果中值大于右值，则说明，反转部分在右，
                if(target<nums[mid]&&target>=nums[left])right=mid-1;
                //然后需要判断一下目标值与中值的大小，如果目标值小于中值且目标值大于最左值，则在右端
                else left=mid+1;
            }else if(nums[mid]<nums[left]){
            	//同理
                if(target>nums[mid]&&target<=nums[right]) left=mid+1;
                else right=mid-1;
            }else {
                if(target<nums[mid]) right=mid-1;
                else left=mid+1;
            }  
        }
    return -1;
    }
};