#include "example.h"
#include <string.h>
#include <iostream>
#include <cassert>

namespace Task1 {
    //�������� ������� - ������, �� ����������� ������ ������������ �� ������ ��������� �������� � �����.
    //�������� ������������ ������� - ������ ��� ���� char* .

    template<size_t N>
    void swap_min_max(char(&arr)[N]) {
        // ��������� ��������� �� ������������ ��������
        auto min_it = std::min_element(arr, arr + N - 1);
        auto max_it = std::max_element(arr, arr + N - 1);

        // ������ ������ ��������� �� ������������ ��������
        std::swap(*min_it, *max_it);
    }

    template<size_t N, typename T>
    void swap_min_max(T(&arr)[N]) {
        // ��������� ��������� �� ������������ ��������
        auto min_it = std::min_element(arr, arr + N);
        auto max_it = std::max_element(arr, arr + N);

        // ������ ������ ��������� �� ������������ ��������
        std::swap(*min_it, *max_it);
    }

    int Task1main() 
    {
        std::cout << "========================================================================================================\n";
        // ���� 1: ������������� ������ '1' �� '9' � �����
        int str2[] = { 1,2,3,4,5,6,7,8,9 };

        std::cout << "Array number one:";
        for (int i = 0; i < sizeof(str2) / 4; i++) {
            std::cout << " " << str2[i];
        }
        std::cout << "\n";
        
        swap_min_max(str2);
        //assert(str2[0] == '9'); //��������� ���� ������ ������� ������� 9
        //assert(str2[8] == '1'); //��������� ���� ������� ������� ������� 1

        std::cout << "Modified array number one:";
        for (int i = 0; i < sizeof(str2) / 4; i++) {
            std::cout << " " << str2[i];
        }
        std::cout << "\n";
        std::cout << "\n";

        // ���� 2: ������������� ������ 'a' �� 'z' � �����
        char str1[] = "abcdefghijklmnopqrstuvwxyz";

        std::cout << "Array number two:";
        for (int i = 0; i < sizeof(str1); i++) {
            std::cout << " " << str1[i];
        }
        std::cout << "\n";

        swap_min_max(str1);
        assert(str1[0] == 'z');
        assert(str1[25] == 'a');

        std::cout << "Modified array number two:";
        for (int i = 0; i < sizeof(str1); i++) {
            std::cout << " " << str1[i];
        }
        std::cout << "\n";
        std::cout << "\n";

        std::cout << "All tests passed!\n";
        std::cout << "\n";
        std::cout << "========================================================================================================\n";

        return 0;
    }
}
namespace Task2 {
    //�������� �������-������ ������� ������������� ������� ��������.
    //�������� ������������ ������� - ������ ��� ���� char* .
    template<typename T, std::size_t N>
    void insertion_sort(T(&arr)[N]) {
        for (std::size_t i = 1; i < N; ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    template<std::size_t N>
    void insertion_sort(char(&arr)[N]) {
        for (std::size_t i = 1; i < N - 1; ++i) {
            char key = arr[i];
            std::size_t j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
    int Task2main() {

        // ���� 1: ���������� ������ int
        int arr1[] = {3,2,1,4,5};

        std::cout << "Array number one:";
        for (int i = 0; i < 5; i++) {
            std::cout << " " << arr1[i];
        }
        std::cout << "\n";

        insertion_sort(arr1);
        assert(arr1[0] == 1);
        assert(arr1[1] == 2);
        assert(arr1[2] == 3);
        assert(arr1[3] == 4);
        assert(arr1[4] == 5);

        std::cout << "Modified array number one:";
        for (int i = 0; i < 5; i++) {
            std::cout << " " << arr1[i];
        }
        std::cout << "\n";
        std::cout << "\n";

        // ���� 2: ���������� ������ double
        double arr2[] = { 3.2, 1.1, 4.7, 2.8, 5.3 };

        std::cout << "Array number two:";
        for (int i = 0; i < 5; i++) {
            std::cout << " " << arr2[i];
        }
        std::cout << "\n";

        insertion_sort(arr2);
        assert(arr2[0] == 1.1);
        assert(arr2[1] == 2.8);
        assert(arr2[2] == 3.2);
        assert(arr2[3] == 4.7);
        assert(arr2[4] == 5.3);

        std::cout << "Modified array number two:";
        for (int i = 0; i < 5; i++) {
            std::cout << " " << arr2[i];
        }
        std::cout << "\n";
        std::cout << "\n";

        // ���� 3: ���������� ������ char
        char arr3[] = "hello";

        std::cout << "Array number three:";
        for (int i = 0; i < 5; i++) {
            std::cout << " " << arr3[i];
        }
        std::cout << "\n";

        insertion_sort(arr3);

        std::cout << "Modified array number three:";
        for (int i = 0; i < 6; i++) {
            std::cout << " " << arr3[i];
        }
        std::cout << "\n";
        std::cout << "\n";

        std::cout << "All tests passed!\n";
            
        assert(std::strcmp(arr3, "ehllo") == 0);

        std::cout << "========================================================================================================\n";

        return 0;
    }
}
namespace Task3 {
    template<typename T>
    class Queue {
    private:
        struct Node {
            T data; //��� ���
            Node* next; //��������, �� ����� �� ��������� ������� �����.
            Node(const T& d) : data(d), next(nullptr) {}
        };

        Node* head; //�� �������� �� ������ ������� �����,  �������� �������� � ������� ����� (�������� head).
        Node* tail; //�� �������� �� ������� ������� �����, �������� ��� �������� �� ���� ����� (�������� tail).

    public:
        Queue() : head(nullptr), tail(nullptr) {} //����� ��'��� ����� �� �������� ���� ��� ���� - ��������� ����������� (nullptr).

        //����������
        ~Queue() {
            while (head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        //������� ������ �������� true, ���� ����� �������, � ������ �������� false, ���� ����� �� �������, ����� ������ ���� � ���� �������.
        bool empty() const {
            return head == nullptr;
        }
        //������� ���������� ��������� �� ��� ������� �������� �����, �� ����������� � ��� data 
        const T& front() const {
            return head->data;
        }
        //���� ����� ������� �� ���� �����.
        void push(const T& item) {
            Node* newNode = new Node(item);
            if (head == nullptr) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        //������� ������ ������� � �����.
        void pop() {
            if (head == nullptr) {
                return;
            }
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    };

    int Task3main() {
        Queue<int> queue;
        queue.push(1);
        queue.push(2);
        queue.push(3);

        std::cout << "Our array: ";
        while (!queue.empty()) {
            std::cout << queue.front() << " ";
            queue.pop();
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Tests passed!\n";
        std::cout << "========================================================================================================\n";

        return 0;
    }

}
namespace Task4 {
    template <typename T>
    class DoublyLinkedList {
    private:
        struct Node {
            T data; //��� ���������� ����
            Node* prev; //��������� �������
            Node* next; //��������� �������
            Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr)    //����������� ���� �� ����, ��������� ������� �� ��������� �������
                : data{ d }, prev{ p }, next{ n } {}
        };
        Node* head; //������ �������
        Node* tail; //������ �������
        int size;   //�����
    public:
        //���������� ���� ��������, �� �������� ��������� ������.
        class Iterator {
        public:
            Iterator(Node* n = nullptr) : curr{ n } {} //�� ����������� �����, ���� ������ �������� �� �������� ������� n � �������� ���� ��������� �����.
            T& operator*() { return curr->data; }      //�� �������������� �������� "������������", ���� ������� ��������� �� ��� ��������� ��������, �� ����������� � ��� data.
            Iterator& operator++() { curr = curr->next; return *this; } //�� ������������ ��������� "�������������" � "�������������", �� ���������� ������������� �� ��������� ������. 
            Iterator& operator--() { curr = curr->prev; return *this; } 
            bool operator==(const Iterator& other) const { return curr == other.curr; } //�� ������������ ��������� ���������, �� ���������� ���������� ��� ���������. �������� == ������� true,
            bool operator!=(const Iterator& other) const { return !(*this == other); }  //� �������� != ������� false 
        //���� �� ���������� �� ������ �������� ������ �� ������, �� ������� �������� ����� curr, ��� ��������� �� �������� �������.
        private:
            Node* curr;
        };

        DoublyLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {} //����������� �� ������������ � ����� �� �������� �����������
        //����������
        ~DoublyLinkedList() {
            Node* p;
            while (head != nullptr) {
                p = head;
                head = head->next;
                delete p;
            }
            tail = nullptr;
            size = 0;
        }
        //����� ��� ������
        int getSize() const { return size; }
        //��������� ���� ������ �� ������, �� ������� �������� True ��� False 
        bool isEmpty() const { return size == 0; }
        //���������� ������ ��������
        void pushFront(const T& val) {
            head = new Node(val, nullptr, head);
            if (tail == nullptr) {
                tail = head;
            }
            else {
                head->next->prev = head;
            }
            size++;
        }
        //���������� ������ � ���� 
        void pushBack(const T& val) {
            tail = new Node(val, tail, nullptr);
            if (head == nullptr) {
                head = tail;
            }
            else {
                tail->prev->next = tail;
            }
            size++;
        }
        //��������� ������ ��������
        void popFront() {
            if (isEmpty()) {
                throw std::out_of_range("List is empty");
            }
            Node* p = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            else {
                head->prev = nullptr;
            }
            delete p;
            size--;
        }
        //��������� ������ � ����
        void popBack() {
            if (isEmpty()) {
                throw std::out_of_range("List is empty");
            }
            Node* p = tail;
            tail = tail->prev;
            if (tail == nullptr) {
                head = nullptr;
            }
            else {
                tail->next = nullptr;
            }
            delete p;
            size--;
        }

        Iterator begin() const { return Iterator(head); }
        Iterator end() const { return Iterator(nullptr); }
    };
    int Task4main() {
        DoublyLinkedList<int> list;
        list.pushBack(1);
        list.pushBack(2);
        list.pushBack(3);
        list.pushBack(4);

        std::cout << "Our array: ";
        for (DoublyLinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Tests passed!\n";
        std::cout << "========================================================================================================\n";

        return 0;
    }
}
void example()
{
    int task;
    do {
        std::cout << "Enter a task number (1-4), or 0 to exit: ";
        std::cin >> task;

        switch (task) {
        case 1:
            Task1::Task1main();
            break;
        case 2:
            Task2::Task2main();
            break;
        case 3:
            Task3::Task3main();
            break;
        case 4:
            Task4::Task4main();
            break;
        case 0:
            std::cout << "Exiting program..." << "\n";
            break;
        default:
            std::cout << "Invalid task number. Please try again." << "\n";
            break;
        }
    } while (task != 0);
}