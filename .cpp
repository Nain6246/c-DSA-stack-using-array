#include <iostream>
using namespace std;
class stack
{
   const static int N = 10;
   int arr[N];
   int n;
   int top;

public:
   stack()
   {
      fill_n(arr, N, 0);
      top = -1;
      n = 0;
   };
   ~stack()
   {
      fill_n(arr, N, 0);
   };
   bool is_empty()
   {
      return (top == -1);
   }
   bool is_full()
   {
      return (top == (N - 1));
   }

   int peek()
   {
      if (is_empty())
      {
         cout << "Stack of array is empty :" << endl;
         return -1;
      }
      return arr[top];
   }

   void push(int value)
   {
      if (is_full())
      {
         cout << "Stack is full :" << endl;
      }
      else
      {
         arr[++top] = value;
         n++;
      }
   }
   void pop()
   {
      if (is_empty())
      {
         cout << "Stack is empty :" << endl;
      }
      else
      {
         arr[top] = 0;
         top--;
         n--;
      }
   }
   void display()
   {
      if (is_empty())
      {
         cout << "Empty :" << endl;
         return;
      }
      stack temp_stack;
      cout << "Data is :";
      for (int i = this->top; i >= 0; i--)
      {
         cout << this->peek() << " ";
         temp_stack.push(this->peek());
         this->pop();
      }
      for (int i = temp_stack.top; i >= 0; i--)
      {
         this->push(temp_stack.peek());
         temp_stack.pop();
      }
      cout << endl;
   }
   int size()
   {
      return (top + 1);
   }

   void find_replace(int toFind, int newData)
   {
      if (is_empty())
      {
         cout << "Empty :" << endl;
         return;
      }
      int check_no = 0;
      stack temp_stack;
      for (int i = this->top; i >= 0; i--)
      {
         if (toFind == arr[i])
         {
            check_no++;
            arr[i] = newData;
            break;
         }
         temp_stack.push(this->peek());

         this->pop();
      }
      if (check_no == 0)
      {
         cout << "Element not found :" << endl;
      }
      for (int i = temp_stack.top; i >= 0; i--)
      {
         this->push(temp_stack.peek());
         temp_stack.pop();
      }
      cout << endl;
   }
};
int main()
{
   stack obj;
   for (int i = 0; i < 10; i++)
      obj.push(i);
   obj.pop();
   obj.pop();
   obj.display();

   obj.find_replace(5, 9);
   obj.display();
   return 0;
}
