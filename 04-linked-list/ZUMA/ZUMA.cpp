#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

class DoublyLinkedListNode
{
public:
    int number;
    int color;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;

    DoublyLinkedListNode(int number, int color, DoublyLinkedListNode* prev = nullptr, DoublyLinkedListNode* next = nullptr)
    {
        this->number = number;
        this->color = color;;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
    unsigned int size;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void pushBack(int number, int color)
    {

        DoublyLinkedListNode* node = new DoublyLinkedListNode(number, color);
        node->prev = tail;
        size++;
        if (!tail)
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
        tail = node;
    }

    void insertAt(DoublyLinkedListNode* node, DoublyLinkedListNode* iter)
    {
        size++;
        node->prev = iter;
        node->next = iter->next;
        iter->next = node;
        if (!node->next)
        {
            tail = node;
            return;
        }

        node->next->prev = node;
    }

    DoublyLinkedListNode* findStart(int color, DoublyLinkedListNode* iter)
    {
        if (!iter)
        {
            return head;
        }
        while (iter->prev && iter->prev->color == color)
        {
            iter = iter->prev;
        }
        return iter;
    }

    DoublyLinkedListNode* findPosition(int pos)
    {
        auto iter = head;
        if (head->number == pos)
        {
            return head;
        }

        while (iter->next && iter->next->number != pos)
        {
            iter = iter->next;
        }
        if (iter->next)
        {
            iter = iter->next;
        }

        return iter;
    }

    void deleteBalls(DoublyLinkedListNode* start, DoublyLinkedListNode* end, int countRemoved)
    {
        if (head == start && tail == end)
        {
            tail = head = nullptr;
        }
        else if (start == head && end != tail)
        {
            head = end;
        }
        else if (start->prev && (!end->next))
        {
            end->prev = start->prev;
            if (end->color == start->color)
            {
                tail = start->prev;
                start->prev->next = nullptr;
            }
            else
            {
                start->prev->next = end;
                tail = end;
            }
        }
        else if (start != head && end != tail)
        {
            start->prev->next = end;
            end->prev = start->prev;
        }

        size -= countRemoved;

    }

    int playGame(pair<int, int>& request, int currentSize)
    {
        if (size == 0)
        {
            return -1;
        }

        DoublyLinkedListNode* iter = findPosition(request.first);
        DoublyLinkedListNode* node = new DoublyLinkedListNode(currentSize, request.second);
        insertAt(node, iter);
        int sum = 0;
        while (iter)
        {
            if (!iter->next)
            {
                return sum;
            }
            else if (iter->next && iter->next->color != iter->color)
            {
                iter = iter->next;
            }
            else if (iter->prev && iter->prev->color == iter->color)
            {
                iter = findStart(iter->color, iter);
            }

            DoublyLinkedListNode* currentNodeIter = iter;
            int countRemoved = 0;
            while (currentNodeIter->next && iter->color == currentNodeIter->color)
            {
                countRemoved++;
                currentNodeIter = currentNodeIter->next;
            }

            if ((!currentNodeIter->next) && currentNodeIter->prev->color == currentNodeIter->color)
            {
                countRemoved++;
            }

            if (countRemoved > 2)
            {
                sum += countRemoved;
                deleteBalls(iter, currentNodeIter, countRemoved);
                currentNodeIter = currentNodeIter->prev;
                if (!head)
                {
                    currentNodeIter = nullptr;
                }
            }
            else
            {
                return sum;
            }
            iter = currentNodeIter;
        }

        return sum;
    }

    friend ostream& operator<<(ostream& out, const DoublyLinkedList& list)
    {
        DoublyLinkedListNode* traverse = list.head;

        while (traverse)
        {
            out << traverse->color << " ";
            traverse = traverse->next;
        }

        return out;
    }

};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N;
    DoublyLinkedList list;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        list.pushBack(i, input);
    }
    cin >> Q;
    vector < pair<int, int>> requests;
    for (int i = 0; i < Q; i++)
    {
        int number, color;
        cin >> number >> color;
        requests.push_back(make_pair(number, color));
    }

    int currentSize = N;
    for (int i = 0; i < Q; i++)
    {
        int countRemoved = list.playGame(requests.at(i), currentSize);
        currentSize++;

        if (countRemoved == -1)
        {
            cout << "Game Over" << endl;
        }
        else
        {
            cout << countRemoved << endl;
        }
    }

    if (list.size != 0)
    {
        cout << list << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}