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

typedef long long ll;

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
    ll calcSum(ListNode* ln) {
        if (ln->next != nullptr) {
            return calcSum(ln->next) * 10LL + ln->val;
        } else {
            return (ll)ln->val;
        }
    }

    ListNode* createRes(ll sum) {
        int val = (int)(sum % 10LL);
        ListNode* res = new ListNode(val);

        ll tmp = sum / 10LL;
        if (tmp != 0) {
            res->next = createRes(tmp);
        }
        return res;
    }

    pair<ListNode*, int> createRes(ListNode* p1, ListNode* p2, int carry_flag) {
        ListNode* res = new ListNode();

        int sum = 0;
        pair<ListNode*, int> ret;
        if (p1 != nullptr && p2 != nullptr) {
            ret = createRes(p1->next, p2->next, 0);
            sum = p1->val + p2->val + ret.second;
        } else if (p1 != nullptr && p2 == nullptr) {
            ret = createRes(p1->next, nullptr, 0);
            sum = p1->val + ret.second;
        } else if (p1 == nullptr && p2 != nullptr) {
            ret = createRes(nullptr, p2->next, 0);
            sum = p2->val + ret.second;
        } else { // p1 == nullptr && p2 == nullptr
            return pair<ListNode*, int> {nullptr, 0};
        }

        res->val = sum % 10;
        res->next = ret.first;
        return pair<ListNode*, int> {res, sum / 10};
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        pair<ListNode*, int> ret = createRes(l1, l2, 0);
        if (ret.second) {
            ListNode* res = new ListNode(ret.second, ret.first);
            return res;
        } else {
            return ret.first;
        }

    }    
};


int main() {

    ListNode l1;
    ListNode l2;

    l1.val = 7;
    l1.next = 

    


    return 0;
}