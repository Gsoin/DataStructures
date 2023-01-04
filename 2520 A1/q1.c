#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char plateNum[8];
    int mileage;
    int yymmdd;
    struct node *next;
} node;

node *available = NULL;
node *rented = NULL;
node *repair = NULL;
int totalIncome = 0;

void sort(node **head);
void addToList(node **head, char plateNum[8], int mileage, int yymmdd);
node *find(node *head, char plateNum[8]);
void removeNode(node **head, node *remove);
void returnCar(char plateNum[8]);

int main(void)
{
    node *node1 = malloc(sizeof(node));
    node *node2 = malloc(sizeof(node));
    node *node3 = malloc(sizeof(node));
    node *node4 = malloc(sizeof(node));
    node *node5 = malloc(sizeof(node));

    // initialize nodes
    strcpy(node1->plateNum, "AAA0000");
    node1->mileage = 2000;
    node1->yymmdd = 0;
    node1->next = NULL;

    strcpy(node2->plateNum, "BBB1111");
    node2->mileage = 3000;
    node2->yymmdd = 0;
    node2->next = NULL;

    strcpy(node3->plateNum, "CCC2222");
    node3->mileage = 4000;
    node3->yymmdd = 0;
    node3->next = NULL;

    strcpy(node4->plateNum, "DDD3333");
    node4->mileage = 5000;
    node4->yymmdd = 0;
    node4->next = NULL;

    strcpy(node5->plateNum, "EEE4444");
    node5->mileage = 6000;
    node5->yymmdd = 0;
    node5->next = NULL;

    // set head of available list
    available = node1;

    // link nodes in available list
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int choice;

    // display menu
    printf("1. Add a new car to the available-for-rent list\n");
    printf("2. Add a returned car to the available-for-rent list\n");
    printf("3. Add a returned car to the repair list\n");
    printf("4. Transfer a car from the repair list to the available-for-rent list\n");
    printf("5. Rent the first available car\n");
    printf("6. Print all lists\n");
    printf("7. Quit\n\n");
    // get user's menu choice
    printf("Enter menu choice: ");
    scanf("%d", &choice);

    char plateNum[8];
    int mileage;
    int yymmdd;

    // process menu choice
    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            // add new car to available list
            printf("Enter plate number: ");
            scanf("%s", plateNum);
            printf("Enter mileage: ");
            scanf("%d", &mileage);
            addToList(&available, plateNum, mileage, 0);
            break;

        case 2:
            // add returned car to available list
            printf("Enter plate number: ");
            scanf("%s", plateNum);
            printf("Enter mileage: ");
            scanf("%d", &mileage);
            returnCar(plateNum);
            break;

        case 3:
            // add returned car to repair list
            printf("Enter plate number: ");
            scanf("%s", plateNum);
            printf("Enter mileage: ");
            scanf("%d", &mileage);
            addToList(&repair, plateNum, mileage, 0);
            break;

        case 4:
            // transfer car from repair list to available list
            printf("Enter plate number: ");
            scanf("%s", plateNum);
            node *repairNode = find(repair, plateNum);
            removeNode(&repair, repairNode);
            addToList(&available, plateNum, repairNode->mileage, 0);
            break;

        case 5:
            // rent the first available car
            printf("Enter expected return date (yymmdd): ");
            scanf("%d", &yymmdd);
            node *availableNode = find(available, available->plateNum);
            removeNode(&available, availableNode);
            addToList(&rented, availableNode->plateNum, availableNode->mileage, yymmdd);
            break;

        case 6:
            // print all lists
            printf("\nAvailable cars:\n");
            node *current = available;
            while (current != NULL)
            {
                printf("%s\n", current->plateNum);
                current = current->next;
            }
            printf("\nRented cars:\n");
            current = rented;
            while (current != NULL)
            {
                printf("%s\n", current->plateNum);
                current = current->next;
            }
            printf("\nCars in repair:\n");
            current = repair;
            while (current != NULL)
            {
                printf("%s\n", current->plateNum);
                current = current->next;
            }
            printf("\n");
            break;

        default:
            // invalid input
            printf("Error: Please enter a valid menu choice.\n\n");
            break;
        }
    }