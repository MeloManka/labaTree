#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED

using namespace std;
enum colorRB {BLACK,RED};

struct RBTree
{
    RBTree *parent;
    RBTree *left;
    RBTree *right;
    int data;
    int number;
    colorRB color;
 bool isNil(){
 return(right == 0 && left==0);}
    RBTree(const int dt)
    {
        color = BLACK;
        number = 1;
        data = dt;
        parent = 0;
        left = 0;
        right = 0;
    }
    int getData()const;
};

class MainRBTree
{    public:

        RBTree *root;


        MainRBTree();  //конструктор
        MainRBTree (const MainRBTree &original);  //конструктор копирования

        void insert(int);  //вставка элемента
        //void deleteRBT(int);

        void out(int); //вывод на экран дерева
        void unite(MainRBTree,MainRBTree); //объединение
        void intersection(MainRBTree,MainRBTree); //пересечение
       // void difference(MainTree,MainTree) //разность

        void copyRBTree(RBTree *&newRBTree, RBTree *original);
        void deleteRBTree(RBTree *&element);
        MainRBTree &operator=(const MainRBTree &original);

    private:
        void leftRotateRBTree(RBTree *&,RBTree *&);
        void rightRotateRBTree(RBTree *&,RBTree *&);
        void insertRBTree(RBTree *&,RBTree *&); //дополнительная функция вставки элемента
        //void deleteRB(RBTree *&);

        void outRBTree(RBTree *&, int);  //дополнительная функция вывода на экран
        void uniteRBTrees(RBTree *&,RBTree *&);  //дополнительная функция объединения
        void intersectionRBTrees(RBTree *&,RBTree *&,RBTree *&); //дополнительная функция пересечения
        bool intersectionRBTrees2(RBTree *&,RBTree *&);
        void detourFindSimilar(RBTree *&,RBTree *&); //функция подсчёта кол-ва элементов при операции объединения
        //void differenceTree(); //дополнительная функция разности
        void leaf(RBTree *&);
};


#endif // RBTREE_H_INCLUDED
