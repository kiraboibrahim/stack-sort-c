#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 25

// :) Linear search to check if a number is in the array
bool isNumberInArray(int arr[], int size, int num)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == num)
    {
      return true;
    }
  }
  return false;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap arr[j] and arr[j+1]
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int binarySearch(int arr[], int low, int high, int key)
{
  if (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
    {
      return mid;
    }

    if (arr[mid] < key)
    {
      return binarySearch(arr, mid + 1, high, key); // Search in the right half
    }
    else
    {
      return binarySearch(arr, low, mid - 1, key); // Search in the left half
    }
  }

  return -1;
}

int main()
{
  int numbers[ARRAY_SIZE];
  int num, searchKey, i, result;

  // Input 25 unique numbers from the user
  printf("Enter 25 unique numbers:\n");
  for (i = 0; i < ARRAY_SIZE; i++)
  {
    do
    {
      printf("Enter number %d: ", i + 1);
      scanf("%d", &num);

      if (isNumberInArray(numbers, i, num))
      {
        printf("Number already exists. Enter a unique number.\n");
      }
      else
      {
        numbers[i] = num;
        break; // Exit the do-while loop
      }
    } while (1); // Infinite loop until a unique number is entered
  }

  printf("Enter the number to search for: ");
  scanf("%d", &searchKey);

  bubbleSort(numbers, ARRAY_SIZE);

  result = binarySearch(numbers, 0, ARRAY_SIZE - 1, searchKey);

  // Print the result
  if (result == -1)
  {
    printf("Number %d not found in the array.\n", searchKey);
  }
  else
  {
    printf("Number %d found at index %d in the sorted array.\n", searchKey, result);
  }

  return 0;
}