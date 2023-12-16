class Solution {
public:
    string addBinary(string a, string b) {
        int lenDiff = a.length()-b.length();
        int aEnd = a.length()-1;
        int bEnd = b.length()-1;
        int maxL,minL,decide=0;
        if(lenDiff>0){
            maxL = aEnd;
            minL = bEnd;
        }
        else if(lenDiff<0){
            maxL = bEnd;
            minL = aEnd;      
            decide =1;
        }
        else{
            decide = 2;
        }
        
        int flag = 0;
        string s;
        for(int i = 0; i<=minL;i++){
            if(flag){
            if(a[aEnd-i]=='0'&& b[bEnd-i]=='0'){
                s = "1" +s;
                flag=0;
            }
            else if((a[aEnd-i]=='0'&& b[bEnd-i]=='1') || (a[aEnd-i]=='1'&& b[bEnd-i]=='0')){
                flag =1;
                s = "0" +s;
            }
            else if(a[aEnd-i]=='1'&& b[bEnd-i]=='1'){
                s = "1" +s;
                flag = 1;
            }    
            }
            else{
            if(a[aEnd-i]=='0'&& b[bEnd-i]=='0'){
                s = "0" +s;
            }
            else if((a[aEnd-i]=='0'&& b[bEnd-i]=='1') || (a[aEnd-i]=='1'&& b[bEnd-i]=='0')){
                s = "1" +s;
            }
            else if(a[aEnd-i]=='1'&& b[bEnd-i]=='1'){
                s = "0" +s;
                flag = 1;
            }    
            }          
        }
        
        if(decide==1){
        for(int i=minL+1; i<=maxL;i++){
            if(flag){
              if(b[maxL-i]=='0'){
                  s = "1" +s;
                  flag=0;
              }
                else{
                    s= "0"+s;
                    
                }
            }
            else{
                flag=0;
                s = b.substr(0,maxL-i+1) + s;
                break;
            }
        }
           
        }
        else if(decide == 0){
         for(int i=minL+1; i<=maxL;i++){
            if(flag){
              if(a[maxL-i]=='0'){
                  s = "1" +s;
                  flag=0;
              }
                else{
                    s= "0"+s;
                    
                }
            }
            else{
                flag=0;
                s = a.substr(0,maxL-i+1) + s;
                break;
            }
        }
            
        }
        if(flag) s = "1" + s;
        return s;
     
    }
};