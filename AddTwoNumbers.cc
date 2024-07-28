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

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* createRes(ListNode* p1, ListNode* p2, int carry_flag) {
        int sum = 0;
        ListNode* ret;
        if (p1 != nullptr && p2 != nullptr) {
            sum = p1->val + p2->val + carry_flag;
            ret = createRes(p1->next, p2->next, sum / 10);
        } else if (p1 != nullptr && p2 == nullptr) {
            sum = p1->val + carry_flag;
            ret = createRes(p1->next, nullptr, sum / 10);
        } else if (p1 == nullptr && p2 != nullptr) {
            sum = p2->val + carry_flag;
            ret = createRes(nullptr, p2->next, sum / 10);
        } else { // p1 == nullptr && p2 == nullptr
            if (carry_flag) {
                ListNode* res = new ListNode(carry_flag, nullptr);
                return res;
            } else {
                return nullptr;
            }
        }

        ListNode* res = new ListNode(sum % 10, ret);
        return res;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return createRes(l1, l2, 0);
    }    
};


int main() {

    ListNode l1;
    ListNode l2;

    return 0;
}