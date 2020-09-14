#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    cout << "Add Two Polynomials" << endl;

    int num_terms1;
    cout << "Enter number of terms in first polynomial: ";
    cin >> num_terms1;
    Polynomial p1;
    cout << "Enter first polynomial:" << endl;
    p1.get_poly(num_terms1);
    
    int num_terms2;
    cout << "Enter number of terms in second polynomial: ";
    cin >> num_terms2;
    Polynomial p2;
    cout << "Enter second polynomial:" << endl;
    p2.get_poly(num_terms2);

    Polynomial p3;
    p3.add(p1, p2);

    cout << "Sum of p1 and p2 is" << endl;
    p1.show_poly();
    cout << "+" << endl;
    p2.show_poly();
    cout << "=" << endl;
    p3.show_poly();

    return 0;
}


/*
Add Two Polynomials
Enter number of terms in first polynomial: 2
Enter first polynomial:
Enter power: 3
Enter coefficient for x^3: 3
Added.
Enter power: 2
Enter coefficient for x^2: 2
Added.
Enter number of terms in second polynomial: 2
Enter second polynomial:
Enter power: 1
Enter coefficient for x^1: 1
Added.
Enter power: 0
Enter coefficient for x^0: 1
Added.
Sum of p1 and p2 is
3x^3 + 2x^2
+
1x^1 + 1x^0
=
3x^3 + 2x^2 + 1x^1 + 1x^0
*/

