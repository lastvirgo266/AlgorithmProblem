import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = {};
        
        HashMap<Integer, Integer>  total =new HashMap<>();
        HashMap<Integer, Integer>  cur =new HashMap<>();
        HashMap<Integer, Double>  fail =new HashMap<>();
        
        for(int i=1; i<=N+1; i++){
            total.put(i,0);
            cur.put(i,0);
            fail.put(i, (double)0);
        }
        
        
        for(int i=0; i<stages.length; i++){
            
            cur.put(stages[i], cur.get(stages[i])+1);
            
            for(int j=1; j<=stages[i]; j++){
                total.put(j, total.get(j)+1);
            }
            
        }
        
        
        for(int i=1; i<=N; i++){
            
            if(total.get(i) == 0)
                fail.put(i,(double)0);
            else
                fail.put(i, (double)cur.get(i)/(double)total.get(i));
        }
        
        Iterator it = sortByValue(fail).iterator();
        
        answer = new int[N];
        int i = N-1;
        
        while(it.hasNext()) {
            int key = (Integer)it.next();
            if(key == N+1)
                continue;
            
            answer[i] = key;
            i--;
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
        
        Collections.reverse(list);

        return list;

    }
        
}