template<typename T> class Node
{
public:
    T data;
    Node* next;
    Node* prev;
    Node* sm;
    Node* gt;
    Node(T);
};

template<typename T> class FrankenstainList
{
public:
    FrankenstainList();
    ~FrankenstainList();
    void push_front(T);
    void push_back(T);
    int delete_front();
    int delete_back();
    bool is_empty();
    void display();
    int length();
    void search(T);
 
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* smaller;
    Node<T>* greater;
    void PutSorted(Node<T>* node);
    int size;
 
};