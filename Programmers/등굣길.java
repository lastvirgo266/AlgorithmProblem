class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        int[][] dp = new int[m+1][n+1];
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++)
                dp[i][j] = 0;
        }
        
        for(int i=0; i<puddles.length; i++){
            dp[puddles[i][0]][puddles[i][1]] = -1;
        }

        
        dp[1][1] = 1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][j] != -1){
                    int newX = (i+1) % 1000000007;
                    int newY = (j+1) % 1000000007;

                    if(1<= newX && newX <=m && dp[newX][j] != -1)
                        dp[newX][j] = (dp[newX][j] + dp[i][j]) % 1000000007;

                    if(1<= newY && newY <=n && dp[i][newY] != -1)
                        dp[i][newY] = (dp[i][newY] + dp[i][j]) % 1000000007;
                }
            }
        }
        
        answer = dp[m][n];
        
        return answer;
    }
}