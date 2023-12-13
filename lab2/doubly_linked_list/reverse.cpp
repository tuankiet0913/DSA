ListNode* reverse(ListNode* head, int a, int b) {
    ListNode dummy;
    dummy.right = head;
    head->left = &dummy;

    ListNode* node_a = &dummy;
    for (int i = 0; i < a; i++) {
        node_a = node_a->right;
    }

    ListNode* node_b = node_a;
    for (int i = a; i < b; i++) {
        node_b = node_b->right;
    }

    ListNode* node_a_prev = node_a->left;
    ListNode* node_b_next = node_b->right;

    for (ListNode* p = node_a, *q = p->right, *r = q ? q->right : nullptr; p != node_b_next; p = q, q = r, r = r ? r->right : nullptr) {
        p->right = p->left;
        p->left = q;
    }

    node_a_prev->right = node_b;
    node_b->left = node_a_prev;

    if (node_b_next) {
        node_b_next->left = node_a;
        node_a->right = node_b_next;
    } else {
        node_a->right = nullptr;
    }

    return dummy.right;
}
