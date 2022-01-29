#include<iostream>
using namespace std;

class DoublyLinkedListNode
{
public:
    int number;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;

    DoublyLinkedListNode(int number = 0, DoublyLinkedListNode* prev = nullptr, DoublyLinkedListNode* next = nullptr)
    {
        this->number = number;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* mid;
    DoublyLinkedListNode* tail;
    unsigned int size;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->mid = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void add(int);
    void gun();
    void milen();

    friend ostream& operator<<(ostream&, const DoublyLinkedList&);
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    DoublyLinkedList list;

    int number;
    char request[8];

    for (int i = 0; i < N; i++)
    {
        cin >> request;
        if (request[0] == 'a')
        {
            cin >> number;
            list.add(number);
        }
        else if (request[0] == 'm')
        {
            list.milen();
        }
        else
        {
            list.gun();
        }
    }

    cout << list.size << '\n' << list;

    return 0;
}

ostream& operator<<(ostream& out, const DoublyLinkedList& list)
{
    DoublyLinkedListNode* traverse = list.head;

    while (traverse != nullptr)
    {
        out << traverse->number << ' ';
        traverse = traverse->next;
    }

    return out;
}

void DoublyLinkedList::add(int number)
{
    DoublyLinkedListNode* node = new DoublyLinkedListNode(number, tail);
    size++;
    if (tail != nullptr)
    {
        tail->next = node;
        tail = node;

        if ((size % 2) == 0)
        {
            mid = mid->next;
        }
    }
    else
    {
        head = mid = tail = node;
    }
}

void DoublyLinkedList::gun()
{
    if (tail != nullptr)
    {
        DoublyLinkedListNode* temp = tail;
        tail = tail->prev;
        delete[] temp;
        size--;
        if (tail != nullptr)
        {
            tail->next = nullptr;
            if (size % 2 == 1)
            {
                mid = mid->prev;
            }
        }
        else
        {
            head = nullptr;
            mid = nullptr;
        }
    }
}

void DoublyLinkedList::milen()
{
    if (size > 1)
    {
        DoublyLinkedListNode* oldHead(head);
        DoublyLinkedListNode* oldMid(mid);
        DoublyLinkedListNode* oldTail(tail);

        tail->next = head;
        head->prev = tail;

        head = oldMid;
        tail = oldMid->prev;
        if (size % 2 == 0)
        {
            mid = oldHead;
        }
        else
        {
            mid = oldTail;
        }

        tail->next = nullptr;
        head->prev = nullptr;
    }
}
