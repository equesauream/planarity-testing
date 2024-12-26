#ifndef PQNODE
#define PQNODE

#include <vector>
using namespace std;

enum PQNode_types  {leaf, pnode, qnode};

template <typename T>
class PQNode
{
  public:
    PQNode_types type;
    T value; // if this is a leaf node
    PQNode<T>* parent = nullptr;
    vector<PQNode<T>*> children = {};

// constructors
    PQNode(PQNode_types type);
    PQNode(const T &_value);

  private:
    inline PQNode* getRoot() const {
        return (this->parent == nullptr ? 
            this->parent : 
            getRoot(this->parent));
    }
    
};

#include "pqnode.tpp"

#endif