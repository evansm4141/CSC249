# -*- coding: utf-8 -*-
"""
Created on Thu Feb  9 11:21:43 2023

@author: evansm4141
"""
DEBUG = bool(True) # only print if DEBUG is True (bool is the type)

def selection_sort(numbers):
   # A variable to hold the number of item comparisons
   comparisons = 0

   for i in range(len(numbers)-1):
   #for i in numbers:
          
      # Find index of smallest remaining element
      index_smallest = i
      for j in range(i+1, len(numbers)):
      
         comparisons = comparisons + 1
         if numbers[j] < numbers[index_smallest]:
            index_smallest = j
            print("\tsmallest:", numbers[index_smallest], "@", index_smallest)
      
      # Swap numbers[i] and numbers[index_smallest]
      temp = numbers[i]
      numbers[i] = numbers[index_smallest]
      numbers[index_smallest] = temp
      if DEBUG:
          print("\t\tswap", i, "and", index_smallest)
          print("PART_SORTED", numbers)
          
   return comparisons

def main():
  # Main program to test the selection sort algorithm
  numbers = [10, 2, 78, 4, 45, 32, 7, 11]
  
  # Display the contents of the list
  print('UNSORTED:', numbers)
  
  # Call the selection_sort() function
  comparisons = selection_sort(numbers)
  
  # Display the (sorted) contents of the list
  print('SORTED:', numbers)
  
  print('Total comparisons: %d' % comparisons)

# start program
if __name__ == "__main__":
  main()