#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Node class for the Huffman tree
class Node {
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Comparator class for priority queue (min-heap)
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Huffman class to build the tree and print codes
class Huffman {
public:
    // Function to print the Huffman codes
    void printCodes(Node* root, string code) {
        if (!root) return;

        if (root->data != '$') {
            cout << root->data << " : " << code << endl;
        }

        printCodes(root->left, code + "0");
        printCodes(root->right, code + "1");
    }

    // Function to build the Huffman Tree
    void build(vector<char>& data, vector<int>& freq) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        for (size_t i = 0; i < data.size(); i++) {
            minHeap.push(new Node(data[i], freq[i]));
        }

        while (minHeap.size() > 1) {
            Node* left = minHeap.top();
            minHeap.pop();
            Node* right = minHeap.top();
            minHeap.pop();

            Node* temp = new Node('$', left->freq + right->freq);
            temp->left = left;
            temp->right = right;
            minHeap.push(temp);
        }

        printCodes(minHeap.top(), "");
    }
};

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> data(n);
    vector<int> freq(n);

    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter the frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    Huffman huff;
    huff.build(data, freq);

    return 0;
}
