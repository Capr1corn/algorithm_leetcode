/*
给定一个包括 n 个整数的数组 S，找出 S 中的三个整数使得他们的和与给定的数 target 最接近。返回这三个数的和。假定每组输入只存在一个答案。

例如，给定数组 S = {-1 2 1 -4}, 并且 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).





解题思路：
先将给定数列排序，任意三个数相加的和来和target做绝对值减法，
每次做完减法之后，将num 里的值与


是在之前那道 3Sum 三数之和的基础上又增加了些许难度，
那么这道题让我们返回这个最接近于给定值的值，
即我们要保证当前三数和跟给定值之间的差的绝对值最小，
所以我们需要定义一个变量diff用来记录差的绝对值，
然后我们还是要先将数组排个序，然后开始遍历数组
，思路跟那道三数之和很相似，都是先确定一个数，
然后用两个指针left和right来滑动寻找另外两个数，
每确定两个数，我们求出此三数之和，
然后算和给定值的差的绝对值存在newDiff中，
然后和diff比较并更新diff和结果closest即可，代码如下：
*/

//代码实现1

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
        int closet=nums[0]+nums[1]+nums[2];//先保存前三个数的和
        int diff=abs(closet-target);//计算差值的绝对值，通过差值绝对值来比较
       //绝对值较小的，保存到closet中
        for(int i=0;i<nums.size()-2;++i){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                int newDiff=abs(sum-target);
                if(diff>newDiff){
                    diff=newDiff;
                    closet=sum;
                }
                if(sum<target)++left;
                else --right;
            }
            
        }
        return closet;
    }