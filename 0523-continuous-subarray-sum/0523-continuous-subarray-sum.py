class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if len(nums) == 1:
            return False
        mp = {}
        sum = nums[0]%k
        mp[sum] = 0
        for idx, num in enumerate(nums[1:], start=1):
            sum = (sum + num)%k
            if sum ==0 or (sum in mp and mp[sum]!=idx-1):
                return True
            elif sum not in mp:
                mp[sum] = idx
        
        return False