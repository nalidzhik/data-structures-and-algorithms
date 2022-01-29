/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

 /*
  * For your reference:
  *
  * SinglyLinkedListNode {
  *     int data;
  *     SinglyLinkedListNode* next;
  * };
  *
  */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{

    if (position == 0)
    {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (llist == nullptr)
        {
            llist = newNode;
        }

        else
        {
            SinglyLinkedListNode* temp = llist;
            newNode->next = temp;
            llist = newNode;
        }

        return llist;
    }
    else
    {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        SinglyLinkedListNode* traverse = llist;
        for (int i = 1; i < position; i++)
        {
            traverse = traverse->next;
        }
        // traverse points to (pos-1)th Node
        SinglyLinkedListNode* temp = traverse->next; // pos-th Node  :  traverse - newNode - temp
        traverse->next = newNode;
        newNode->next = temp;
    }

    return llist;
}