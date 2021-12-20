class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        
        # Intialise a max heap.
        maxHeap = list()

        for row in mat:
            for num in row:

                # In python heap is always min heap, so to have max heap we can store the numbers as negative.
                heapq.heappush(maxHeap, -num)

                # If more than K elements are present in the heap.
                if len(maxHeap) > k:
                    heapq.heappop(maxHeap)

        # Return the top of the heap.
        return -heapq.heappop(maxHeap)
        