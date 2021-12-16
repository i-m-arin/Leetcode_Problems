class Solution:
    def findPeakElement(self, arr: List[int]) -> int:
        if len(arr) == 1: return 0

        i = 0

        # Iterate over all elements of the array.
        while i < len(arr) - 1:

            # If we are checking the first element of the array.
            if i == 0 and arr[i] > arr[i + 1]:
                return i

            # Checking the rest of the elements of the array.
            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                return i

            i += 1

        return len(arr) - 1
