class Solution:
    def partitionDisjoint(self, arr: List[int]) -> int:
        # Set the initital parition index as 0.
        partitionIndex = 0
        localMaximum = overallMax = arr[0]

        # Iterate through the array.
        for i, num in enumerate(arr):

            # Update the overall maximum.
            overallMax = max(num, overallMax)

            # If current number is smaller than localMaximum update it as overallMax.
            if num < localMaximum:
                localMaximum = overallMax

                # Set this as current index.
                partitionIndex = i

        return partitionIndex + 1
