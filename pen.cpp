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
    Vertex tree[maxNumberOfVertexes];
    int root;
    int size;
};
int dfs(Tree tree, int v, int parent,EmptySubTree* emptySubTrees, int& numberOfEmptySubTrees) {
    Vertex* t=tree.tree;
    //Vertex* vp = &tree.tree[v];
    int size=0;
    for(auto i=t[v].childs.begin();i!=t[v].childs.end();i++) {
        size+=dfs(tree,*i,v,emptySubTrees,numberOfEmptySubTrees);
    }
    if (t[v].value == 0) {
        //emptySubTrees[numberOfEmptySubTrees++]
    }
}
void parseInputAndPrepare(Tree &tree,EmptySubTree* emptySubTrees,
                          list<AvailableValue>& availableValues,int& numberOfEmptySubTrees){
    cin>>tree.size;
    bool setValues[maxNumberOfVertexes];
    fill(false,tree.size+1,setValues); //nie wiem czy to dziala
    for(int i=0;i<tree.size;i++) {
        int parent;
        cin>>parent;
        parent--;
        tree.tree[parent].childs.push_back(i);

        cin>>tree.tree[i].value;
        setValues[tree.tree[i].value]=true;
    }
    numberOfEmptySubTrees=0;
    for(int i=1;i<=tree.size;i++) {
        if (setValues[i] == false)
            availableValues.push_back(AvailableValue(i));
    }


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

}
void main2(){
    Tree tree;
    EmptySubTree emptySubTrees[maxNumberOfVertexes];
    list<AvailableValue> availableValues;
    int numberOfVertexes, numberOfEmptySubTrees;

    parseInputAndPrepare(tree,emptySubTrees,availableValues,numberOfEmptySubTrees);

    for(int i=0;i<numberOfEmptySubTrees;i++) {
        //setValuesInFirstSubTree(emptySubTrees[i],availableValues, -1);
    }
    printTreeWithValues(tree);
}
int main() {
}
