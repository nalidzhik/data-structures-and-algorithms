/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position)
{
    if (position == 0)
    {
        SinglyLinkedListNode* temp = llist->next;
        delete llist;
        llist = temp;
    }
    else
    {
        SinglyLinkedListNode* traverse = llist;
        for (int i = 0; i < position - 1; i++)
        {
            traverse = traverse->next;
        }
        SinglyLinkedListNode* temp = traverse->next;
        traverse->next = temp->next;

        delete temp;
    }
    return llist;
}