#include "pqtree.h"
#include "pqnode.h"
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>

using namespace std;

template <typename T> 
PQTree<T>::PQTree(const vector<T>& universe) {
    
    PQNode<T>* _root = new PQNode<T>(pnode);
    _root->parent = nullptr;
    // set up leaf nodes for each element
    for (const auto& element : universe) {
        PQNode<T>* _leaf = new PQNode<T>(leaf);
        _leaf->value = element;
        _leaf->parent = root;
        
        _root->children.push_back(_leaf);

        // the PQTree will track all of the leaves
        leaves.push_back(_leaf);
    }
    root = _root;
}



template <typename T>
bool PQTree<T>::bubble(const vector<PQNode<T>*> &leaves_to_reduce){
    queue<PQNode<T>*> q(leaves_to_reduce.begin(), leaves_to_reduce.end());


    /////////////////////// persistent vars (TODO: move these to class-level?)
    int block_count = 0;
    int blocked_nodes = 0;
    int off_the_top = 0;

    enum Mark {QUEUED, BLOCKED, UNBLOCKED};
    unordered_map<PQNode<T>*, Mark> mark; // If node is not present, its implicit mark is "unmarked"

    unordered_map<PQNode<T>*, int> pertinent_child_count;

    //////////////////////////////////////////////

    while(q.size() + block_count + off_the_top > 1){
        if(q.empty()){
            return false;
        }
        PQNode<T>* x = q.front();
        q.pop();
        mark[x] = BLOCKED;

        // Get blocked/unblocked immediate siblings
        vector<PQNode<T>*> immediate_siblings = {}; // TODO: get immediate siblings
        vector<PQNode<T>*> blocked_siblings = {};
        vector<PQNode<T>*> unblocked_siblings = {};
        for(auto s: immediate_siblings){
            if(mark.count(s)){ //TODO initialize all keys? or turn into diff function?
                if(mark[s] == BLOCKED) blocked_siblings.push_back(s);
                else if(mark[s] == UNBLOCKED) unblocked_siblings.push_back(s);
            }
        }

        if(unblocked_siblings.size() > 0){
            PQNode<T> y = unblocked_siblings[0];
            x->parent = y->parent;
            mark[x] = UNBLOCKED;
        }
        else if(immediate_siblings.size() < 2){
            mark[x] = UNBLOCKED;
        }
        
        if(mark.count(x) && mark[x] == UNBLOCKED){
            PQNode<T>* y = x->parent;
            vector<PQNode<T>*> _LIST = {}; // TODO: _LIST = maximal consecutive set of blocked siblings adjacent to X
            if(blocked_siblings.size()  > 0){
                for(auto z: _LIST){
                    mark[z] = UNBLOCKED;
                    z->parent = y;
                    //TODO: y could be null here
                    if(!pertinent_child_count.count(y)) pertinent_child_count[y] = 0; // TODO: maybe initialize all keys at begining?
                    pertinent_child_count[y] += 1;
                }
            }

            if(y == nullptr){
                off_the_top = 1;
            }
            else{
                if(!pertinent_child_count.count(y)) pertinent_child_count[y] = 0; // TODO: same as above^ (init keys?)
                pertinent_child_count[y] += 1;
                if(!mark.count(y)){ //TODO: init keys?
                    q.push(y);
                    mark[y] = QUEUED;
                }
            }
            block_count -= int(blocked_siblings.size());
            blocked_nodes -= int(_LIST.size());
        }
        else{
            block_count -= int(blocked_siblings.size()) - 1;
        }
    }
    return true;
}

// Include templates for reduce
#include "templates.tpp"

template <typename T>
bool PQTree<T>::reduce(const vector<PQNode<T>*> &leaves_to_reduce){
    // Add all leaves to a queue
    // queue<PQNode*> q;
    // for(PQNode* leaf in leaves){
    //     q.push(leaf);
    // }
    // // Main loop
    // while(!q.empty()){
    //     PQNode* node = q.front();
    //     q.pop();
    //     if(true){
    //         // TODO implement template checking and substitution
    //     }
    //     else{
    //         return false;
    //     }
    //     // If leaves_to_reduced are all children of X, then break
    //     // TODO
    //     // If every sibling of X has been "matched", then place parent of X onto Queue
    //     PQNode* parent = node->parent;
    //     assert(parent != nullptr);
    // }
    return true;
}

// reduction: returns true iff the reduction was successful
template <typename T>
bool PQTree<T>::reduction(const vector<T> &elements){
    // Get the leaves corresponding to elements
    unordered_set<T> elements_set(elements.begin(), elements.end());
    vector<PQNode<T>*> leaves_to_reduce;
    for(PQNode<T>* leaf: leaves){
        if(elements_set.count(leaf->value)){
            leaves_to_reduce.push_back(leaf);
        }
    }

    // Bubble + Reduce
    this->bubble(leaves_to_reduce);
    bool success = this->reduce(leaves_to_reduce);
    return success;
}

template <typename T>
PQTree<T>::~PQTree() {
    delete this->root;
}

//for debug printing
template <typename T>
ostream& operator<<(std::ostream& out, const PQTree<T>& t){
    out << "PQTree: ";
    for (const auto& e: t.leaves){
        out << *e << ", ";
    }
    return out;
}
