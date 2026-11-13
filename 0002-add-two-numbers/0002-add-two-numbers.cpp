class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = 0;
        ListNode* currL1 = l1;
        ListNode* currL2 = l2;

        // check which linked list is longer 
        // to perform sum inplace on the longer list
        while(currL1 && currL2) {
            currL1 = currL1->next;
            currL2 = currL2->next;
        }

        ListNode* chosenList;
        if (currL1) chosenList = l1;
        else chosenList = l2;

        ListNode* startSaver = chosenList;
        // to perfrom the final carry addition 
        // operation correctly if we need an extra node
        ListNode* LastNotNull = chosenList;

        short tmpSum = 0;
        while(l1 && l2) {
            tmpSum = l1->val + l2->val + carry;
            if (tmpSum > 9) {
                carry = 1;
                chosenList->val = tmpSum - 10;
            } else {
                carry = 0;
                chosenList->val = tmpSum;
            }

            LastNotNull = chosenList;
            chosenList = chosenList->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // In case l1 is longer
        while(l1) {
            tmpSum = l1->val + carry;
            if (tmpSum > 9) {
                carry = 1;
                chosenList->val = tmpSum - 10;
            } else {
                carry = 0;
                chosenList->val = tmpSum;
            }

            LastNotNull = chosenList;
            chosenList = chosenList->next;
            l1 = l1->next;
        }

        // In case l2 is longer
        while(l2) {
            tmpSum = l2->val + carry;
            if (tmpSum > 9) {
                carry = 1;
                chosenList->val = tmpSum - 10;
            } else {
                carry = 0;
                chosenList->val = tmpSum;
            }

            LastNotNull = chosenList;
            chosenList = chosenList->next;
            l2 = l2->next;
        }

        // Need to create new node as we have carry
        if (carry) {
            ListNode* addtionalFinalNode = new ListNode(carry);
            LastNotNull->next = addtionalFinalNode;
        }

        return startSaver;
    }
};
