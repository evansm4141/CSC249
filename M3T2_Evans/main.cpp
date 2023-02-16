//CSC 249
//M3T2
//Melody Evans
//2-16-23

/* As with M3T1, but take the implementation from 3.5 (Insertion Sort)
Then, add debug print (or cout) statements that illustrate what is happening for each pass through the algorithm. */
//https://sortvisualizer.com/selectionsort

#include <iostream>
#include <string>
using namespace std;

void InsertionSort(int* numbers, int numbersSize) {
   for (int i = 1; i < numbersSize; i++) {
      int j = i;
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         // Swap numbers[j] and numbers [j - 1]
         int temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         j--;
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
   // Create an array of numbers to sort
   int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;

   // Call the InsertionSort function
   InsertionSort(numbers, numbersSize);

   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}
