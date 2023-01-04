#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve(struct Node *head)
{
    struct Node *fast = head;
    struct Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("%d ", slow->data);
    difference between class and java files
    build with gradle
    checkstyle is in reports in build main.html
    encapsulation
    
#include
}