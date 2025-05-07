class Solution:
    def maxArea(self, height: List[int]) -> int:
        r = len(height) - 1
        l, res = 0, 0
        while l < r:
            area = (r - l) * min(height[l], height[r])
            res = max(res, area)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return res
