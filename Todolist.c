#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

typedef struct {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int count;
} ToDoList;

void addTask(ToDoList *list, const char *task) {
    if (list->count < MAX_TASKS) {
        strncpy(list->tasks[list->count], task, MAX_LENGTH);
        list->tasks[list->count][MAX_LENGTH - 1] = '\0'; // Ensure null termination
        list->count++;
        printf("Task added: %s\n", task);
    } else {
        printf("Task list is full!\n");
    }
}

void viewTasks(ToDoList *list) {
    if (list->count == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("Tasks:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]);
    }
}

void deleteTask(ToDoList *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid task number.\n");
        return;
    }
    for (int i = index; i < list->count - 1; i++) {
        strcpy(list->tasks[i], list->tasks[i + 1]);
    }
    list->count--;
    printf("Task deleted.\n");
}

int main() {
    ToDoList list = { .count = 0 };
    int choice;
    char task[MAX_LENGTH];

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter task: ");
                fgets(task, MAX_LENGTH, stdin);
                task[strcspn(task, "\n")] = 0; // Remove newline character
                addTask(&list, task);
                break;
            case 2:
                viewTasks(&list);
                break;
            case 3:
                printf("Enter task number to delete: ");
                int taskNumber;
                scanf("%d", &taskNumber);
                deleteTask(&list, taskNumber - 1);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}