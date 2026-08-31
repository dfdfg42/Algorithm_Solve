class Solution {
    
    public char getNextRank(char input){
        
        if(input =='A'){
            return 'E';
        }else if(input == 'E'){
            return 'I';
        }else if(input == 'I'){
            return 'O';
        }else if(input =='O'){
            return 'U';
        }
        
        return input;
        
    }
    
    
    public int solution(String word) {
        int answer = 0;
        
        //5개 미만이면 뒤에 A를 붙임
        //5개 이상이면 맨 뒤에 +1 , 맨뒤가 U 면 없애고 한칸 앞에를 +1 -> 될때까지
        
        String temp = "";
        
        while(!temp.equals(word)){
            
            int tempLen = temp.length();
            
            
            
            if(tempLen < 5){
                temp += "A";
            }
            else{
                
                char nextRank = 'A';
                for(int i=tempLen-1; i>=0; i--){
                    
                    char target = temp.charAt(i);
                    
                    
                    if(target == 'U'){
                        temp = temp.substring(0,temp.length()-1);
                    }
                    else{
                        nextRank = getNextRank(target);
                        break;
                    }
                }
                temp = temp.substring(0,temp.length()-1);
                temp += Character.toString(nextRank);
                
            }
            
            answer +=1;
        }
        
        return answer;
    }
}