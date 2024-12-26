#include "pqtree.h"
#include <iostream>

using namespace std;

int main(){
    cout << "hi" << endl;
    vector<int> universe = {0, 1, 2, 3};
    PQTree<int> t = PQTree<int>(universe);
}