import java.util.*;


class Solution {
    public int solution(int[] food_times, long k) {
        int answer = -1;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i=0; i<food_times.length; i++){
            map.put(i+1, food_times[i]);
        }
        
        
        Iterator keys = sortByValue(map).iterator();
        
        long pretime = 0;
        
        while(keys.hasNext()){
            int key = (int)keys.next();
            long value = map.get(key);
            
            long diff = value - pretime;
            
            if(diff == 0){
                map.remove(key);
                continue;
            }
            
            long spend = diff*(long)map.size();
            
            
            if(k >= spend ){
                k -= spend;
                map.remove(key);
                pretime = value;
            }
            
            else{
                k %= (long)map.size();
                
                Iterator<Integer> itr = map.keySet().iterator();
                
                int ans = -1;
                while(itr.hasNext()){
                    ans = itr.next();
                    if(k == 0)
                        break;
                    k--;
                }
                return ans;
                
            }
        }
        return answer;
    }
    
    
    public static List sortByValue(final Map map) {

        List<Integer> list = new LinkedList();

        list.addAll(map.keySet());

        Collections.sort(list,new Comparator() {             
            
            @Override
            public int compare(Object o1,Object o2) {
                Object v1 = map.get(o1);
                Object v2 = map.get(o2);
                return ((Comparable) v1).compareTo(v2);

            }
        });

        //Collections.reverse(list);
        return list;
    }
    
}