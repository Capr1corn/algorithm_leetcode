/*
给一组候选数字（C）（没有重复）并给一个目标数字（T），
找出 C 中所有唯一的组合使得它们的和为 T。
可以从 C 无限次数中选择相同的数字。

说明：
所有数字（包括目标）都是正整数。
解集合中没有相同组合。
 
例如，给一个候选集合 [2, 3, 6, 7] 并且目标为 7，
一个解的集合为：
[
  [7],
  [2, 2, 3]
]




解题思路：
这些题目发现都是一个套路，都是需要另写一个递归函数，
这里我们新加入三个变量，start记录当前的递归到的下标，
out为一个解，res保存所有已经得到的解，
每次调用新的递归函数时，
此时的target要减去当前数组的的数，



原题是说给定一些数字和一个目标值，从这些数字中挑选几个加起来，
加起来后他的和正好等于目标值，其中一个数字可以选择多次。
要求输出的不能有重复，并且组内的顺序是不能降序的。

这道题首先必须要想到的就是排序了，排序是非常基本，又非常常用的一种操作。

然后我们需要排除重复的（注意可以重复选择一个数，所以重复的最好先去掉，
因为我们需要进行递归回溯，这样做可以降低无谓的开销）

随后我们就开始求解，求解的做法是采用递归的回溯，
每一次递归传递还需要的数值reserve，同时记录已经选择的数字，
原则上当前选择的数字需要大于等于上一个，所以再加上一个index表示可以从哪个索引开始选择。

然后遇到reserve为0就加入最终结果，遇不到就不加咯~~~


*/


//代码实现

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(),candidates.end());
        combinationSumCore(candidates,target,0,out,res);
        return res;
    }
    
    void combinationSumCore(vector<int> &candidates,int target,int start,vector<int> &out,vector<vector<int>> &res){
        
        if(target<0) return ;
        else if(target==0) res.push_back(out);
        else{
            for(int i=start;i<candidates.size();++i){
                out.push_back(candidates[i]);
                combinationSumCore(candidates,target-candidates[i],i,out,res);
                out.pop_back();
            }
        }
        
    }
};