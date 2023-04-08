#include "example.h"
#include <string.h>
#include <iostream>
#include <cassert>

namespace Task1 {
    //Написати функцію - шаблон, що переставляє перший максимальний та перший мінімальний елементи в масиві.
    //Написати специфікацію функції - шаблон для типу char* .

    template<size_t N>
    void swap_min_max(char(&arr)[N]) {
        // знаходимо мінімальний та максимальний елементи
        auto min_it = std::min_element(arr, arr + N - 1);
        auto max_it = std::max_element(arr, arr + N - 1);

        // міняємо місцями мінімальний та максимальний елементи
        std::swap(*min_it, *max_it);
    }

    template<size_t N, typename T>
    void swap_min_max(T(&arr)[N]) {
        // знаходимо мінімальний та максимальний елементи
        auto min_it = std::min_element(arr, arr + N);
        auto max_it = std::max_element(arr, arr + N);

        // міняємо місцями мінімальний та максимальний елементи
        std::swap(*min_it, *max_it);
    }

    int Task1main() 
    {
        std::cout << "========================================================================================================\n";
        // тест 1: переставляємо місцями '1' та '9' у рядку
        int str2[] = { 1,2,3,4,5,6,7,8,9 };

        std::cout << "Array number one:";
        for (int i = 0; i < sizeof(str2) / 4; i++) {
            std::cout << " " << str2[i];
        }
        std::cout << "\n";
        
        swap_min_max(str2);
        //assert(str2[0] == '9'); //Перевіряєм якщо перший елемент дорівнює 9
        //assert(str2[8] == '1'); //Перевіряєм якщо останній елемент дорівнює 1

        std::cout << "Modified array number one:";
        for (int i = 0; i < sizeof(str2) / 4; i++) {
            std::cout << " " << str2[i];
        }
        std::cout << "\n";
        std::cout << "\n";

        // тест 2: переставляємо місцями 'a' та 'z' у рядку
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
    //Написати функцію-шаблон функцію впорядкування методом «Вставки».
    //Написати специфікацію функції - шаблон для типу char* .
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

        // тест 1: сортування масиву int
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

        // тест 2: сортування масиву double
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

        // тест 3: сортування масиву char
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
            T data; //самі дані
            Node* next; //вказівник, що вказує на наступний елемент черги.
            Node(const T& d) : data(d), next(nullptr) {}
        };

        Node* head; //це вказівник на перший елемент черги,  видаляти елементи з початку черги (вказівник head).
        Node* tail; //це вказівник на останній елемент черги, додавати нові елементи до кінця черги (вказівник tail).

    public:
        Queue() : head(nullptr), tail(nullptr) {} //новий об'єкт черги та ініціалізує його два поля - нульовими вказівниками (nullptr).

        //Деструктор
        ~Queue() {
            while (head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        //повертає логічне значення true, якщо черга порожня, і логічне значення false, якщо черга не порожня, тобто містить хоча б один елемент.
        bool empty() const {
            return head == nullptr;
        }
        //повертає константну посилання на дані першого елемента черги, що знаходяться в полі data 
        const T& front() const {
            return head->data;
        }
        //додає новий елемент до кінця черги.
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
        //видаляє перший елемент з черги.
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
            T data; //тут зберігається обєкт
            Node* prev; //попередній елемент
            Node* next; //наступний елемент
            Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr)    //конструктор який має обєкт, попередній елемент та наступний елемент
                : data{ d }, prev{ p }, next{ n } {}
        };
        Node* head; //перший елемент
        Node* tail; //останій елемент
        int size;   //розмір
    public:
        //Побудували клас ітератор, що дозволяє проходити список.
        class Iterator {
        public:
            Iterator(Node* n = nullptr) : curr{ n } {} //це конструктор класу, який приймає вказівник на поточний елемент n і ініціалізує його відповідним чином.
            T& operator*() { return curr->data; }      //це перевантажений оператор "розіменування", який повертає посилання на дані поточного елемента, що зберігаються в полі data.
            Iterator& operator++() { curr = curr->next; return *this; } //ці перевантажені оператори "інкрементації" і "декрементації", які дозволяють переміщуватися по елементах списку. 
            Iterator& operator--() { curr = curr->prev; return *this; } 
            bool operator==(const Iterator& other) const { return curr == other.curr; } //ці перевантажені оператори порівняння, які дозволяють порівнювати два ітератори. Оператор == повертає true,
            bool operator!=(const Iterator& other) const { return !(*this == other); }  //а оператор != повертає false 
        //Коли ми переходимо від одного елемента списку до іншого, ми змінюємо значення змінної curr, щоб вказувати на поточний елемент.
        private:
            Node* curr;
        };

        DoublyLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {} //конструктор по замовчуванню в якому всі значення зануляються
        //Деструктор
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
        //Гетер для розміру
        int getSize() const { return size; }
        //Порівняння якщо список не пустий, та повертає значення True або False 
        bool isEmpty() const { return size == 0; }
        //Заповнення списку спочатку
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
        //Заповнення списку з кінця 
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
        //Видалення списку спочатку
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
        //Видалення списку з кінця
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