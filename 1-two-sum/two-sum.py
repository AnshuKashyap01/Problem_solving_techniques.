class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        dic = {}

        for i,x in enumerate(nums):
            k = target-x
            if k in dic:
                return [dic[k],i]
            dic[x]=i




        