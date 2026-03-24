/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* deleteAtIndex(struct ListNode* head, int index) {
    if(index == 0) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct ListNode* a = head;
    struct ListNode* b = head->next;

    for (int i = 0; i < index - 1; i++) {
        a = a->next;
        b = b->next;
    }

    a->next = b->next;
    free(b);

    return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int index = count - n;  

    head = deleteAtIndex(head, index);

    return head;
}
