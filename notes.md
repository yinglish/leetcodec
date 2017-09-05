
### 002. Add Two Numbers
>You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

>You may assume the two numbers do not contain any leading zero, except the number 0 itself.

>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

1. 考察单链表的操作：插入，删除，创建（头插法，尾插法）

2. 虽然题目的输入没有头结点，但是处理的过程中自己创建头结点，最后返回头结点的下一个结点是一种很好的处理方法。

3. 处理完最高位后，可能还有进位，循环结束后不要忘了这一点。

4. while循环中一定要记得更新变量。