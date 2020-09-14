#include "polynomial.h"

Polynomial :: Polynomial()
{
    head = NULL;
}

Polynomial :: ~Polynomial()
{
    while (head)
    {
        Polynode *temp = head;
        head = head -> next;
        delete temp;
    }
}

void Polynomial :: get_poly(int num_terms)
{
    for (int i = 0; i < num_terms; i++)
    {
        int power, coefficient;
        cout << "Enter power: ";
        cin >> power;
        cout << "Enter coefficient for x^" << power << ": ";
        cin >> coefficient;
        add_tail(coefficient, power);
        cout << "Added." << endl;
    }
}

void Polynomial :: show_poly()
{
    Polynode *temp = head;
    while (temp)
    {
        cout << temp->coefficient << "x^" << temp->power;
        
        if (temp -> next)
            cout << " + ";
        else
            cout << endl;

        temp = temp -> next;
    }
}

void Polynomial :: add_tail(int c, int p)
{
    Polynode *newPoly = new Polynode(c, p);

    if (!head)
    {
        head = newPoly;
    }
    else
    {
        Polynode *temp = head;
        for (; (temp -> next); temp = temp -> next);

        temp -> next = newPoly;
    }
}

void Polynomial :: add(Polynomial &p1, Polynomial &p2)
{
    Polynode *temp1 = p1.head;
    Polynode *temp2 = p2.head;

    while (temp1 && temp2)
    {
        int power1 = temp1->power;
        int power2 = temp2->power;
        if (power1 == power2)
        {
            int coefficient = temp1->coefficient + temp2->coefficient;
            this -> add_tail(coefficient, power1);
        }
        else if (power1 > power2)
        {
            this -> add_tail(temp1->coefficient, power1);
            temp1 = temp1 -> next;
        }
        else
        {
            this -> add_tail(temp2->coefficient, power2);   
            temp2 = temp2 -> next;
        }
    }

    while (temp1)
    {
        this -> add_tail(temp1->coefficient, temp1->power);
        temp1 = temp1 -> next;
    }

    while (temp2)
    {
        this -> add_tail(temp2->coefficient, temp2->power);
        temp2 = temp2 -> next;
    }
}
