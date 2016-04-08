#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
template <typename Object>
class DoublyLinkedList{
    private:
        struct Node{
            Object data;
            Node* prev;
            Node* next;
            Node(const Object& d = Object(),Node* p = NULL, Node* n = NULL)
                :data(d),prev(p),next(n){}
        };
    public:
        class const_iterator{
            public:
                const_iterator():current(NULL){}
                const Object& operator*() const{
                    return retrieve();
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
            protected:
                Node* current;
                const_iterator(Node* p):current(p){}
                Object& retrieve() const{
                    return current->data;
                }
                friend class DoublyLinkedList<Object>;
        };

        class iterator : public const_iterator{
        public:
            iterator(){}
            iterator& operator++(){
                 this->current = this->current->next;
                 return *this;
            }
            Object& operator*() {
                return this->retrieve();
            }
            iterator operator++(int){
                 iterator old = *this;
                 ++(*this);
                 return old;
            }
            iterator& operator--(){
                this->current = this->current->prev;
                return *this;
            }
            iterator operator--(int){
                 iterator old = *this;
                 --(*this);
                 return old;
            }
            const Object& operator*() const{
                return const_iterator::operator*();
            }
        protected:
            iterator(Node* p):const_iterator(p){}
            friend class DoublyLinkedList<Object>;
        };
    public:
        DoublyLinkedList(){
             init();
        }
        DoublyLinkedList(const DoublyLinkedList& rhs){
            init();
            *this = rhs;
        }
        ~DoublyLinkedList(){
            clear();
            delete head;
            delete tail;
        }
        const Object& operator=(const DoublyLinkedList& rhs){
            if(this == &rhs)
                return *this;
            clear();
            for(iterator itr = rhs.begin(); itr!=rhs.end();itr++){
                 push_back(*itr);
            }
            return *this;
        }

        iterator begin(){
            return iterator(head->next);
        }

        iterator end(){
            return iterator(tail);
        }
        const_iterator begin() const{
            return const_iterator(head->next);
        }
        const_iterator end() const{
            return const_iterator(tail);
        }

        int size() const{
            return theSize;
        }

        bool empty() const{
            return size() == 0;
        }

        void clear(){
            while(!empty()){
                 pop_front();
            }
        }

        Object& front(){
            return *begin();
        }
        Object& back(){
            return *--end();
        }
        const Object& front() const{
            return *begin();
        }

        const Object& back() const {
            return *--end();
        }
        //z在head 和 head->next之间插入
        void push_front(const Object& data){
            insert(begin(),data);
        }

        void push_back(const Object& data){
            insert(end(),data);
        }

        void pop_front(){
            erase(begin());
        }
        void pop_back(){
            erase(--end());
        }

        iterator insert(iterator itr, const Object& data){
            Node* p = itr.current;
            theSize++;
            //pretty easy to understand
            return iterator(p->prev=p->prev->next=new Node(data,p->prev,p));

        }

        iterator erase(iterator itr){
            Node* p = itr.current;
            iterator retVal(p->next);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            theSize--;
            return retVal;
        }
        iterator erase(iterator start, iterator end){
            for(iterator itr = start; itr != end;)
                itr = erase(itr);
            return end;
        }

    private:
        int theSize;
        Node* head;
        Node* tail;
        void init(){
             theSize = 0;
             head = new Node;
             tail = new Node;
             head->next = tail;
             tail->prev = head;
        }
};




#endif
