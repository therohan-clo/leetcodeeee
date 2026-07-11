class Solution {
public:
    int getSum(int a, int b) {
         while (b != 0){
            int carry= a  ; //# Find common set bits
            a = a ^ b      ;//# Add without carrying
            b = (carry & b) << 1 ; //# Shift carry to the left
    }
    return a;
    }
};