class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        
        
        sortedAngles = []

        sameAsStart = 0

        for point in points:

            # If the point is at the same location as the start point.
            if point[0] == location[0] and point[1] == location[1]:
                sameAsStart += 1
                continue

            pointAngle = math.atan2(point[1] - location[1], point[0] - location[0])

            sortedAngles.append(pointAngle)

        # Sort the angles.
        sortedAngles.sort()

        # Insert all the elements of the array again at the back of the array to make it cyclic.
        # We add 2*pi or 360 degrees to each angle because we have completed a cycle.
        sortedAngles = sortedAngles + [pointAngle + 2.0 * math.pi for pointAngle in sortedAngles]

        left  = 0
        solution = 0

        for right in range(len(sortedAngles)):

            # Increase the window size.
            while sortedAngles[right] - sortedAngles[left] > angle*math.pi / 180:
                left += 1

            # Update the solution.
            solution = max(solution, right - left + 1)

        return solution + sameAsStart
