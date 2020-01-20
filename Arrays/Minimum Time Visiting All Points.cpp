// Source : https://leetcode.com/problems/minimum-time-visiting-all-points/
// Author : Saravana Kumar


/*On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.
 

Example 1:

Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000

***************************************************************************************************************/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size() - 1; i++) //Since we are taking difference between two points, we should stop 1 lower than its size
        {             
            int diffx = abs(points[i][0] - points[i + 1][0]);     //2d vector: [points[0][0]  points[1][0]                                           
            int diffy = abs(points[i][1] - points[i + 1][1]);     //            points[0][1]  points[1][1]]
            ans += max(diffx, diffy); //Gives the maximum value
        }
        return ans;
    }
};

/*Explanation:

Example: Given two points,
[x1,y1] = [3,2]
[x2,y2] = [-2,2]

The idea to move from [3,2] to [-2,2] with a minimum time is,

step1: abs(x1 -x2) = value 1 ------------> abs(3+2) = abs(5) = 5 sec
step2: abs(y1 - y2) = value 2 -----------> abs(2-2) = abs(0) = 0 sec
step 3: Minimum time taken = (Maximum value between value 1 and value 2) seconds ----------> max(5,0) = 5 seconds //Output






