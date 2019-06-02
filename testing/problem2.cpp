// C++ program to find largest
// value on each level of binary tree.
#include <iostream>
#include <vector>
#include <stdarg.h>

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node() {
        left = NULL;
        right = NULL;
    }
};

template <typename T>
Node<T>* newNode(T data) {
    Node<T>* temp = new Node<T>();
    temp->data = data;
    return temp;
}

// template <typename T>
// T max(int arguments,  ... )

template <typename T>
T max (T a, T b) {
    return (a > b ? a : b);
}

template<typename T, typename... Args>
T max (T first, Args... args) {
    return (first > max(args...) ? first : max(args...));
}


template <typename T>
void preOrder(Node<T>* node, std::vector<std::pair<T, int> > &seq, int depth = 0) {
    if(node == NULL)
        return;
    seq.push_back(std::make_pair(node->data, depth));
    preOrder(node->left, seq, depth + 1);
    preOrder(node->right, seq, depth + 1);
}

template <typename T>
void findHighValueInEachLevel(Node<T>* node, std::vector<T> &highest, int depth = 0) {
    if(node == NULL)
        return;
    if(depth == highest.size())
        highest.push_back(node->data);
    else{
        highest[depth] = max(highest[depth], node->data);
    }

    findHighValueInEachLevel(node->left, highest, depth + 1);
    findHighValueInEachLevel(node->right, highest, depth + 1);
}

template <typename T>
int maxDepth(Node<T>* node) {
    if(!node)
        return -1;
    else{
        int LDepth = maxDepth(node->left) + 1;
        int RDepth = maxDepth(node->right) + 1;
        int maxDepth = (LDepth > RDepth) ? LDepth : RDepth;
        return maxDepth;
    }
}

template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    std::cout << std::endl;
}
template<typename T, typename U>
void printPairs(std::pair<T, U> t){
    std::cout << "Depth : " << t.second << ", Value : " << t.first << std::endl;
    return;
}

template <typename T>
void printCustomVector(const T& t) {
    for(auto i = 0; i < t.size(); ++ i)
        printPairs(t[i]);
}


// Driver code
int main()
{
    /* Let us construct a Binary Tree
        4
       / \
      9   2
     / \   \
    3   5   7 */
 
    Node<int>* root = NULL;
    
    root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(7);
    root->right->right->right = newNode(0);

    std::vector<std::pair<int, int> > sequence;
    preOrder(root, sequence);

    std::vector<int> highestInLevel;
    findHighValueInEachLevel(root, highestInLevel);

    std::cout << "Nodes & their depth" << std::endl; 
    printCustomVector(sequence);
    std::cout << "Maximum Depth of the tree : " << maxDepth(root) << std::endl;
    printVector(highestInLevel);
    return 0;
}