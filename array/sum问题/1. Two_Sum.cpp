/*
给定一个整数数列，找出其中和为特定值的那两个数。

你可以假设每个输入都只会有一种答案，同样的元素不能被重用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]




解题思路：
运用无序map,按数列顺序遍历查找 ，队列中是否存在与target -i  相等的值
如果存在则将结果放入到新创建的数组中，不存在，则++i,然后将nums[i] 的值存放到hashmap中


map<key,value>         map[k]    ->返回关键字为K的元素
*/

//函数实现
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;//c++中的hashmap实现，查找速度快
        vector<int> res;

        /*map.find(需要find的值) 如果找到则返回此元素的迭代器，
            若没有找到则返回end()的迭代器（即查找到尾部都没有找到）*/
        for(size_t i=0;i<nums.size();++i){
            int number=target-nums[i];
            if(map.find(number)!=map.end()){
                res.push_back(i);
                res.push_back(map[number]);
                return res;
            }
            map[nums[i]]=i;//这里是用下标作为key，用下标的值对应value。
            
            
        }
        return res;
        
    }
};