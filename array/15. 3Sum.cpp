/*
给定一个包含 n 个整数的数组 S，是否存在属于 S 的三个元素 a，b，c 
使得 a + b + c = 0 ？找出所有不重复的三个元素组合使三个数的和为零。

注意：结果不能包括重复的三个数的组合。

例如, 给定数组 S = [-1, 0, 1, 2, -1, -4]，

一个结果集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]


解题思路：
我们要首先对原数组进行排序，然后开始遍历排序后的数组，
这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了，然后我们还要加上重复就跳过的处理，
对于遍历到的数，我们用0减去这个数得到一个sum，
我们只需要再之后找到两个数之和等于sum即可，---------将求三个数之和转化为求两数之和
这样一来问题又转化为了求two sum，这时候我们一次扫描，
找到了等于sum的两数后，加上当前遍历到的数字，按顺序存入结果中即可，然后还要注意跳过重复数字。


*/

//代码实现 1

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();++k){
            if(nums[k]>0) break;//求三个和为零的数，最小的>0时，中断
            if(k>0&&nums[k]==nums[k-1]) continue;//来控制跳过重复数字
            int target=0-nums[k];
            int i=k+1,j=nums.size()-1;
            
            while(i<j){
                if(nums[i]+nums[j]==target){
                    res.push_back({nums[k],nums[i],nums[j]});
                    while(i<j&&nums[i]==nums[i+1])++i;
                    while(i<j&&nums[j]==nums[j-1])--j;
                    ++i,--j;
                }else if(nums[i]+nums[j]<target) ++i;
                else --j;
            }
        }
        return res;
    }
};


//代码实现2--- 通过set来规避掉重复数字,代码些许差别。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.insert({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return vector<vector<int>>(res.begin(), res.end());//将set 转换为vector
    }
};