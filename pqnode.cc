#include <vector>

using namespace std;

enum PQNode_types  {leaf, pnode, qnode};

template <typename T> class PQNode {
public:
    PQNode_types type;
    T value;
    (T PQNode)* parent;
    vector<(T PQNode)*> children;
    bool blocked;
};
