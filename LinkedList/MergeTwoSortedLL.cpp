class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2) return list2;
        else if(list1 && list2 == NULL) return list1;
        else if(list1 == NULL && list2 == NULL) return NULL;
        ListNode* last = NULL;
        ListNode* third = NULL;
        if(list1->val < list2->val) {
            last = list1;
            third = list1;
            list1 = list1->next;
            last->next = NULL;
        }
        else {
            last = list2;
            third = list2;
            list2 = list2->next;
            last->next = NULL;
        }
        while(list1 && list2) {
            if(list1->val < list2->val) {
                last->next = list1;
                last = list1;
                list1 = list1->next;
                last->next = NULL;
            }
            else {
                last->next = list2;
                last = list2;
                list2 = list2->next;
                last->next = NULL;
            }
        }
        if(list1) {
            last->next = list1;
        }
        else if(list2) {
            last->next = list2;
        }
        return third;
    }
};