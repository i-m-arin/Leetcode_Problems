class Solution:
    def knightDialer(self, n: int) -> int:
        MOD = 10**9 + 7

        # For 1 digit number each key pad can be hit 1 time.
        prevNumWays = [1 for _ in range(10)]

        # Each iteration of loop will update the value for new digit in the phone number.
        for _ in range(n - 1):

            # New array to store the next iteration of value updation.
            noOfWays = [0 for _ in range(10)]

            noOfWays[0] = prevNumWays[4] + prevNumWays[6]
            noOfWays[1] = prevNumWays[6] + prevNumWays[8]
            noOfWays[2] = prevNumWays[7] + prevNumWays[9]
            noOfWays[3] = prevNumWays[4] + prevNumWays[8]
            noOfWays[4] = prevNumWays[3] + prevNumWays[9] + prevNumWays[0]
            noOfWays[5] = 0
            noOfWays[6] = prevNumWays[1] + prevNumWays[7] + prevNumWays[0]
            noOfWays[7] = prevNumWays[2] + prevNumWays[6]
            noOfWays[8] = prevNumWays[1] + prevNumWays[3]
            noOfWays[9] = prevNumWays[4] + prevNumWays[2]

            # Set the current Array as the previous one.
            prevNumWays = noOfWays


        # Return the sum of value of the array.
        return sum(prevNumWays) % MOD