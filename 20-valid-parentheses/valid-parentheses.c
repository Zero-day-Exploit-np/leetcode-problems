struct Node {
    char data;
    struct Node* next;
};
int isEmpty(struct Node* ptr) {
    if (ptr == NULL) {
        return 1;
    }
    return 0;
}
int isFull() {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        return 1;
    }
    free(ptr);
    return 0;
}

struct Node* push(struct Node* ptr, char info) {
    if (isFull()) {
        return 0;
    }
    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    a->data = info;
    a->next = ptr;
    return a;
}
struct Node* pop(struct Node* ptr) {
    if (isEmpty(ptr)) {
        return NULL;
    }
    struct Node* a = ptr;
    ptr = ptr->next;
    free(a);
    return ptr;
}

int ismatching(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

bool isValid(char* s) {
    struct Node* head = NULL;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            head = push(head, s[i]);
        } else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if (isEmpty(head)) {
                return FALSE;
            }
            char a = head->data;
            head = pop(head);
            if (!ismatching(a, s[i])) {
                return FALSE;
            }
        }
    }
    if (head == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}