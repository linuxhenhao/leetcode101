#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {};
};


class Solution {
  public:
    ListNode *detectCycle(ListNode* head) {
      ListNode *fast, *slow;
      fast = slow = head;
      while(true) {
        if(!fast || !fast->next) return NULL;
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
      }
      fast = head;
      while(fast!=slow) {
        fast = fast->next;
        slow = slow->next;
      }
      return fast;
    }
};


std::vector<ListNode*> construct_list() {
  auto v = std::vector<ListNode*>();
  for(int i=0;i<5;++i) {
    auto node = new ListNode(i);
    v.push_back(node);
  }
  int size = v.size();
  for(int i=0;i<size-1;++i) {
    v[i]->next = v[i+1];
  }
  v[size-1]->next = v[0];
  return v;
}

void free_v(std::vector<ListNode*> v) {
  for(auto node: v) {
    delete node;
  }
}

int main() {
  auto solution = Solution();
  std::vector<ListNode*> v = construct_list();
  ListNode* cycle_start = solution.detectCycle(v[0]);
  std::cout<<cycle_start->val<<v[0]->val<<std::endl;
  free_v(v);
  return 0;
}
