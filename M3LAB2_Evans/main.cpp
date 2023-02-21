//CSC 249
//M3LAB2
//Melody Evans
//2-16-23

#include <iostream>
#include <string>
using namespace std;

//renamed numbers > numArray, numbersSize > numArray_Size
//renamed leftPos, rightPos, mergePos > left_Pos, right_Pos, merge_Pos
//renamed leftFirst, leftLast, rightLast > left_First, left_Last, right_Last

//declare function, just in case
string ArrayToString(int* array, int arraySize);

void Merge(int* numArray, int left_First, int left_Last, int right_Last) {
   int mergedSize = right_Last - left_First + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
                                             // array for merged numArray
   int merge_Pos = 0;                         // Position to insert merged number
   int left_Pos = left_First;                  // Initialize left partition position
   int right_Pos = left_Last + 1;              // Initialize right partition position

   // Add smallest element from left or right partition to merged numArray
   while (left_Pos <= left_Last && right_Pos <= right_Last) {
      if (numArray[left_Pos] <= numArray[right_Pos]) {
         mergedNumbers[merge_Pos] = numArray[left_Pos];
         left_Pos++;
      }
      else {
         mergedNumbers[merge_Pos] = numArray[right_Pos];
         right_Pos++;
      }
      merge_Pos++;
   }

   // If left partition is not empty, add remaining elements to merged numArray
   while (left_Pos <= left_Last) {
      mergedNumbers[merge_Pos] = numArray[left_Pos];
      left_Pos++;
      merge_Pos++;
   }

   // If right partition is not empty, add remaining elements to merged numArray
   while (right_Pos <= right_Last) {
      mergedNumbers[merge_Pos] = numArray[right_Pos];
      right_Pos++;
      merge_Pos++;
   }

   // Copy merged numArray back to numArray
   for (merge_Pos = 0; merge_Pos < mergedSize; merge_Pos++) {
      numArray[left_First + merge_Pos] = mergedNumbers[merge_Pos];
   }

   // Free temporary array
   delete[] mergedNumbers;
}

void MergeSort(int* numArray, int startIndex, int endIndex) {
   if (startIndex < endIndex) {
      // Find the midpoint in the partition
      int mid = (startIndex + endIndex) / 2;

      // Recursively sort left and right partitions
      MergeSort(numArray, startIndex, mid);
      MergeSort(numArray, mid + 1, endIndex);

      // Merge left and right partition in sorted order
      Merge(numArray, startIndex, mid, endIndex);
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
   cout << "M3LAB2 - Merge Sort\n\n";

   // Create an array of numArray to sort
   int numArray[] = { 61, 76, 19, 4, 94, 32, 27, 83, 58 };
   int numArray_Size = sizeof(numArray) / sizeof(numArray[0]);

   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(numArray, numArray_Size) << endl;

   // Call the MergeSort function
   MergeSort(numArray, 0, numArray_Size - 1);

   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(numArray, numArray_Size) << endl;
}
