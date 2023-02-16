//CSC 249
//M3T2
//Melody Evans
//2-16-23

/* Similar to M3T1, but take the implementation from 3.5 (Insertion Sort)
Then, add debug print (or cout) statements that illustrate what is happening for each pass through the algorithm. */
//https://sortvisualizer.com/selectionsort

#include <iostream>
#include <string>
using namespace std;

static int COMPARES = 0;
static int SWAPS = 0;
const bool DEBUG = true;

void InsertionSort(int* numArray, int numArray_Size) {
   for (int i = 1; i < numArray_Size; i++) {
      int j = i;
      COMPARES++; //next line is a compare, whether True or False
      while (j > 0 && numArray[j] < numArray[j - 1]) {
         // Swap numArray[j] and numArray [j - 1]
         SWAPS++;
         int temp = numArray[j];
         numArray[j] = numArray[j - 1];
         numArray[j - 1] = temp;
         j--;
         if (DEBUG) {
            cout << "\t" << "swapped elements " numArray[j] << " and " << numArray[j-1] << endl;
            cout << "\tPART_SORTED: " << ArrayToString(numArray, numArray_Size) << endl;
         }
      }
   }
}

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }

   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);

   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }

   // Add closing ']' and return result
   result += "]";
   return result;
}

int main() {
  cout << "M3T2: Insertion Sort\n\n";
   // Create an array of numArray to sort
   int numArray[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
   int numArray_Size = sizeof(numArray) / sizeof(numArray[0]);

   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(numArray, numArray_Size) << endl;

   // Call the InsertionSort function
   InsertionSort(numArray, numArray_Size);

   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(numArray, numArray_Size) << endl;
}
