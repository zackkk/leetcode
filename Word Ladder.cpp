class Solution {
public:
    // bfs, two queues
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == "")
            return 0;
        
        queue<string> wordQueue;
        queue<int> distQueue;
        
        wordQueue.push(start);
        distQueue.push(1);
        while(!wordQueue.empty()){
            string curWord = wordQueue.front();
            wordQueue.pop();
            int curDist = distQueue.front();
            distQueue.pop();
            
            if(curWord == end)
                return curDist; 
                
            // put all words in dict that have distance one, of the current word
            // O(26 * len(word))
            for(int i = 0; i < curWord.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != curWord[i]){
                        
                        // replace one charcter each time
                        string tmpStr = curWord;
                        tmpStr[i] = c; 
                        
                        // add it into the queue 
                        if(dict.find(tmpStr) != dict.end()){
                            wordQueue.push(tmpStr);
                            distQueue.push(curDist+1);
                            dict.erase(tmpStr); // avoid loop
                        }
                    }
                }
            }
        }
        return 0;
    }
};