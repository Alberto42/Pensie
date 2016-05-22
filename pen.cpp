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
using namespace std;
const int maxNumberOfVertexes=1000007;
struct Vertex {
    int leftChild,rightChild,value;
};
struct EmptySubTree {
    Vertex* root;
    int parentValue, size;
    //dlugosc sciezki do pierwszego rozgalezienia ?
};
struct AvailableValue {
    int value;
    /**
     * this flag is set to true if we are sure
     * that "value" may have more than one proper values.
     */
    bool isSetUnclearly=false;
};
/**
 *  availableValues are sorted ascending
 *  emptySubTrees are sorted ascending
 *
 */
void parseInputAndPrepare(Vertex* tree,int& numberOfVertexes,EmptySubTree* emptySubTrees,
                          list<AvailableValue>& availableValues,int& numberOfEmptySubTrees){
}
void addVertexValues(EmptySubTree tree, list<AvailableValue>& availableValues,
                     list<AvailableValue>::iterator it) {

}
void setValuesInFirstSubTree(EmptySubTree tree, list<AvailableValue>& availableValues, int unclearlyValues) {
    auto it = availableValues.begin();
    int values=0;
    while(it!=availableValues.end() && it->value< tree.parentValue) {
        it++;values++;
    }
    if (values == tree.size) {
        it--;
        //addVertexValues(tree,availableValues, it);
        it++;
    }
    else if (values > tree.size) {


    } else assert(false);
}
void printTreeWithValues(Vertex* tree,int& numberOfVertexes) {

}
void main2(){
    Vertex tree[maxNumberOfVertexes];
    EmptySubTree emptySubTrees[maxNumberOfVertexes];
    list<AvailableValue> availableValues;
    int numberOfVertexes, numberOfEmptySubTrees;

    parseInputAndPrepare(tree,numberOfVertexes,emptySubTrees,availableValues,numberOfEmptySubTrees);

    for(int i=0;i<numberOfEmptySubTrees;i++) {
        setValuesInFirstSubTree(emptySubTrees[i],availableValues, -1);
    }
    printTreeWithValues(tree,numberOfVertexes);
}
int main() {
}
