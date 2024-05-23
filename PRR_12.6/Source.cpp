#include <fstream>
#include <string>
#include <iostream>

class Node {
public:
    std::string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const std::string& word) {
        Node* temp = new Node;
        temp->data = word;
        temp->next = nullptr;
        if (front == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void invertQueue() {
        if (front == nullptr) return;
        Node* prev = nullptr;
        Node* current = front;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        front = prev;
    }

    void readWordsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string word;
        while (file >> word) {
            enqueue(word);
        }
    }
};

int main() {
    Queue q;
    q.readWordsFromFile("file.txt");
    q.printQueue();
    q.invertQueue();
    q.printQueue();
    return 0;
}