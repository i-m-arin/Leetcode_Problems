class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        # If not possible to form into 1 pile return -1.
        if (len(stones) - 1) % (k - 1) != 0: return -1

        # Create a prefix sum array of stones array.
        preArr = [0]
        for pile in stones:
            preArr.append(preArr[-1] + pile)

        # If not possible to form into 1 pile return -1.
        if (len(stones) - 1) % (k - 1) != 0: return -1

        # Create a dp array.
        dp = [[0 for _ in range(len(stones))] for _ in range(len(stones))]

        # Iterate over every possible subarray of the current array.
        for start in range(len(stones) - 1, -1, -1):
            for end in range(start + k - 1, len(stones)):

                dp[start][end] = maxsize

                for i in range(start, end, k - 1):

                    # Get the cost of first pile from the left of the subarray.
                    firstPile = dp[start][i]

                    # Cost of the rest of the subarray.
                    otherPiles = dp[i + 1][end]

                    # If the whole subarray can be converted into 1 pile no need to add the sum of all elements.
                    mergeCost = 0 if (end - start) % (k - 1) != 0 else preArr[end + 1] - preArr[start]

                    dp[start][end] = min(dp[start][end], firstPile + otherPiles + mergeCost)

        return dp[0][len(stones) - 1]

