#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
template <typename Object>
class DoublyLinkedList{
    private:
        struct Node{
            Object data;
            Node* prev;
            Node* next;
            Node(const Object* d = Object(),Node* p = NULL, Node* n = NULL)
                :data(d),prev(p),next(n){}
        };
    public:
        class const_iterator{
            public:
                const_iterator():current(NULL){}
                const Object& operator*() const{
                    return current->data;
                }

                const_iterator & operator++(){
                    current = current->next;
                    return *this;
                }

                const_iterator operator++(int){
                     const_iterator old = *this;
                     ++(*this);
                     return old;
                }

                const_iterator&  operator--(){
                    current=current->prev;
                    return *this;
                }

                const_iterator operator--(int){
                     const_iterator old = *this;
                     --(*this);
                     return old;
                }

                bool operator==(const const_iterator & rhs) const{
                     return current == rhs.current;
                }
                bool operator!= (const const_iterator& rhs) const{
                    return current != rhs.current;
                }
            private:
                Node* current;
                const_iterator(Node* p):current(p){}
                friend class DoublyLinkedList<Object>;
        };

        class iterator : public const_iterator{

        };
    public:
        DoublyLinkedList(){
             init();
        }
        DoublyLinkedList(const DoublyLinkedList& rhs){

        }
        ~DoublyLinkedList(){

        }
        const Object& operator=(const DoublyLinkedList& rhs){

        }

        iterator begin(){

        }
        iterator end(){

        }
        const const_iterator begin(){

        }
        const const_iterator end(){

        }

        int size() const{

        }

        bool empty() const{

        }

        void clear(){

        }

        Object& front(){

        }
        Object& back(){

        }
        const Object& front() const{

        }

        const Object& back() const {

        }

        void push_front(const Object& data){

        }

        void push_back(const Object& data){

        }

        void pop_front(){

        }
        void pop_back(){

        }

        iterator insert(iterator itr, const Object& data){

        }

        iterator erase(iterator itr){

        }
        iterator erase(iterator start, iterator end){

        }

    private:
        int theSize;
        Node* head;
        Node* tail;
        void init(){
             thisSize = 0;
             head = new Node;
             tail = new Node;
             head->next = tail;
             tail->prev = head;
        }
};




#endif
