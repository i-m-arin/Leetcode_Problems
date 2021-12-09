class Solution:
    
    def minDifficulty(self, arr: List[int], k: int) -> int:
        
        MAX = 2**31 - 1

        n = len(arr)
        if k > n:
            return -1
        # Create two arrays two store the values.
        currArr  = [MAX for _ in range(n)]
        nextArr = [0 for _ in range(n)]

        for split in range(k):

            # Intitialise empty stack.
            stack = []

            # We will start from split.
            # It's because we need minimum of X elements to form x more subarrays.
            for i in range(split, n):

                # Update the next subarray's split.
                nextArr[i] = currArr[i - 1] + arr[i] if i else arr[i]

                # Update the values from the stack.
                # Arr[stack[-1]] will be last number larger than arr[i].
                while len(stack) > 0 and arr[stack[-1]] <= arr[i]:
                    j = stack.pop()
                    nextArr[i] = min(nextArr[i], nextArr[j] - arr[j] + arr[i])

                if len(stack) > 0:
                    nextArr[i] = min(nextArr[i], nextArr[stack[-1]])

                # Insert current split index in the stack.
                stack.append(i)

            # Swap the arrays.
            currArr, nextArr = nextArr, currArr

        return currArr[-1]
