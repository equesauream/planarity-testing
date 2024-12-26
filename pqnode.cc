enum PQNode_types  {leaf, pnode, qnode};

class PQNode {
public:
    PQNode_types type;
    int value;
};