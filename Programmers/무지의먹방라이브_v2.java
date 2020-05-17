import java.util.*;


class Solution {
    public int solution(int[] food_times, long k) {
        int answer = -1;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i=0; i<food_times.length; i++){
            map.put(i+1, food_times[i]);
        }
        
        
        Iterator keys = sortByValue(map).iterator();
        
        long total = 0;
        int i = 0;
        
        while(keys.hasNext()){
            int key = (int)keys.next();
            long value = map.get(key);
            
            if(k < (long)(map.size()-i))
                break;
            
            
            else if(value - total == 0){
                food_times[key-1] = 0;
                i++;
                continue;
            }
            
            
            if(k - (long)(value - total)*(long)(map.size()-i) >= 0 ){
                food_times[key-1] = 0;
                k -= (long)(value - total)*(long)(map.size()-i);
            }
            
            
            else {
                if(value - total > 1){
                    for(long j = value-1; j>=1; j--){
                        if(k - (long)(j - total)*(long)(map.size()-i) >= 0){
                            k -=(long)(j - total)*(long)(map.size()-i);
                            if(k ==0)
                                break;
                            i++;
                            total += (k - total);
                            continue;
                        }
                    }     
                }
            }
            
            
            if(k == 0)
                break;
            
            total += (value - total);
            i++;
        }
        
        
        for(int j=0; j<food_times.length; j++){
            
            
            if((long)food_times[j] - total <=0)
                food_times[j] = 0;
            
            if(food_times[j] == 0)
                continue;
            
           if( k == 0)
               return j+1;
            
            k--;
            food_times[j]--;

        }
        
        
        return answer;
    }
    
    
    public static List sortByValue(final Map map) {

        List<Integer> list = new ArrayList();

        list.addAll(map.keySet());

        Collections.sort(list,new Comparator() {             

            public int compare(Object o1,Object o2) {
                Object v1 = map.get(o1);
                Object v2 = map.get(o2);
                return ((Comparable) v2).compareTo(v1);

            }

             

        });

        Collections.reverse(list); // 주석시 오름차순
        return list;
    }
    
}