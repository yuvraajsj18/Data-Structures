/*
 * Create a data structure twoStacks that represents two stacks. 
 * Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements. 
 * Following functions must be supported by twoStacks.
 * push1(int x) –> pushes x to first stack	
 * push2(int x) –> pushes x to second stack
 * pop1() –> pops an element from first stack and return the popped element
 * pop2() –> pops an element from second stack and return the popped element
 * display1() displays elements of first stack
 * display2() diaplays elements of second stack
 * Implementation of twoStack should be space efficient.
 */

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename type, int size>
class TwoStacks
{
    private:
        type* two_stacks;
        int top1;
        int top2;

    public:
        TwoStacks();
        ~TwoStacks();

        void push1(type x);
        void push2(type x);

        type pop1();
        type pop2();

        void display1() const;
        void display2() const;
};

int main()
{
    cout << "Two Stack implemented as Array";

    const int stack_size = 5;
    TwoStacks<int, stack_size> my_stack;

    int choice;
    while(true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Push1\n" << "2. Pop1\n" << "3. Display1\n"
        << "4. Push2\n" << "5. Pop2\n" << "6. Display2\n" 
        << "7. Exit" << endl;
        cout << "Enter a choice(1-6): ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                int element1;
                cout << "Enter element to push to first stack: ";
                cin >> element1;
                try
                {
                    my_stack.push1(element1);
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
                    int popped_element = my_stack.pop1();
                    cout << "Top most element of first stack popped: " << popped_element << endl;                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 3:
                my_stack.display1();
            break;
            case 4:
                int element2;
                cout << "Enter element to push to second stack: ";
                cin >> element2;
                try
                {
                    my_stack.push2(element2);
                    cout << "Pushed to stack\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 5:
                try
                {
                    int popped_element = my_stack.pop2();
                    cout << "Top most element of second stack popped: " << popped_element << endl;                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            break;
            case 6:
                my_stack.display2();
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

    return 0;
}


// Member Function Implementation of TwoStacks

template <typename type, int size>
TwoStacks<type, size> :: TwoStacks()
{
    two_stacks = new type[size];
    top1 = -1;
    top2 = size;
}

template <typename type, int size>
TwoStacks<type, size> :: ~TwoStacks()
{
    delete[] two_stacks;
}

template <typename type, int size>
void TwoStacks<type, size> :: push1(type x)
{
    if (top1 == top2 - 1)
    {
        throw out_of_range("Stack Overflow!! No more space to add elements to first stack");
    }

    two_stacks[++top1] = x;
}

template <typename type, int size>
void TwoStacks<type, size> :: push2(type x)
{
    if (top2 == top1 + 1)
    {
        throw out_of_range("Stack Overflow!! No more space to add elements to second stack");
    }

    two_stacks[--top2] = x;
}

template <typename type, int size>
type TwoStacks<type, size> :: pop1()
{
    if (top1 == -1)
    {
        throw out_of_range("Stack Underflow!! No more element to pop from first stack.");
    }

    type element_popped = two_stacks[top1--];
    return element_popped;
}

template <typename type, int size>
type TwoStacks<type, size> :: pop2()
{
    if (top2 == size)
    {
        throw out_of_range("Stack Underflow!! No more element to pop from second stack.");
    }

    type element_popped = two_stacks[top2++];
    return element_popped;
}

template<typename type, int size>
void TwoStacks<type, size> :: display1() const
{
    if (top1 == -1)
    {
        cout << "Woops! first stack is empty." << endl;
        return;
    }

    for (int i = top1; i >= 0; i--)
    {
        cout << two_stacks[i] << " ";
    }
    cout << endl;
}

template<typename type, int size>
void TwoStacks<type, size> :: display2() const
{
    if (top2 == size)
    {
        cout << "Woops! second stack is empty." << endl;
        return;
    }

    for (int i = top2; i < size; i++)
    {
        cout << two_stacks[i] << " ";
    }
    cout << endl;
}

