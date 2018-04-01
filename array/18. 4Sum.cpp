/*
给定一个含有 n 个整数的数组 S，数列 S 中是否存在
元素 a，b，c 和 d 使 a + b + c + d = target ？

请在数组中找出所有满足各元素相加等于特定值 的 不重复 组合。

注意：解决方案集不能包含重复的四元组合。

例如，给定数组 S = [1, 0, -1, 0, -2, 2]，并且给定 target = 0。

示例答案为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]




解题思路：
分别是Two Sum 两数之和，3Sum 三数之和，3Sum Closest 最近三数之和，
虽然难度在递增，但是整体的套路都是一样的，在这里为了避免重复项，我们使用了STL中的set，其特点是不能有重复，
如果新加入的数在set中原本就存在的话，插入操作就会失败，这样能很好的避免的重复项的存在。
此题的O(n^3)解法的思路跟3Sum 三数之和基本没啥区别，就是多加了一层for循环，其他的都一样，

*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }


    -------未完待续