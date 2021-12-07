class Solution:
    
    def possiblePosition(self, stones: List[int], currPos: int, positionMap: Dict[int, int], lastStep: int, cache: List[List[int]]) -> int:

        # If current position is the last stone.
        if currPos == stones[-1]:
            return 1

        # If currPos is not a stone or greater than the last stone return false.
        if (not positionMap[currPos]) or currPos > stones[-1] or lastStep == 0:
            return 0

        if cache[positionMap[currPos]][lastStep] != -1:
            return cache[positionMap[currPos]][lastStep]


        # Calculate and store answer for all possible steps.
        cache[positionMap[currPos + lastStep - 1]][lastStep - 1] = self.possiblePosition(stones, currPos + lastStep - 1, positionMap, lastStep - 1, cache)
        cache[positionMap[currPos + lastStep]][lastStep] = self.possiblePosition(stones, currPos + lastStep, positionMap, lastStep, cache)
        cache[positionMap[currPos + lastStep + 1]][lastStep + 1] = self.possiblePosition(stones, currPos + lastStep + 1, positionMap, lastStep + 1, cache)

        # Return the OR of all possible steps.
        return (cache[positionMap[currPos + lastStep - 1]][lastStep - 1] or
                cache[positionMap[currPos + lastStep]][lastStep] or
                cache[positionMap[currPos + lastStep + 1]][lastStep + 1])

    
    def canCross(self, stones: List[int]) -> bool:
        # If the first step can't be made.
        if stones[1] - stones[0] != 1:
            return False

        # If array is of length 2 only 1 step is required.
        if len(stones) == 2 and stones[1] - stones[0] == 1:
            return True

        # Create a set of all stone positions.
        positionMap = defaultdict(int)

        cache = [[-1 for _ in stones] for _ in stones]

        for index, pos in enumerate(stones):
            positionMap[pos] = index

        # Return the recursive function.
        return True if self.possiblePosition(stones, stones[1], positionMap, 1, cache) else False
