#include <iostream>
#include <fstream>
#include <cassert>
#include <stdlib.h>

#include "RBTree.h"

MainRBTree::MainRBTree (const MainRBTree &original)
{
    if (original.root)
    {
        root=new RBTree(original.root->data);
        copyRBTree(root, original.root);
    }
    else root=0;
}

void MainRBTree::copyRBTree(RBTree *&newRBTree, RBTree *original)
{
    if(original==0)
        newRBTree = 0;

    if (original)
    {
        newRBTree= new RBTree(original->data);
        newRBTree->parent = original->parent;
        newRBTree->color = original->color;
        //newTree->number = original->number;
        if(original->left)
            copyRBTree(newRBTree->left,original->left);
        else
            newRBTree->left =0;

        if(original->right)
            copyRBTree(newRBTree->right,original->right);
        else
            newRBTree->right =0;
    }
}

MainRBTree &MainRBTree::operator=(const MainRBTree &original)
{
    if(this==&original)
        return *this;
    deleteRBTree(root);
    copyRBTree(root,original.root);
    return *this;
}

void MainRBTree::deleteRBTree(RBTree *&element)
{
    if(element)
    {
        deleteRBTree(element->left);
        deleteRBTree(element->right);
        delete element;
        element=0;
    }
}

int RBTree::getData()const
{
    return data;
}

MainRBTree::MainRBTree()
{
    root = 0;
}

void MainRBTree::out(int k)
{
    outRBTree(root,k);
}

void MainRBTree::unite(MainRBTree intTree1,MainRBTree intTree2)
{
    copyRBTree(root,intTree1.root);
    uniteRBTrees(root,intTree2.root);
}

void MainRBTree::intersection(MainRBTree intTree1,MainRBTree intTree2)
{
    //copyTree(root,intTree1.root);
    deleteRBTree(root);
    intersectionRBTrees(intTree1.root,intTree2.root,root);
}

/*void MainTree::difference(MainTree intTree1,MainTree intTree2)
{
    copyTree(root,intTree1.root);
    differenceTree();
}*/

void MainRBTree::leftRotateRBTree(RBTree *&root,RBTree *&element)
{
    RBTree *y = element->right;
    element->right = y->left;

    if(y->left->data != 0)
    {
        y->left->parent = element;
    }
    if(y->data != 0)
    {
        y->parent = element->parent;
    }
    if(element != root )
    {
        if(element->data == element->parent->left->data)
        {
            element->parent->left = y;
        }
        else
        {
            element->parent->right = y;
        }

    }
    else
    {
         root = y;
    }

    y->left = element;

    if(element != 0)
    {
        element->parent = y;
    }
}

void MainRBTree::rightRotateRBTree(RBTree *&root,RBTree *&element)
{
    RBTree *y = element->left;
    element->left = y->right;

    if(y->right->data != 0)
    {
        y->right->parent = element;
    }
    if(y->data != 0)
    {
        y->parent = element->parent;
    }
    if(element->data != root->data || element->data )
    {

        if(element == element->parent->right)
        {
            element->parent->right = y;
        }
        else
        {
            element->parent->left = y;
        }

    }
    else
    {
         root = y;
    }

    y->right = element;
    if(element != 0)
    {
        element->parent = y;
    }
}

void MainRBTree::insert(int data)
{
    RBTree *current = root;
    current = new RBTree(0);
    if(root)
    {
        current = root;
    }
    else
    {
        current->data = 0;
    }
    RBTree *parent = 0;

    while (current->data !=0)
    {
        if (data==current->data)
        {
            return;
        }
        parent = current;

        current = (data < current->data) ?
        current->left : current->right;
    }

    RBTree *x;
    x = new RBTree(data);
    x->parent = parent;
    x->left = 0;
    x->right = 0;
    x->color = RED;
    x->data = data;

    if(parent)
    {
        if(data < parent->data)
        {
            parent->left = x;
        }
        else
        {
            parent->right = x;
        }
    }
    else
    {
        root = x;
    }
    insertRBTree(root,x);
}

void MainRBTree::leaf(RBTree *&root)
{
    if (root)
    {
        RBTree *x;
        x = new RBTree(0);
        x->parent = root;
        x->left = 0;
        x->right = 0;
        x->color = BLACK;
        x->data = 0;

        if(!root->right && root->data)
        {
            root->right = x;
        }
        if(!root->left && root->data)
        {
            root->left = x;
        }
        leaf(root->right);
        leaf(root->left);
    }
}

void MainRBTree::insertRBTree(RBTree *&element,RBTree *&element1)
{
    leaf(element);
    while(element1 != element && element1->parent->color == RED)
    {
        if(element1->parent == element1->parent->parent->left)
        {
            RBTree *y = element1->parent->parent->right;
            if(y->color == RED)
            {
                element1->parent->color = BLACK;
                y->color = BLACK;
                element1->parent->parent->color = RED;
                element1 = element1->parent->parent;
            }
            else
            {
                if(element1 == element1->parent->right)
                {
                    element1 = element1->parent;
                    leftRotateRBTree(root,element1);
                }
                element1->parent->color = BLACK;
                element1->parent->parent->color = RED;
                rightRotateRBTree(root,element1->parent->parent);
            }
        }
        else
        {
            RBTree *y = element1->parent->parent->left;
            if(y->color == RED)
            {
                element1->parent->color = BLACK;
                y->color = BLACK;
                element1->parent->parent->color = RED;
                element1 = element1->parent->parent;
            }
            else
            {
                if(element1 == element1->parent->left)
                {
                    element1 = element1->parent;
                    rightRotateRBTree(root,element1);
                }
                element1->parent->color = BLACK;
                element1->parent->parent->color = RED;
                leftRotateRBTree(root,element1->parent->parent);
            }
        }
    }
    element->color = BLACK;
}

void MainRBTree::detourFindSimilar(RBTree *&root3,RBTree *&root2)
{
    if(root3!=0)
    {
        if((root2->data==root3->data)&&(root2->number>=root3->number))
        {
            root3->number=root2->number-1;
        }
        if((root2->data==root3->data)&&(root3->number>=root2->number))
        {
            root3->number=root3->number-1;
        }
        detourFindSimilar(root3->left,root2);
        detourFindSimilar(root3->right,root2);
    }
}

void MainRBTree::outRBTree(RBTree *&root, int k)
{
    if (root != 0)
    {
        outRBTree(root->right, k + 3);
        for(int i = 0; i < k; i++)
        {
            cout<<" ";
        }
        cout<< root->data;
        cout<<"("<<root->number<<")"<<endl;
        outRBTree(root->left, k + 3);
    }
 }

void MainRBTree::uniteRBTrees(RBTree *&root3,RBTree *&root2)
{
    if(root2!=0)
    {
        detourFindSimilar(root3,root2);
        insertRBTree(root3,root2);
        uniteRBTrees(root3,root2->left);
        uniteRBTrees(root3,root2->right);
    }
}
void MainRBTree::intersectionRBTrees(RBTree *&root1,RBTree *&root2,RBTree *&root3)
{
    if(root2!=0)
    {
        if(intersectionRBTrees2(root1,root2))
        {
            insertRBTree(root3,root2);
        }

        intersectionRBTrees(root1,root2->right,root3);
        intersectionRBTrees(root1,root2->left,root3);
    }
}

bool MainRBTree::intersectionRBTrees2(RBTree *&root1,RBTree *&root2)
{
    if(root1==0)
    {
        return false;
    }
    else
    {
        if(root1->data==root2->data)
            return true;
        else
            if(root1->data>root2->data)
                return intersectionRBTrees2(root1->left,root2);
            else
                return intersectionRBTrees2(root1->right,root2);
    }
}

/*void MainTree::differenceTree() //дописать!!!!
{
    if(root==0)
    {
        insertTree(root,root2->data);
    }
    else
    {
        if(root3->data==root2->data)
            insertTree(root,root2->data);
            root3->number =
        else
            if(root1->data>root2->data)
                return intersectionTrees2(root1->left,root2);
            else
                return intersectionTrees2(root1->right,root2);
    }
}*/

/*void deleteRB(RBTree *&element)
{
    while (element != root && element->color == BLACK)
    {
        if (element == element->parent->left)
        {
            RBTree *y = element->parent->right;
            if (y->color == RED) {
                y->color = BLACK;
                element->parent->color = RED;
                leftRotateRBTree(x->parent);
                y = element->parent->right;
            }
            if (y->left->color == BLACK && y->right->color == BLACK) {
                y->color = RED;
                element = element->parent;
            } else {
                if (y->right->color == BLACK) {
                    y->left->color = BLACK;
                    y->color = RED;
                    rotateRight (y);
                    y = element->parent->right;
                }
                y->color = x->parent->color;
                element->parent->color = BLACK;
                y->right->color = BLACK;
                leftRotateRBTree(element->parent);
                element = root;
            }
        } else {
            RBTree *y = element->parent->left;
            if (y->color == RED) {
                y->color = BLACK;
                element->parent->color = RED;
                rightRotateRBTree(element->parent);
                y = element->parent->left;
            }
            if (y->right->color == BLACK && y->left->color == BLACK) {
                y->color = RED;
                element = element->parent;
            } else {
                if (y->left->color == BLACK) {
                    y->right->color = BLACK;
                    y->color = RED;
                    leftRotateRBTree(y);
                    y = element->parent->left;
                }
                y->color = element->parent->color;
                element->parent->color = BLACK;
                y->left->color = BLACK;
                rightRotateRBTree(element->parent);
                element = root;
            }
        }
    }
    element->color = BLACK;
}

void deleteRBT(RBTree *z) {
    RBTree *x, *y;


    if (!z || z == NIL) return;


    if (z->left == NIL || z->right == NIL) {

        y = z;
    } else {

        y = z->right;
        while (y->left != NIL) y = y->left;
    }


    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;


    x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;

    if (y != z) z->data = y->data;


    if (y->color == BLACK)
        deleteRB (x);

    free (y);
}*/

