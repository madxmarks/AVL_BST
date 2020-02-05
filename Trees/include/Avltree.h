#ifndef AVLtree1_H
#define AVLtree1_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <windows.h>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <stdexcept>
#include <iostream>

using namespace std;

struct Node1
{
    int val;
    Node1 *lef;
    Node1 *rig;
    int height;
    Node1 (int x): val (x), lef(nullptr), rig(nullptr), height(1) {}
} ;

class tree1
{
    Node1 *root;

public:
    tree1(): root (nullptr) {}
    void clear (Node1 *ptr)
    {
        if (ptr!=nullptr)
        {
            clear (ptr->lef);
            clear (ptr->rig);
            delete ptr;
        }
    }

    void push (int x)
    {
        push (x, root);
    }

    void print()
    {
        print (root);
    }

    int nelems()
    {
        int s=0;
       return nelems (root, s);
    }

    ~tree1 ()
    {

        clear (root);
    }

    void print2D()
    {
        print2DUtil(root, 2, 0);
    }

        bool sear(int x)
    {
        return (sear (x, root));
    }

private:

    bool sear(const int & s, Node1*& tree)
{
    if(tree == NULL)
    {
        return false;
    }
    if(s < tree->val)
    {
        return sear(s, tree->lef);
    }
    if(tree->val < s)
    {
        return sear(s, tree->rig);
    }
    return true; // We found the value.
}


    void print2DUtil(Node1 *root, int pos, int space)
    {
        if (root == NULL)
            return;
        int COUNT =10;
        space += COUNT;
        print2DUtil(root->rig, space,space);
        cout << "\n";
        for (int i = COUNT; i < space; i++)
        {
            if (i > pos)
                cout << "-";
            else
                cout << " ";
        }
        cout << " : "<< root->val <<"\n" ;
        print2DUtil(root->lef, space,space);
    }

    void push (int & x, Node1* & ptr)
    {
        int balance = 0;


        if (root==nullptr)
        {
            root=new Node1(x);

        }
        else
        {
            if (ptr->val < x)
            {
                if (ptr->rig==nullptr)
                {
                    ptr->rig=new Node1 (x);
                }
                else
                {
                    push (x, ptr->rig);
                    balance = getBalance(ptr)-1;
                }
            }
            else
            {
                if (ptr->val > x)
                {
                if (ptr->lef==nullptr)
                {
                    ptr->lef=new Node1 (x);
                }
                else
                {
                        push (x, ptr -> lef);
                        balance = getBalance(ptr)+1;

                }
                }
            }
        }

    ptr->height =  maxy(height(ptr->lef), height(ptr->rig)) +1 ;
  balance = getBalance(ptr);

        if (balance < -1 && x > ptr->rig->val)
        {

            leftRotate(ptr);
              balance = getBalance(ptr);
        }


        if (balance > 1 && x < ptr->lef->val)
        {

             rightRotate(ptr);
               balance = getBalance(ptr);
        }



        // Left Right Case
        if (balance > 1 && x > ptr->lef->val)
        {

             leftRotate(ptr->lef);
            rightRotate(ptr);
              balance = getBalance(ptr);
        }

        // Right Left Case
        if (balance < -1 && x < ptr->rig->val)
        {
           rightRotate(ptr->rig);
          leftRotate(ptr);
            balance = getBalance(ptr);
        }


    }
    void leftRotate(Node1* &  ptr )
    {
        int maxi=0, maxinpt =0;
        Node1 *nptr = ptr->rig;
        //     Node11 *T2 = nptr->lef;
        //      ptr->rig = T2;
        ptr->rig = nptr->lef;
        nptr->lef = ptr;

        ptr->height = maxy(height(ptr->lef), height(ptr->rig))+1;
        nptr->height =  maxy(height(nptr->lef), height(nptr->rig))+1;
        ptr = nptr;
    }


    void rightRotate(Node1* & ptr )
    {
        int maxi=0, maxinpt =0;
        Node1 *nptr = ptr->lef;
//       Node11 *T2 = nptr->rig;
//       ptr->lef = T2;
        ptr->lef = nptr->rig;
        nptr->rig = ptr;

        ptr->height = maxy(height(ptr->lef), height(ptr->rig))+1;
        nptr->height =  maxy(height(nptr->lef), height(nptr->rig))+1;
 ptr = nptr;
    }

    int height(Node1* t)
    {
        return (t == NULL ? 0 : t->height);
    }

    int maxy(int a, int b)
    {
        return (a > b)? a : b;
    }

    int getBalance(Node1* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->lef) - height(t->rig);
    }

    void print(Node1 *&ptr)
    {
        if(ptr!=NULL)
        {
            print(ptr->lef);
            cout << ptr->val << " \t";
            print(ptr->rig);
        }
    }

 int nelems(Node1 *&ptr, int &hop)
    {

        if(ptr!=NULL)
        {
            nelems(ptr->lef, hop);
            hop++;
            nelems(ptr->rig, hop);
        }
        return hop;
    }



};


#endif
