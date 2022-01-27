#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head = nullptr;
    Node *tail = nullptr;

    void add(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }


    Node *getNodeByIndex(int index) {
        Node *current = head;
        while (index > 0) {
            if (current == nullptr) {
                return nullptr;
            }

            current = current->next;
            index--;
        }

        return current;
    }

    int count() {
        int length = 0;
        Node *currentNode = head;
        while (currentNode != nullptr) {
            currentNode = currentNode->next;
            length++;
        }

        return length;
    }

    void reverse(int from, int to) {
        int length = count();
        if (from >= length) {
            return;
        }
        if (to > length) {
            to = length;
        }

        Node *startNode = getNodeByIndex(from - 1);
        Node *currentNode = startNode;
        int subArrayLength = to - from + 1;
        int *subArray = new int[subArrayLength];

        int index = 0;
        while (index < subArrayLength) {
            subArray[index++] = currentNode->data;
            currentNode = currentNode->next;
        }

        currentNode = startNode;
        for (int i = subArrayLength - 1; i >= 0; i--) {
            currentNode->data = subArray[i];
            currentNode = currentNode->next;
        }

        delete[] subArray;
    }

    void print() {
        Node *temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List() {
        Node *curr = head;

        while (curr) {
            Node *prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        string op;
        cin >> op;

        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}