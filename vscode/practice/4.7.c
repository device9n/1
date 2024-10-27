#include <stdio.h>
#include <stdlib.h>

#define MAX_PROJECTS 26


typedef struct Node{
    char project;
    struct Node* next;
} Node;

Node* addNote(Node* head, char project) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->project = project;
    newNode->next = head;
    return newNode;
}

void printBuildOrder(char* order, int size){
    for(int i = 0; i < size; i++) {
        printf("%c ", order[i]);
    }
    printf("\n");
}

int findBuildOrder(char projects[], int numProjects, 
                    char dependencies[][2], int numDependencies,
                     char* buildOrder) {
    Node* graph[MAX_PROJECTS] = {0};
    int inDegree[MAX_PROJECTS] = {0};
    int queue[MAX_PROJECTS];
    int front = 0, rear = 0;
    int orderIndex = 0;

    for(int i = 0; i < numDependencies; i++) {
        char pre = dependencies[i][0] - 'a';
        char post = dependencies[i][1] - 'a';
        graph[pre] = addNote(graph[pre], dependencies[i][1]);
        inDegree[post]++;
    }

    for(int i = 0; i < numProjects; i++){
        if(inDegree[projects[i] - 'a'] == 0) {
            queue[rear++] = projects[i];
        }
    }

    while(front < rear) {
        char current = queue[front++];
        buildOrder[orderIndex++] = current;

        Node* temp = graph[current - 'a'];
        while(temp) {
            int neighbor = temp->project - 'a';
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0) {
                queue[rear++] = temp->project;
            }
            temp = temp->next;
        }
    }

    if(orderIndex < numProjects) {
        return -1;
    }
    return orderIndex;
}
int main() {
    char projects[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int numProjects = sizeof(projects) / sizeof(projects[0]);

    char dependencies[][2] = {
        {'a', 'd'},
        {'f', 'b'},
        {'b', 'd'},
        {'f', 'a'},
        {'d', 'c'},
    };
    int numDependencies = sizeof(dependencies) / sizeof(dependencies[0]);

    char buildOrder[MAX_PROJECTS];

    int result = findBuildOrder(projects,numProjects, dependencies, numDependencies, buildOrder);

    if (result == -1) {
        printf("错误：存在循环依赖，无法找到合法的编译顺序。\n");
    } else {
        printf("编译顺序：");
        printBuildOrder(buildOrder, result);
    }

    return 0;
}