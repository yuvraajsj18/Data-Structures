# Stack Implemented with Arrays

### What is a stack?

A stack is a data structure that stores a collection of elements and has at least two operations associated with it:

1. push		2. pop

Push and pop operation on a stack is done according to LIFO that is *Last in, First Out* order.

- Push means to insert a new item at the end.

- Pop means to remove an item from the end.

### Implementation

We will implement our stack with a dynamically allocated array, you can also implement a stack with a linked list or dynamic arrays.

#### Stack class

The stack is a template class that has two *data members*:

1. **stack**: this is a dynamically allocated array.
2. **top**: this is the index of topmost element in our array.

Additionally, our class will have two *template parameters*:

1. **type**: type of the elements to be stored in the array.
2. **size**: maximum size of the stack

 The stack will have the following *member functions*:

1. **is_empty**: Return true if the stack is empty, false otherwise.
2. **push**: insert 'element' at the top of the stack, if not overflow
3. **pop**: remove the element at the top of the stack if not underflow
4. **display**: print all elements in the stack to the console
5. **get_top_element**: returns the top element
6. **clear**: remove all elements in the stack and reset the top.

```cpp
template <typename type, int size>
class Stack
{
    private:
        type* stack; 
        int top;   

    public:
        Stack();
        ~Stack();

        bool is_empty();    
        void push(type element);
        type pop();   
        void display();   
        type get_top_element(); 
        void clear();  
};
```

#### Stack Member Functions Implementation

Now let's define each function one by one.

1. **Stack()**: This is our constructor.

   - It creates a stack with an array of size 'size'.
   - It sets top to -1 to indicate that the stack is empty right now.

   ```cpp
   template <typename type, int size>
   Stack<type, size> :: Stack()
   {
       stack = new type[size];
       top = -1;
   }
   ```

2. **~Stack()**: This is our destructor.

   -  It will free the memory occupied by the dynamically allocated array of Stack.

     **Why?** It's important to do this in destructor because when an object goes out of scope, the *dynamically allocated array* won't be released automatically.

     Just remember that whatever you allocate *dynamically* in constructor must be freed in the destructor.

   ```cpp
   template <typename type, int size>
   Stack<type, size> :: ~Stack()
   {
       delete[] stack;
   }
   ```

3. **is_empty()**:  Return true if stack is empty, false otherwise.

   - How to check if the stack is empty?

     If you think of this:

     ```cpp
     if (top == -1)
         return true
     else
         return false
     ```

     then it is correct but just **unnecessary**, because you can do it like this:

     ```cpp
     template<typename type, int size>
     bool Stack<type, size> :: is_empty()
     {
         return top == -1;   
     }
     ```

     because the Boolean operator == will itself return either *true* or *false*.

4. **push()**: insert 'element' at the top of the stack, if not overflow.

   - First, we need to check for **overflow** that is if we have more space in the stack or not for our new element, then if we do we save it otherwise we have two options -

     1. We can handle overflow with an `if` statement.

     2. We can handle overflow with **exception handling**. We will use this method because [It's **easier** to **ask** forgiveness **than** it is to get **permission**](https://www.google.com/search?q=grace+hopper).
     3. **Note**: **out_of_range(msg)** is a standard exception defined in   **\<stdexcept>** header file. 

   ```cpp
   template<typename type, int size>
   void Stack<type, size> :: push(type element)
   {
       if (top == size - 1)
       {
           throw out_of_range("Stack Overflow!! No more space to add elements.");
       }
   
       // insert element on next position in array
       stack[++top] = element; 
   }
   ```

5. **pop()**: Remove element at the top of stack if not underflow.

   - Just like we did with **push()** we will handle **underflow** that is no more elements to remove with exception handling.
   - **Note**: **out_of_range(msg)** is a standard exception defined in   **\<stdexcept>** header file. 

   ```cpp
   template<typename type, int size>
   type Stack<type, size> :: pop()
   {
       // check for underflow
       if (is_empty())
       {
           throw out_of_range("Stack Underflow!! No more element to pop.");
       }
   
       // pop element
       type element_popped = stack[top--];
       return element_popped;
   }
   ```

6. **display()**: print all elements in stack to console.

   - We will print elements in the LIFO order.

   ```cpp
   template<typename type, int size>
   void Stack<type, size> :: display()
   {
       // check for empty stack
       if (is_empty())
       {
           cout << "Woops! stack is empty." << endl;
           return;
       }
   
       // loop over stack and display all elements
       for (int i = top; i >= 0; i--)
       {
           cout << stack[i] << " ";
       }
       cout << endl;
   }
   ```

7. **get_top_element()**: Returns the top element if stack is not empty.

   - Note: **out_of_range(msg)** is a standard exception defined in   **\<stdexcept>** header file. 

   ```cpp
   template <typename type, int size>
   type Stack<type, size> :: get_top_element()
   {
       if (is_empty())
       {
           throw out_of_range("Stack is empty!!");
       }
       return stack[top];
   }
   ```

8. **clear()**: Remove all elements in the stack and reset the top to -1.

   ```cpp
   template <typename type, int size>
   void Stack<type, size> :: clear()
   {
       // free current memory occupied by the stack
       delete[] stack;
       // reset top
       top = -1;
       // assign new memory
       stack = new type[size];
   }
   ```



### main Function to test our code:

We created a menu-driven main function to perform each operation on our stack.

**Note**

- Remember to create a stack object with template syntax providing both parameters - *type* and *size*.
- Remember to handle the possible exceptions thrown by **push**, **pop**, and **get_top_element** with a *try-catch* block.
- The *what* function used while handling exceptions is a predefined function in all exception classes that will return the message we send while throwing the exceptions.

```cpp
int main()
{
    cout << "Stack implemented as Array";

    const int stack_size = 5;
    Stack<int, stack_size> my_stack;

    int choice;
    while(true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n" << "2. Pop\n" << "3. Display\n"
        << "4. Display top\n" << "5. Stack empty?\n" << "6. Clear stack\n" 
        << "7. Exit" << endl;
        cout << "Enter a choice(1-6): ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                try
                {
                    my_stack.push(element);
                    cout << "Pushed to stack\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 2:
                try
                {
                    int popped_element = my_stack.pop();
                    cout << "Top most element popped: " << popped_element << endl;                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 3:
                cout << "Stack right now:\n";
                my_stack.display();
            break;
            case 4:
                try
                {
                    cout << "Top most element: " << my_stack.get_top_element() << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 5:
                my_stack.is_empty() ? cout << "Stack is empty right now.\n" : cout << "Stack is not empty right now.\n";
            break;
            case 6:
                my_stack.clear();
                cout << "Stack cleared.\n";
            break;
            case 7:
                exit(0);
            break;
            default:
                cout << "Invalid Input!! Please Try Again.\n" << endl; 
            break;
        }
    }

    return 0;
}
```



#### Thanks.





