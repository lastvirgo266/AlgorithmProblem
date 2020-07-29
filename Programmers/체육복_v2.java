import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int count =0;
        int len = lost.length;
        
        List<Integer> lostList = new ArrayList<>();
        List<Integer> store = new ArrayList<>();
        
        
        for(int i=0; i<reserve.length; i++){
            store.add(reserve[i]);
        }
        
        for(int i=0; i<lost.length; i++){
            if(store.contains(lost[i])){
                store.remove(Integer.valueOf(lost[i]));
                len--;
            }
            else lostList.add(lost[i]);
        }
        
        for(int val : lostList){
            if(store.contains(val+1)){
                store.remove(Integer.valueOf(Integer.valueOf(val+1)));
                count++;
            }
            
            else if(store.contains(val-1)){
                store.remove(Integer.valueOf(Integer.valueOf(val-1)));
                count++;
            }
        }
        
        System.out.println(count);
        
        answer = n - len + count;
        
        return answer;
    }
}