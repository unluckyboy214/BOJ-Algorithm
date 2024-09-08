#include <iostream>

using namespace std;

// 트리를 구성하는 노드 구조체
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리에 노드를 삽입하는 함수
Node* insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key); // 왼쪽 서브트리에 삽입
    }
    else {
        node->right = insert(node->right, key); // 오른쪽 서브트리에 삽입
    }

    return node;
}

// 후위 순회를 수행하는 함수
void postorder(Node* node) {
    if (node == nullptr) return;

    postorder(node->left);   // 왼쪽 서브트리 방문
    postorder(node->right);  // 오른쪽 서브트리 방문
    cout << node->key << '\n'; // 루트 노드 출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x;
    Node* root = nullptr;

    // EOF까지 입력을 받으면서 트리 구성
    while (cin >> x) {
        root = insert(root, x);
    }

    // 후위 순회를 통해 출력
    postorder(root);

    return 0;
}
