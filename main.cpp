#include <iostream>
#include <fstream>
#include <cstdlib>

#include "RBTree.h"

using namespace std;

int main()
{
    MainRBTree intTree1,intTree2,intTree3;
    int intValue;

////чтение элементов первого дерева/////

    fstream fileTree1;
    fileTree1.open("intTree1.txt");
    if(!fileTree1)
    {
        cerr<<"Error 404"<<endl;
        return -1;
    }
    int k1;
    fileTree1>>k1;

    while(!fileTree1.eof())
    {
        fileTree1>>intValue;
        intTree1.insert(intValue);
    }
    cout<<endl;
    fileTree1.close();

    cout<<"First tree:"<<endl<<endl;
    intTree1.out(k1);
    cout<<endl<<endl;

////чтение элементов второго дерева/////

    fstream fileTree2;
    fileTree2.open("intTree2.txt");
    if(!fileTree2)
    {
        cerr<<"Error 404"<<endl;
        return -1;
    }
    int k2;
    fileTree2>>k2;

    while(!fileTree2.eof())
    {
        fileTree2>>intValue;
        intTree2.insert(intValue);
    }
    fileTree2.close();
    cout<<"Second tree:"<<endl<<endl;
    intTree2.out(k2);
    cout<<endl<<endl;

////объединение/////
    /*cout<<"Union:"<<endl<<endl;
    intTree3.unite(intTree1,intTree2);
    intTree3.out(k1+k2);

////пересечение/////
    cout<<endl<<endl;
    cout<<"Intersection:"<<endl<<endl;
    intTree3.intersection(intTree1,intTree2);
    intTree3.out(k1+k2);
*/
    return 0;
}

