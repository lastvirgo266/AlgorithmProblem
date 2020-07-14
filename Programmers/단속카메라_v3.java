import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 1;
        
        Arrays.sort(routes, Comparator.comparingInt(o1 -> o1[0]));
        
        
        int tmp = routes[0][1]; 
        
        for (int i = 0; i < routes.length-1; i++) { 
            if (tmp > routes[i][1]) tmp = routes[i][1]; 
            if (tmp < routes[i + 1][0]) { 
                answer += 1; tmp = routes[i + 1][1]; 
            } 
        }
        
        
        return answer;
    }
}