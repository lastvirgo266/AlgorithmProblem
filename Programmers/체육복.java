import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n;
        int[] store = new int[lost.length + reserve.length];
        
        for(int i=0; i<reserve.length; i++){
            store[i] = reserve[i];
        }
        
        int j =reserve.length;
        for(int i=0 ; i<lost.length; i++){
            store[i+j] = lost[i];
        }
        
        Arrays.sort(store);
        
        
        for(int i=0; i<store.length; i++){
            if(store[i] == -1)
                continue;
            
            if(i+1<store.length){
                if(store[i+1] - store[i] == 1){
                    store[i] = -1;
                    store[i+1] = -1;
                    answer--;
                }
            }
        }
        
        
        return answer;
    }
}