#include <iostream>

template <typename T>
class Node {
public:
    T data; //represents data
    Node* next; // is a pointer to the next node

    Node(T data) : data(data), next(nullptr) {} //constructor
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;//first node

public:
    CircularLinkedList() : head(nullptr) {} //constructor 

   
    void add(T data) { // add element to end of list
        Node<T>* newNode = new Node<T>(data);
        if (!head) { //if there is no start node
            head = newNode;
            head->next = head;  //second node is a start node (ring)
        }
        else { 
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; //for ring 
        }
    }

    
    void remove(T data) {// Remove item from list 
        if (!head) { //check empty or not
            return;
        }
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        do {
            if (current->data == data) {
                if (prev) {                              // it is not the node at the beginning of the list, 
                    prev->next = current->next;          // then it sets the next pointer of the previous node to the next pointer 
                                                         // of the current node.        
                }
                else {
                   
                    Node<T>* last = head; 
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }

  
    void display() {
        if (!head) {
            std::cout << "Null." << std::endl;
            return;
        }

        Node<T>* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList<int> intList;
    CircularLinkedList<std::string> strList;

    while (true) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Add a element to list" << std::endl;
        std::cout << "2. Remove a element from list" << std::endl;
        std::cout << "3. Display the list" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Select the type of list to add an element:" << std::endl;
            std::cout << "1. Integer List" << std::endl;
            std::cout << "2. String List" << std::endl;
            int listChoice;
            std::cin >> listChoice;

            if (listChoice == 1) {
                int data;
                std::cout << "Enter the integer value to add: ";
                std::cin >> data;
                intList.add(data);
            }
            else if (listChoice == 2) {
                std::string data;
                std::cout << "Enter the string value to add: ";
                std::cin >> data;
                strList.add(data);
            }
            else {
                std::cout << "Invalid choice!" << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Select the type of list to remove an element:" << std::endl;
            std::cout << "1. Integer List" << std::endl;
            std::cout << "2. String List" << std::endl;
            int listChoice;
            std::cin >> listChoice;

            if (listChoice == 1) {
                int data;
                std::cout << "Enter the integer value to remove: ";
                std::cin >> data;
                intList.remove(data);
                std::cout << "Element removed successfully." << std::endl;
            }
            else if (listChoice == 2) {
                std::string data;
                std::cout << "Enter the string value to remove: ";
                std::cin >> data;
                strList.remove(data);
                std::cout << "Element removed successfully." << std::endl;
            }
            else {
                std::cout << "Invalid choice!" << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Contents of the list:" << std::endl;
            std::cout << "Integer List: ";
            intList.display();
            std::cout << "String List: ";
            strList.display();
            break;
        }
        case 4: {
            std::cout << "Exiting..." << std::endl;
            return 0;
        }
        default: {
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
        }
    }

    return 0;
}
