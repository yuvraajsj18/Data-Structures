/**
 * Design template classes such that they support the following statements:
    Rupee <float> r1, r2;
    Dollar <float> d1, d2;
    d1 = r2; // converts rupee to dollar
    r1 = d2; //converts dollar to rupee
    Write a complete program which does such conversions according to the world market value.
 */

#include <iostream>
using namespace std;

template <typename type>
class Currency
{
    protected:
        type value;

    public:
        void set_value(type value)
        {
            this -> value = value;
        }

        type get_value() const
        { 
            return this -> value; 
        }
};

template <typename type>
class Dollar;

template <typename type>
class Rupee : public Currency<type>
{
    public:
        template <typename fType>
        Rupee& operator=(const Dollar<fType> &d) 
        {
            this -> value = d.get_value() *  74.84;
            return *this;
        }
};

template <typename type>
class Dollar : public Currency<type>
{
    public:
        template <typename fType>
        Dollar& operator=(const Rupee<fType> &r) 
        {
            this -> value = r.get_value() *  0.013;
            return *this;
        }
};


int main()
{
    Rupee <float> r1, r2;   // first required statement
    r2.set_value(100);

    Dollar <float> d1, d2;  // second required statement
    d2.set_value(1.5);

    d1 = r2;    // third required statement
    r1 = d2;    // fourth required statement

    cout << d1.get_value() << endl;
    cout << r1.get_value() << endl;
    
    return 0;
}