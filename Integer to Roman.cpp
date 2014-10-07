class Solution {
public:
    // Lucy Can't Drink Milk
    string intToRoman(int num) {
        map<int, string> myMap;
        myMap[1] = "I";
        myMap[4] = "IV";
        myMap[5] = "V";
        myMap[9] = "IX";
        myMap[10] = "X";
        myMap[40] = "XL";
        myMap[50] = "L";
        myMap[90] = "XC";
        myMap[100] = "C";
        myMap[400] = "CD";
        myMap[500] = "D";
        myMap[900] = "CM"; 
        myMap[1000] = "M";
        
        int myArray[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ret = "";
        int i = 0;
        while(num > 0){
            int times = num / myArray[i];
            num = num % myArray[i];
            for(int j = 0; j < times; j++){
                ret += myMap[myArray[i]];
            }
            i++;
        }
        return ret;
    }
};