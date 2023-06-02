// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
    struct Node {
        char z;
        std::vector<Node*> nodes;
    };
    std::vector<char> change;
    Node* root = nullptr;
    void make(std::vector<char> val, Node* root) {
        for (auto i : val) {
            if (i == root->z) {
                val.erase(std::remove(val.begin(), val.end(), i),
                    val.end());
                for (auto ch : val) {
                    Node* temp = new Node;
                    temp->z = ch;
                    root->nodes.push_back(temp);
                }
            }
        }
        for (auto i : root->nodes) {
            make(val, i);
        }
    }
    void Changes(Node* root) {
        if (root->nodes.empty()) {
            change.push_back(root->z);
            shifts.push_back(change);
            change.clear();
        }
        for (auto i : root->nodes) {
            change.push_back(root->z);
            Changes(i);
        }
    }
 public:
    std::vector<std::vector<char>> shifts;
    explicit Tree(std::vector<char> val) {
        root = new Node;
        root->z = ' ';
        for (auto i : val) {
            Node* temp = new Node;
            temp->z = i;
            root->nodes.push_back(temp);
        }
        for (auto i : root->nodes) {
            make(val, i);
            Changes(i);
            change.clear();
        }
    }
};
#endif  // INCLUDE_TREE_H_
