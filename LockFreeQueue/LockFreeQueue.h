#include <atomic>

template <typename T>
class LockFreeQueue {
public:
    LockFreeQueue() : head_(new Node), tail_(head_.load()) {}
    ~LockFreeQueue() {
        while (head_ != nullptr) {
            Node* tmp = head_;
            head_ = head_->next;
            delete tmp;
        }
    }

    void push(const T& data) {
        Node* node = new Node(data);
        Node* tail = tail_.load();
        Node* next = nullptr;
        do {
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            next = tail->next;
        } while (!tail_.compare_exchange_weak(tail, node));
        tail->next = node;
    }

    bool pop(T& data) {
        Node* head = head_.load();
        Node* tail = tail_.load();
        Node* next = nullptr;
        do {
            if (head == tail) {
                return false;
            }
            next = head->next;
        } while (!head_.compare_exchange_weak(head, next));
        data = next->data;
        delete head;
        return true;
    }
}