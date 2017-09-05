
### 002 Add Two Numbers
>You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

>You may assume the two numbers do not contain any leading zero, except the number 0 itself.

>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

1. 考察单链表的操作：插入，删除，创建（头插法，尾插法）

2. 虽然题目的输入没有头结点，但是处理的过程中自己创建头结点，最后返回头结点的下一个结点是一种很好的处理方法。

3. 处理完最高位后，可能还有进位，循环结束后不要忘了这一点。

4. while循环中一定要记得更新变量。

### 003 Longest Substring Without Repeating Characters

>Given a string, find the length of the longest substring without repeating characters.

>**Examples:**

>Given "abcabcbb", the answer is "abc", which the length is 3.

>Given "bbbbb", the answer is "b", with the length of 1.

>Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

1. 先写好伪代码，多举几个例子研究方法

2. 只有英文字符，可用hash表判断字符是否存在

3. 有些库函数要熟记

4. 写完后，再检查一遍代码再编译

5. 改进：滑窗法（未完成），以及滑窗法的优化（未完成）

### 004 Median of Two Sorted Arrays

>There are two sorted arrays nums1 and nums2 of size m and n respectively.

>Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

>Example 1:
`nums1 = [1, 3]
nums2 = [2]`

>The median is 2.0
Example 2:
`nums1 = [1, 2]
nums2 = [3, 4]`

>The median is `(2 + 3)/2 = 2.5`

1. 给出的解法较复杂，未对照进行优化

### 005 Longest Palindromic Substring

>Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

>Example:

>Input: `"babad"`

>Output: `"bab"`

>Note: "aba" is also a valid answer.
>Example:

>Input: `"cbbd"`

>Output: `"bb"`

1. 参照solutions才完成，并且时间不理想
2. 动态规划解题依旧不会，请复习算法导论相关章节
3. 待优化