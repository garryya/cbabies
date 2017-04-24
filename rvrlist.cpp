#include <iostream>

struct node
{
    int     value;
    node *  next;
    node(int _value, node * _next) : value(_value), next(_next) {}
};

class llist
{
    protected:
        node * head;
    public:
        llist() : head(NULL) {}
        llist(const int * pnArray, int nLength) { this->init(pnArray, nLength); }

        virtual ~llist() { this->destroy(); }

        llist(const llist& l)
        {
            /* TBI */
        }

        const llist& operator = (const llist& l)
        {
            /* TBI copy */
            return *this;
        }

        virtual bool init(const int * pnArray, int nLength)
        {
            this->head = NULL;
            node ** n = &this->head;
            for(int i = 0; i < nLength; i++, n = &(*n)->next)
                *n = new node(pnArray[i], NULL);
            return true;
        }

        void destroy()
        {
            for(node * n = this->head, * nn = NULL; n; n = nn)
            {
                nn = n->next;
                delete n;
            }
            this->head = NULL;
        }

        void print(const char * prompt = NULL)
        {
            if( prompt )
                std::cout << prompt;
            for(const node * n = this->head; n; n = n->next)
                std::cout << n->value << " --> ";
             std::cout << std::endl;
        }

        void reverse()
        {
            for(node * n = this->head, * nprev = NULL, * nnext = NULL; n; nprev = n, n = nnext)
            {
                nnext = n->next;
                if( n == this->head )
                    n->next = NULL;
                else
                    n->next = nprev;
                    this->head = n;
            }
        }
};


int main(int argc, const char ** argv)
{
    int array[] = {1, 2, 3, 4, 5};
    llist list(array, sizeof(array)/sizeof(int));
    list.print("Before: ");
    list.reverse();
    list.print("After : ");
    return 0;
}
