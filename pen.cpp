//============================================================================
// Name        : Pensje.cpp
// Author      : Albert Cieslak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <assert.h>
#include <vector>
#include <array>

using namespace std;
const int maxNumberOfVertexes=1000007;
struct Vertex {
    int value;
    vector<int> childs;

};
class EmptySubTree {
private:
public:
    EmptySubTree(int size, int parentValue, Vertex *root) : size(size), parentValue(parentValue), root(root) { }

private:
    Vertex* root;
    int parentValue, size;
public:

    Vertex *getRoot() const {
        return root;
    }

    int getSize() const {
        return size;
    }

    int getParentValue() const {
        return parentValue;
    }



    //dlugosc sciezki do pierwszego rozgalezienia ?
};
class AvailableValue {
private:
public:
    AvailableValue(int value) : value(value) { }

private:
    int value;
public:
    int getValue() const {
        return value;
    }

/**
     * this flag is set to true if we are sure
     * that "value" may have more than one proper values.
     */
    //bool isSetUnclearly=false;
};
/**
 *  availableValues are sorted ascending
 *  emptySubTrees are sorted ascending
 */
struct Tree {
    Vertex *tree;
    int root;
    int size;
};
int dfs(Tree tree, int v, int parent,vector<EmptySubTree>& emptySubTrees) {
    Vertex* t=tree.tree;
    //Vertex* vp = &tree.tree[v];
    int size=1;
    for(auto i=t[v].childs.begin();i!=t[v].childs.end();i++) {
        size+=dfs(tree,*i,v,emptySubTrees);
    }
    if (t[v].value == 0 && t[parent].value > 0 || v == parent && v == 0 ) {
        emptySubTrees.push_back(EmptySubTree(size,t[parent].value,&t[v]));
    }
    return size;
}
void parseInputAndPrepare(Tree &tree,vector<EmptySubTree>& emptySubTrees,
                          list<AvailableValue>& availableValues){
    cin>>tree.size;
    int size=tree.size;
    tree.tree=new Vertex[size];
    bool* setValues = new bool[size+1];

    for(int i=0;i<=size;i++)
        setValues[i]=false;

    for(int i=0;i<tree.size;i++) {
        int parent;
        cin>>parent;
        parent--;
        if (parent == i)
            tree.root=i;
        else
            tree.tree[parent].childs.push_back(i);

        cin>>tree.tree[i].value;
        setValues[tree.tree[i].value]=true;
    }
    for(int i=1;i<=tree.size;i++) {
        if (setValues[i] == false)
            availableValues.push_back(AvailableValue(i));
    }
    dfs(tree,tree.root,tree.root,emptySubTrees);
    free(setValues);
}
//void addVertexValues(EmptySubTree tree, list<AvailableValue>& availableValues,
//                     list<AvailableValue>::iterator it) {
//
//}
void setValuesInFirstSubTree(EmptySubTree tree, list<AvailableValue>& availableValues, int& unclearlyValues) {
    auto it = availableValues.begin();
    int values=0;
    while(it!=availableValues.end() && it->getValue()< tree.getParentValue()) {
        it++;values++;
    }
    if (values + unclearlyValues == tree.getSize()) {
        it--;
        //addVertexValues(tree,availableValues, it);
        it++;
    }
    else if (values + unclearlyValues > tree.getSize()) {
        //unclearlyValues+=values-tree.size;
        unclearlyValues = values + unclearlyValues;
        unclearlyValues -= tree.getSize();

    } else assert(false);
    //delete()
}
void printTreeWithValues(Tree tree) {
    Vertex* t=tree.tree;
    for(int i=0;i<tree.size;i++) {
        cout<<t[i].value<<endl;
    }

}
void main2(){
    Tree tree;
    vector<EmptySubTree> emptySubTrees;
    list<AvailableValue> availableValues;

    parseInputAndPrepare(tree,emptySubTrees,availableValues);

    int a;
//    int unclearlyValues=0;
//    for(auto i=emptySubTrees.begin();i!=emptySubTrees.end();i++){
//        setValuesInFirstSubTree(*i,availableValues, unclearlyValues);
//    }
//    printTreeWithValues(tree);
//    free(tree.tree);
}
int main() {
    freopen("example", "r", stdin);
    main2();
    //int dupa[100000000000000];
}
