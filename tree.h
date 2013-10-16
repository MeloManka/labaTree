#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

using namespace std;

class MainTree
{
    struct Tree
    {
        Tree *left;
        Tree *right;
        int data;
        int number;

        Tree(const int dt)
        {
            number = 1;
            data = dt;
            left = 0;
            right = 0;
        }
        int getData()const;
    } *root;

    public:
        MainTree();  //конструктор
        MainTree (const MainTree &original);  //конструктор копирования

        void insert(int);  //вставка элемента
        void out(int); //вывод на экран дерева
        void unite(MainTree,MainTree); //объединение
        void intersection(MainTree,MainTree); //пересечение
       // void difference(MainTree,MainTree) //разность

        void copyTree(Tree *&newTree, Tree *original);
        void deleteTree(Tree *&element);
        MainTree &operator=(const MainTree &original);

    private:
        void insertTree(Tree *&,int); //дополнительная функция вставки элемента
        void outTree(Tree *&, int);  //дополнительная функция вывода на экран
        void uniteTrees(Tree *&,Tree *&);  //дополнительная функция объединения
        void intersectionTrees(Tree *&,Tree *&,Tree *&); //дополнительная функция пересечения
        bool intersectionTrees2(Tree *&,Tree *&);
        void detourFindSimilar(Tree *&,Tree *&); //функция подсчёта кол-ва элементов при операции объединения
        //void differenceTree(); //дополнительная функция разности
};

#endif // TREE_H_INCLUDED
