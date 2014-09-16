class Solution {
public:
    // many corner cases
    // point: record words length in each line, then we can assign spaces easily
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        if(words.size() == 0 || L == 0) { ret.push_back(""); return ret;} // corner case 
        
        for(int i = 0; i < words.size(); ){
            vector<string> curLineWords;
            int curLineWordsLen = 0;     
            // previous length + length needed < L
            while((i < words.size() && curLineWordsLen == 0) ||   // first word
                  (i < words.size() && curLineWordsLen + (curLineWords.size() - 1) + (words[i].size() + 1) <= L)) {  // check if can add
                curLineWords.push_back(words[i]);
                curLineWordsLen += words[i].size();
                i++;
            }
            int space = L - curLineWordsLen;
			/*
			    case1:     last line with one word / multiple words;
			    case2: non-last line with one word / multiple words;
			 */
			
            // last line, not distribute evenly
            if(i == words.size()){ 
				// assign one for previous words
				if(curLineWords.size() > 1){
					for(int j = 0; j < curLineWords.size()-1; j++){ 
						if(space <= 0) break; // bug happened here
						curLineWords[j] += ' ';
						space--;
					}
				}	
				// assign the rest for the last one
				while(space > 0){curLineWords[curLineWords.size()-1] += ' '; space--; }
            }
            // distribute evenly
            else{ 
				if(curLineWords.size() > 1){
					while(space > 0){
						for(int j = 0; j < curLineWords.size()-1; ++j){ 
							if(space <= 0) break; // bug happened here
							curLineWords[j] += ' ';
							space--;
						}
					}
				}
				else{
					while(space > 0){curLineWords[0] += ' '; space--; }
				}
            }
          
            string tmp;
            for(int j = 0; j < curLineWords.size(); j++) tmp += curLineWords[j];
            ret.push_back(tmp);
        }
        return ret;
    }
};