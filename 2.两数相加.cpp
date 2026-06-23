// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 虚拟头节点，简化链表操作
        ListNode dummy;
        ListNode* cur = &dummy;
        // 进位
        int carry = 0;

        // l1没走完 / l2没走完 / 还有进位，都要循环
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            // 当前位数值
            int val = sum % 10;
            // 更新进位
            carry = sum / 10;
            // 新建节点接到结果链表
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

