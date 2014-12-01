class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = x;
        int y = 0;
        while(tmp > 0){
            y = y * 10 + tmp % 10;
            tmp /= 10;
        }
        return y == x;
    }
};