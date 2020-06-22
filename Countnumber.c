int count(int n) 
{ 
    // Base cases (Assuming n is not negative) 
    if (n < 3) 
        return n; 
    if (n >= 3 && n < 10) 
       return n-1; 
  
    // Calculate 10^(d-1) (10 raise to the power d-1) where d is 
    // number of digits in n. po will be 100 for n = 578 
    int po = 1; 
    while (n/po > 9) 
        po = po*10; 
  
    // find the most significant digit (msd is 5 for 578) 
    int msd = n/po; 
  
    if (msd != 3) 
      // For 578, total will be 4*count(10^2 - 1) + 4 + count(78) 
      return count(msd)*count(po - 1) + count(msd) + count(n%po); 
    else
      // For 35, total will be equal to count(29) 
      return count(msd*po - 1); 
} 
  
// Driver program to test above function 
int main() 
{ 
    printf ("%d ", count(578)); 
    return 0; 