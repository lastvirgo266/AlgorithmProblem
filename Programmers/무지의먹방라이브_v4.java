import java.util.*;


class Solution {
    class Food{
        int time;
        int idx;
        
        Food(int t, int i){
            time = t;
            idx = i;
        }
        
    }
    
    
    public int solution(int[] food_times, long k) {
        int answer = -1;
        List<Food> foods = new LinkedList<Food>();
        HashMap<Integer, Integer> map = new LinkedHashMap<>();
        
        for(int i=0; i<food_times.length; i++){
            foods.add(new Food(food_times[i], i+1));
            map.put(i+1, food_times[i]);
        }
        
        Comparator <Food> CompTime = new Comparator<Food>(){
            @Override
            public int compare(Food a, Food b){
                return a.time- b.time;
            }
        };
        
        Comparator <Food> CompIdx = new Comparator<Food>(){
            @Override
            public int compare(Food a, Food b){
                return a.idx- b.idx;
            }
        };
        
        foods.sort(CompTime);
        
        long pretime = 0;
        int i = 0;
        int n = food_times.length;
        
        for(Food f : foods){
            
            long diff = f.time - pretime;
            
            if(diff == 0){
                i++;
                n--;
                map.remove(f.idx);
                continue;
            }
            
            long spend = diff*n;
            
            
            if(k >= spend ){
                k -= spend;
                map.remove(f.idx);
                pretime = f.time;
            }
            
            else{
                k %= map.size();
                
                foods.subList(i, food_times.length).sort(CompIdx);
                // return foods.get(i+(int)k).idx;
                
                Iterator<Integer> itr = map.keySet().iterator();
                int test = 0;
                int ans = -1;
                while(itr.hasNext()){
                    ans = itr.next();
                    

                    
                    if(test == k)
                        break;
                    test++;
                }
                return ans;
                
            }
            
            i++;
            n--;
        }
        return answer;
    }
    
}