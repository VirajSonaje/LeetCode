class AuthenticationManager {
private: 
    int ttl;
    unordered_map<string, int> tokens;
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokens.count(tokenId) != 0 && tokens[tokenId] > currentTime){
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count =0;
        for(auto it: tokens){
            if(it.second > currentTime) count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */