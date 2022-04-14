#include<iostream>
using namespace std;
int minCoins(int coinList[], int n, int value) {
   int coins[value+1];       
   if(value == 0)
      return 0;              
   coins[0] = 0;
   for (int i=1; i<=value; i++)
      coins[i] = INT_MAX;            
   for (int i=1; i<=value; i++) {      
      for (int j=0; j<n; j++)
         if (coinList[j] <= i) {
            int tempCoins = coins[i-coinList[j]];
         if (tempCoins != INT_MAX && tempCoins + 1 < coins[i])
            coins[i] = tempCoins + 1;
      }
   }
   return coins[value];       
}
int main() {
   int coins[] = {1, 2, 5, 10};
   int n = 4, value;
   cout << "Enter Value: "; cin >> value;
   cout << "Minimum "<<minCoins(coins, n, value)<<" coins required.";
   return 0;
}
