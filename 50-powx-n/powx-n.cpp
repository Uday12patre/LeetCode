class Solution {
public:
    double myPow(double x, int n) {

     long BinForm = n;
     if(n < 0)
     {
        x = 1/x;
        BinForm = -BinForm; 
     }

     double ans = 1;

     while(BinForm > 0)
     {
        if(BinForm % 2 == 1)
            ans *= x;
        x *= x;
        BinForm /= 2;
     }
     
     return ans;
    }
};