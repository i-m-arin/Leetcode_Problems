class Solution:
    
    from typing import List


    # Util function to check the validity of the solution.
    def isValidSplit(self, arr: List[int], m: int, ans: int) -> bool:

        splits, currSum = 0, 0

        for num in arr:
            currSum += num

            # If the current sub array sum is greater than answer increase the split.
            if currSum > ans:

                splits += 1
                currSum = num

        # If the number of splits are greater than M return false.
        return splits + 1 <= m
    def splitArray(self, arr: List[int], m: int) -> int:
        # Set initial answer as -1.
        ans = -1

        # Set the maximum and minimum possible answer.
        low = max(arr)
        high = sum(arr)

        while low <= high:

            # Get the mid.
            mid = (high + low) // 2

            # If mid is valid as an answer update the answer.
            if self.isValidSplit(arr, m, mid):
                ans = mid
                high = mid - 1

            else:
                low = mid + 1

        # Return the answer.
        return ans

