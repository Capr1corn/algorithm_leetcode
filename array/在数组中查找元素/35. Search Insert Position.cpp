/*给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。
如果没有，返回到它将会被按顺序插入的位置。
你可以假设在数组中无重复元素。

案例 1: 输入: [1,3,5,6], 5  输出: 2
案例 2: 输入: [1,3,5,6], 2  输出: 1
案例 3: 输入: [1,3,5,6], 7  输出: 4
案例 4: 输入: [1,3,5,6], 0  输出: 0

解题思路：
采用二分法查找，如果找到则返回下标，
如果没找到，就说明


*/

//代码实现

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left=0,right=nums.size()-1;
        while (left < right) {
            int mid = (right+left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;

            else right = mid;
            //将mid赋值给right，如果没有找到的话，最后位置是right
        }
        return right;
        
    }
};