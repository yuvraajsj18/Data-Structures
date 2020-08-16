# Currency Templates

### Question:

Design template classes such that they support the following statements:

​    Rupee \<float> r1, r2;

​    Dollar \<float> d1, d2;

​    d1 = r2; // converts rupee to dollar

​    r1 = d2; //converts dollar to rupee

​    Write a complete program which does such conversions according to the world market value.



### Explaination:

We are asked to create two classes **Rupee** and **Dollar** such that they can take *any type of value* as a data member and we can *convert* between the two currency using = operator.

There are two main things to do in this question:

1. *Make classes accept any type of value*: we can achieve this using **templates**.
2. *Convert between two classes*: we can achieve this by overloading = operator.

### Implementation:

- **Create a super class *Currency* of Rupee and Dollar**:

  - Why? Because, we have two classes that are similar to each other and share some common behaviour like:
    - Both have a value
    - both will have two functions for setting and getting value.

  ```cpp
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
  ```

- **Now create *Rupee* Class**:

  - Note: We are inheriting a template class, so we will use the template syntax and not the usual inheritance syntax.

  ```cpp
  template <typename type>
  class Rupee : public Currency<type> // template inheritance
  {
      public:
      	// This function returns a Rupee object from a Dollar object after convertion.
          Rupee& operator=(const Dollar<Type> &d) 
          {
              this->value = d.get_value() * 74.84;
              return *this;
          }
  };
  ```

- **Similarly create *Dollar* class**:

  ```cpp
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
  ```

- You are done!! Now test the program with a main function:

  - Don't forgot to use \<type> syntax every time you use Rupee or Dollar class.

  ```cpp
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
  ```



## Thanks

