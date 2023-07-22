#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue implementation for BFS
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Add an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_NODES - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
}

// Remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;
    return item;
}

// Structure to represent a graph node
struct Node {
    int value;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numNodes;
    struct Node** adjList;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with a given number of nodes
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    graph->adjList = (struct Node**)malloc(numNodes * sizeof(struct Node*));

    for (int i = 0; i < numNodes; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Breadth-First Search algorithm
void BFS(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};

    struct Queue* queue = createQueue();
    visited[startNode] = 1;
    enqueue(queue, startNode);

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);

        struct Node* temp = graph->adjList[currentNode];
        while (temp) {
            int adjNode = temp->value;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                enqueue(queue, adjNode);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    if (graph) {
        for (int i = 0; i < graph->numNodes; i++) {
            struct Node* temp = graph->adjList[i];
            while (temp) {
                struct Node* prev = temp;
                temp = temp->next;
                free(prev);
            }
        }
        free(graph->adjList);
        free(graph);
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("Breadth-First Traversal (starting from node 0): ");
    BFS(graph, 0);

    freeGraph(graph);

    return 0;
}
