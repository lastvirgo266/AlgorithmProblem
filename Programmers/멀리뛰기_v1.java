class Solution {
    public long solution(int n) {
        long answer = 0;
        long[] memoi = new long[n+1];
        
        if(n == 1)
            return 1;
        
        for(int i=0; i<=n; i++)
            memoi[i] = 0;
        
        memoi[1] = 1;
        memoi[2] = 1;
        
        for(int i=1; i<=n; i++){
            if(i - 1 > 0)
                memoi[i] = (memoi[i] +memoi[i-1])  % 1234567;
            
            if(i - 2 > 0)
                memoi[i] = (memoi[i] + memoi[i-2]) % 1234567;
        }
        
        
        return answer=memoi[n];
    }
}