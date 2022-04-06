#include <iostream>
using namespace std;
void findSmallestNumWithSum(int digit, int sum) {
   if (sum == 0) {
      if(digit == 1)
         cout<<"Smallest number is 0";
      else
         cout<<"Smallest number with sum cannot be found";
      return ;
   }
   if (sum > 9*digit) {
      cout<<"Smallest number with sum cannot be found";
      return ;
   }
   int number[digit];
   sum -= 1;
   for (int i = digit-1; i>0; i--) {
      if (sum > 9) {
         number[i] = 9;
         sum -= 9;
      } else {
         number[i] = sum;
         sum = 0;
      }
   }
   number[0] = sum + 1;
   cout<<"Smallest number is ";
   for (int i=0; i<digit; i++)
      cout<<number[i];
}
int main() {
   int sum; 
   cout << "Enter sum: ";
   cin >> sum;
   int digit; 
   cout << "Enter digit: ";
   cin >> digit;
   findSmallestNumWithSum(digit, sum);
   return 0;
}
