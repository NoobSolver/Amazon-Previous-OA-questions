#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *current = head;
        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (current) {
            Node *node = new Node(current->val);
            node->next = current->next;
            current->next = node;
            current = node->next;
        }
        // Second round: assign random pointers for the copy nodes.
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            else
                current->next->random = nullptr;
            current = current->next->next;
        }
        // Third round: restore the original list, and extract the copy list.
        current = head;
        Node *res = head->next;
        Node *tmp = res;
        while(current){
            current->next = current->next->next;
            current = current->next;
            if(tmp->next)
                tmp->next = tmp->next->next;
            tmp = tmp->next;
        }
        return res;
    }
};

Node* make_list(vector<vector<int>> & v) {
    vector<Node*> tmp;
    for(auto i:v) {
        Node * n = new Node(i[0]);
        tmp.push_back(n);
    }

    for(int i = 0; i < tmp.size(); ++i) {
        if(i+1 < tmp.size()) {
            tmp[i]->next = tmp[i + 1];
        }
        else {
            tmp[i]->next = nullptr;
        }

        if(v[i][1] != -1) {
            tmp[i]->random = tmp[v[i][1]];
        }
    }
    return tmp[0];
}

void print_list(Node* n) {
    while(n != nullptr) {
        std::cout << "----------------------" << std::endl;
        std::cout << "Address: " << (void*)n << std::endl;
        std::cout << "Data: " << n->val << std::endl;
        std::cout << "Random: " << (void*)(n->random) << std::endl;
        n = n->next;
    }
}


int main() {
    vector<vector<int>> head = {{7,-1},{13,0},{11,4},{10,2},{1,0}};
    std::cout << "Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]" << std::endl;
    Node* list = make_list(head);
    print_list(list);
    return 0;
}
