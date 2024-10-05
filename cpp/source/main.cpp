#include <iostream>
#include <algorithm>

class NodeTree {
    public:
        int value;
        NodeTree *left;
        NodeTree *right;

        NodeTree(int value, NodeTree *left, NodeTree *right) : value(value), left(left), right(right) {}

        void Reverse() {
            std::swap(this->left, this->right);

            if(this->left != nullptr) this->left->Reverse();
            if(this->right != nullptr) this->right->Reverse();
        }
};

int main(void) {
    NodeTree tree_7(45, nullptr, nullptr);
    NodeTree tree_6(35, nullptr, nullptr);
    NodeTree tree_5(13, nullptr, nullptr);
    NodeTree tree_4(9, nullptr, nullptr);
    NodeTree tree_3(6, &tree_6, &tree_7);
    NodeTree tree_2(4, &tree_4, &tree_5);
    NodeTree tree_1(1, &tree_2, &tree_3);

    tree_1.Reverse();

    std::cout << "NodeTree 1 = " << tree_1.value << "\nleft = " << tree_1.left->value << "\nright = " << tree_1.right->value << "\n\n";
    std::cout << "NodeTree 2 = " << tree_2.value << "\nleft = " << tree_2.left->value << "\nright = " << tree_2.right->value << "\n\n";
    std::cout << "NodeTree 3 = " << tree_3.value << "\nleft = " << tree_3.left->value << "\nright = " << tree_3.right->value << "\n\n";
    return 0;
}