/* Implementation of a dynamic integer array in C++ 

    Methods added to the class DynamicArray are as follows:

    1. void push(int data): This appends an element in the last of the array
    2. void pop(): It deletes the last element.
    3. void insertElement(int data, int index) : It inserts an element at the given index.
    4. void deleteElement(int index) : It deletes element present at given index
    5. void displayArray(): It is used to print the array elements
 */

#include <iostream>

using namespace std;

class DynamicArray
{
  int length;
  int capacity;
  int *arr;

  public:

  DynamicArray()
  {
    arr = new int[1]; //creating a default array of size 1
    capacity = 1;
    length=0;
  }

  void push(int data)
  {
    if(length<capacity)
    {
      //directly assign
      arr[length] = data;
      length++;
    }
    else
    {
      //create a new array and then assign
      int *temp = new int[capacity+1];
      for(int i=0;i<length;i++)
      {
        temp[i]=arr[i];
      }
      delete[] arr;
      arr = temp;

      arr[length] = data;
      length++;
      capacity++;      
    }

  }

  void pop()
  {
    if (length==0)
      return;

    int a = arr[length-1];
    arr[length-1]=0;
    length--;   //note pop does not resize or changes capacity  
  }

  void insertElement(int data, int index)
  {
    if(index>length-1)
    {
      //Attempting to insert in a location that doesnt exist yet
      return;
    }
    if(length<capacity)
    {
      //shift & assign
      for(int i=length-1;i>=index;i--)
      {
        arr[i+1]=arr[i];
      }
      arr[index]=data;
      length++;
    }
    else
    {
      //create new array & assign
      int *temp = new int[capacity+1];
      for(int i=0;i<index;i++)
      {
        temp[i]=arr[i];
      }
      for(int i=index;i<length;i++)
      {
        temp[i+1]=arr[i];
      }
      delete[] arr;
      arr = temp;

      arr[index] = data;
      length++;
      capacity++;
    }    
  }

  void deleteElement(int index)
  {
    //Attempting to insert in a location that doesnt exist yet
    if (index>length-1)
      return;

    for(int i=index;i<length-1;i++)
    {
        arr[i] = arr[i+1];
    }
    length--;   //note delete does not resize or changes capacity
  }

  void displayArray()
  {
    cout <<"Array data:";
    cout<<"[";
    for(int i=0;i<length;i++)
    {
      cout <<arr[i]<<",";
    }
    cout<<"]\n";
  }

  int getsize()
  {
    return length;
  }

  int getcapacity()
  {
    return capacity;
  }

};

int main() {
  std::cout << "Hello World!\n";

  DynamicArray a;
  a.push(5);
  a.push(6);
  a.push(7);
  a.displayArray();
  
  a.pop();
  a.displayArray();
  
  a.insertElement(55, 1 );
  a.displayArray();
  
  a.deleteElement(1);
  a.displayArray();

  return 0;
}
