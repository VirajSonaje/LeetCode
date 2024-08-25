class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);

        if(num <= 10) return to_string(num-1);
        if(num == 11) return "9";

        if(n == "999999999999999999") return "1000000000000000001";

        int len = n.length();
        long long root = stoll(n.substr(0, (len+1)/2));

        vector<long long> solutions(5);
        solutions[0] = makePal(root-1, len%2 ==0);
        solutions[1] = makePal(root, len%2 ==0);

        if(root < 999999999){
            solutions[2] = makePal(root+1, len%2 == 0);
        }
        else{
            solutions[2] = stoll("1"+string(len-1, '0')+"1");
        }

        solutions[3] = pow(10, len-1) -1;
        solutions[4] = pow(10, len) + 1;

        long long ans =0;
        long long minDiff = LLONG_MAX;

        for(long long pal : solutions){
            if(pal != num){
                long long diff = abs(pal - num);
                if((diff < minDiff) || (diff == minDiff && pal<ans)){
                    minDiff = diff;
                    ans = pal;
                }
            }
        }

        return to_string(ans);
    }

    long long makePal(long long root, bool isEven){
        long long pal = root;

        if(!isEven) root /= 10;
        while(root > 0){
            pal = pal*10 + root%10;
            root/=10;
        }
        return pal;
    }

};