#ifndef TREE_H
#define TREE_H



#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *lef;
    Node *rig;
    Node (int x): val (x), lef(nullptr), rig(nullptr) {}
} ;

class tree
{
    Node *root;

public:
    tree(): root (nullptr) {}
    void clear (Node *ptr)
    {
        if (ptr!=nullptr)
        {
            clear (ptr->lef);
            clear (ptr->rig);
            delete ptr;
            ptr = nullptr;
        }

    }

       int nelems()
    {
        int s=0;
       return nelems (root, s);
    }

    void push (int x)
    {
        push (x, root);
    }

    void print()
    {
        if(root!=nullptr)
        print (root);
        else
            cout << "/n empty";
    }

    ~tree ()
    {
        clear (root);
    }

    bool sear(int x)
    {
        return (sear (x, root));
    }

void print2D()
{
   print2DUtil(root, 2, 0);
}


private:

    bool sear(const int & s, Node*& tree)
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

  int nelems(Node *&ptr, int &hop)
    {

        if(ptr!=NULL)
        {
            nelems(ptr->lef, hop);
            hop++;
            nelems(ptr->rig, hop);
        }
        return hop;
    }

void print2DUtil(Node *root, int pos, int space)
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
    cout <<  root->val <<"\n" ;
    print2DUtil(root->lef, space ,space);
}

    void push (int x, Node *ptr)
    {
        if (root==nullptr)
        {
            root=new Node(x);
        }
        else
        {
            if (ptr->val < x)
            {
                if (ptr->rig==nullptr)
                {
                   ptr->rig=new Node (x);
                }
                else
                {
                    push (x, ptr->rig);
                }
            }
         else
            {
                  if (ptr->val > x)
                {
                if (ptr->lef==nullptr)
                {
                    ptr->lef=new Node (x);
                }
                else
                {

                    push (x, ptr -> lef);

                }
                }
            }
        }
    }


    void print(Node *ptr)
    {
        if(ptr!=NULL)
        {
        print(ptr->lef);
        cout << ptr->val << " \t";
        print(ptr->rig);
        }
    }



//
};





#endif // TREE_H
