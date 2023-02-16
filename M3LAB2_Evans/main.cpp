//CSC 249
//M3LAB2
//Melody Evans
//2-16-23

#include <iostream>
#include <string>
using namespace std;

//declare function, just in case
string ArrayToString(int* array, int arraySize);

void Merge(int* numArray, int leftFirst, int leftLast, int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
                                             // array for merged numArray
   int mergePos = 0;                         // Position to insert merged number
   int leftPos = leftFirst;                  // Initialize left partition position
   int rightPos = leftLast + 1;              // Initialize right partition position

   // Add smallest element from left or right partition to merged numArray
   while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numArray[leftPos] <= numArray[rightPos]) {
         mergedNumbers[mergePos] = numArray[leftPos];
         leftPos++;
      }
      else {
         mergedNumbers[mergePos] = numArray[rightPos];
         rightPos++;
      }
      mergePos++;
   }

   // If left partition is not empty, add remaining elements to merged numArray
   while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numArray[leftPos];
      leftPos++;
      mergePos++;
   }

   // If right partition is not empty, add remaining elements to merged numArray
   while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numArray[rightPos];
      rightPos++;
      mergePos++;
   }

   // Copy merged numArray back to numArray
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numArray[leftFirst + mergePos] = mergedNumbers[mergePos];
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
