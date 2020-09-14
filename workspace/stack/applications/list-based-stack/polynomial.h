#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynode
{
    private:
        int coefficient;
        int power;
        Polynode* next;
        friend class Polynomial;
    public:
        Polynode(int coefficient, int power, Polynode* next = NULL)
        {
            this -> coefficient = coefficient;
            this -> power = power;
            this -> next = next;
        }
};

class Polynomial
{
    public:
        Polynode *head;
        Polynomial();
        ~Polynomial();
        void get_poly(int num_terms);
        void show_poly();
        void add(Polynomial &p1, Polynomial &p2);
        void add_tail(int c, int p);
};

#include "polynomial.tpp"
#endif