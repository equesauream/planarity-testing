#include <vector>
#include "pqnode.h"

using namespace std;

template <typename T>
PQNode<T>::PQNode(PQNode_types _type){
    type = _type;
}
