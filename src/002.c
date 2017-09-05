/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include <stdio.h>
 #include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *pl1 = l1;
    struct ListNode *pl2 = l2;
    struct ListNode *pResult = NULL;
    struct ListNode *pCur = NULL;
    struct ListNode *pNew = NULL;
    int carry = 0;
    int sum;

    // create head node
    // It is convenient to create a dummy head node.
    // If you don't create the dummy head list, the code would be messy.
    pResult = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    pResult->next = NULL;

    pCur = pResult;
    while (pl1 != NULL && pl2 != NULL)
    {
        sum = pl1->val + pl2->val + carry;
        if (carry == 1)
            carry = 0;

        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }

        pNew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNew->val = sum;
        pNew->next = NULL;
        pCur->next = pNew;
        pCur = pCur->next;

        pl1 = pl1->next;
        pl2 = pl2->next;
    }

    while (pl1 != NULL) // There is a better way to deal with this!
    {
        sum = pl1->val + carry;
        if (carry == 1)
            carry = 0;

        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }

        pNew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNew->val = sum;
        pNew->next = NULL;
        pCur->next = pNew;
        pCur = pCur->next;

        pl1 = pl1->next;
    }

    while (pl2 != NULL)
    {
        sum = pl2->val + carry;
        if (carry == 1)
            carry = 0;

        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }

        pNew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNew->val = sum;
        pNew->next = NULL;
        pCur->next = pNew;
        pCur = pCur->next;

        pl2 = pl2->next;
    }

    if (carry == 1)  // Don't forget this!
    {
        sum = carry;
        pNew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNew->val = sum;
        pNew->next = NULL;
        pCur->next = pNew;
        pCur = pCur->next;

        carry = 0;
    }

    return pResult->next;
}

void createList(struct ListNode **l, int a[], int n)
{
    int i;
    struct ListNode *pNew = NULL;
    struct ListNode *pTail = NULL;

    // create head node
    (*l) = (struct ListNode *)malloc(sizeof(struct ListNode));
    (*l)->next = NULL;

    pTail = *l;

    //printf("test2\n");
    for (i = 0; i < n; ++i)
    {
        pNew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNew->val = a[i];
        pNew->next = NULL;
        pTail->next = pNew;
        pTail = pNew;
    }
}

void destroyList(struct ListNode **l)
{
    //struct ListNode *pHead = *l;
    struct ListNode *pDelete;
    while ((*l) != NULL)
    {
        pDelete = (*l);
        (*l) = (*l)->next;
        free(pDelete);
    }
}

void printList(struct ListNode *l)
{
    while (l != NULL)
    {
        printf("%d->", l->val);
        l = l->next;
    }
}

int main()
{
    int a[] = {2, 4, 3};
    int b[] = {5, 6, 4};
    struct ListNode *l1;
    struct ListNode *l2;
    struct ListNode *l3;
    createList(&l1, a, 3);
    //printf("test1\n");
    printList(l1->next);
    printf("\n");
    createList(&l2, b, 3);
    printList(l2->next);
    printf("\n");
    l3 = addTwoNumbers(l1->next, l2->next);
    printList(l3);
    printf("\n");

    destroyList(&l1);
    destroyList(&l2);
    destroyList(&l3);

    return 0;
}