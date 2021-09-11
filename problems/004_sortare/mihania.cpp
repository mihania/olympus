#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main() {
   
   // reading the input file
   ifstream in("SORTARE.IN");
   int N;
   in >> N;
   vector<int> nums;
   for (int i = 0; i < N; i++) {
      int val;
      in >> val;
      nums.push_back(val);
   } 
   
   in.close();

   // algorithm
   int res = 0;
   int min;
   int min_ind;
   
   for (int i = 0; i < nums.size(); i++) {
       min = nums[i];
       for (int j = i + 1; j < nums.size(); j++) {
           if (nums[j] < min) {
               min = nums[j];
               min_ind = j;
           }
       }        
 
       if (min < nums[i]) {
           int tmp = nums[min_ind];
           nums[min_ind] = nums[i];
           nums[i] = tmp;
           res++;
       }       
   }

   // writing to the output file.
   ofstream out("SORTARE.OUT");
   out << res;
   out.close();

   return 0;
}
