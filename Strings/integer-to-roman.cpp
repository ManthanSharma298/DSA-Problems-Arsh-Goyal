

// Read the question carefully: O(k), O(1)
class Solution {
public:
    
    string intToRoman(int num) {
        string res = "";
        
        while(num > 0){
            if(num >= 1 && num <= 4){
                if(num/4 >= 1){
                    res += "IV";
                    num %= 4;
                }
                else{
                    for(int i=0; i<num/1; ++i){
                        res += "I";
                    }
                    num %= 1;
                }
            }
            else if(num >= 5 && num <= 9){
                if(num/9 >= 1){
                    res += "IX";
                    num %= 9;
                }
                else{
                    for(int i=0; i<num/5; ++i){
                        res += "V";
                    }
                    num %= 5;
                }
            }
            else if(num >= 10 && num <= 49){
                if(num/40 >= 1){
                    res += "XL";
                    num %= 40;
                }
                else{
                    for(int i=0; i<num/10; ++i){
                        res += "X";
                    }
                    num %= 10;
                }
            }
            else if(num >= 50 && num <= 99){
                if(num/90 >= 1){
                    res += "XC";
                    num %= 90;
                }
                else{
                    for(int i=0; i<num/50; ++i){
                        res += "L";
                    }
                    num %= 50;
                }
            }
            else if(num >= 100 && num <= 499){
                if(num/400 >= 1){
                    res += "CD";
                    num %= 400;
                }
                for(int i=0; i<num/100; ++i){
                    res += "C";
                }
                num %= 100;
            }
            else if(num >= 500 && num <= 999){
                if(num/900 >= 1){
                    res += "CM";
                    num %= 900;
                }
                
                else{
                    for(int i=0; i<num/500; ++i){
                        res += "D";
                    }
                    num %= 500;
                }
            }
            else{
                for(int i=0; i<num/1000; ++i){
                    res += "M";
                }
                num %= 1000;
            }
        }
        return res;
    }
};
