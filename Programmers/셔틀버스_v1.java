import java.util.*;

class Solution {
    class Time{
        int hour;
        int minute;
        
        public Time(int hour, int minute){
            this.hour = hour;
            this.minute = minute;
        }
        
    }
    
    
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        
        Time[] timeArrays = new Time[timetable.length];
        Queue q = new LinkedList();
        
        for(int i=0; i<timetable.length; i++){
            
            String[] temp = timetable[i].split(":");
            
            timeArrays[i] = new Time(Integer.parseInt(temp[0]), Integer.parseInt(temp[1]));
            
        }
        
        Arrays.sort(timeArrays, new Comparator<Time>(){
            public int compare(Time n1, Time n2){
                if(n2.hour == n1.hour)
                    return n1.minute - n2.minute;
                else{
                    return n1.hour - n2.hour;
                }
            }
        });
        
        for(int i=0; i<timeArrays.length; i++)
            q.offer(timeArrays[i]);
        
        Time bus = new Time(9,0);
        
        while(!q.isEmpty()){
            Time in = null;
            
            int i =0;
            int inPeople = 0;
            
            
            for(i=1; i<=m && q.size() >=1; i++){
                Time temp = (Time)q.peek();
                
                if(bus.hour > temp.hour){
                    in = (Time)q.poll();
                    inPeople++;
                }
                else if(bus.hour == temp. hour){
                    if(bus.minute >= temp.minute){
                        in = (Time)q.poll();
                        inPeople++;
                    }
                    else
                        break;
                }
                
                else
                    break;
            }
            
            
            
            n--;
            
            if(n == 0){
                String ansHour;
                String ansMinute;
                
                if(in != null && inPeople == m){
                    in.minute--;
                    if(in.minute < 0){
                        in.minute += 60;
                        in.hour--;
                    }

                    ansHour = Integer.toString(in.hour);
                    ansMinute = Integer.toString(in.minute);
                                            
                }
                
                else{
                    ansHour = Integer.toString(bus.hour);
                    ansMinute = Integer.toString(bus.minute);
                }
                
                if(ansHour.length() != 2){
                    String temp = "0";
                    ansHour = temp.concat(ansHour);
                }
                
                if(ansMinute.length() != 2){
                    String temp = "0";
                    ansMinute = temp.concat(ansMinute);
                }
                
                System.out.println(ansHour+":"+ansMinute);
                return ansHour+":"+ansMinute;
                
            }
            
            bus.minute += t;
            if(bus.minute >= 60){
                bus.minute -=60;
                bus.hour++;
            }
            
        }
        
            
            
        
        
        return answer;
    }
}