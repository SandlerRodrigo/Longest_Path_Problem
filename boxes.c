#include "boxes.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

graph *init_graph(char *filename) {
    graph *g = (graph *)malloc(sizeof(graph));
    int count;
    g->vertices = create_vertices(filename, &count);
    if (!g->vertices) {
        printf("\tUnable to initialize graph.");
        return NULL;
    }
    g->size = count;

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    add_edges(g);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nIt took me %f seconds to add edges to this graph.\n\n", cpu_time_used);


    return g;
}

vertex* create_vertices(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if(!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return NULL;
    }

    char ch;
    *count = 1;
    while(!feof(file)) {
        ch = fgetc(file);
        if(ch == '\n') {
            (*count)++;
        }
    }
    rewind(file);

    vertex* vertices = malloc((*count) * sizeof(vertex));
    if (!vertices) {
        printf("Unable to allocate memory for the vertices array.\n");
        return NULL;
    }

    for(int i = 0; i < *count; i++) {
        fscanf(file, "%hd %hd %hd", &vertices[i].b.lowest, &vertices[i].b.middle, &vertices[i].b.biggest);
        sort_box(&vertices[i].b);
        vertices[i].head = NULL;
    }

    fclose(file);

    return vertices;
}

edge *init_edge() {
    edge *new_edge = (edge *)malloc(sizeof(edge));
    new_edge->dest = NULL;
    new_edge->next = NULL;
    return new_edge;
}

void add_edges(graph *g) {
    sort_boxes_by_volume(g->vertices, g->size);

    for(int src = 0; src < g->size; src++) {
        g->vertices[src].index = src;
        for (int dest = src + 1; dest < g->size; dest++) {
            if(box_fits_into(&g->vertices[src].b, &g->vertices[dest].b)) {
                add_edge(&g->vertices[src], &g->vertices[dest]);
            }
        }
    }
}

void add_edge(vertex *a, vertex *b) {
    edge *new_edge = init_edge();
    new_edge->dest = b;
    edge *aux = a->head;
    a->head = new_edge;
    new_edge->next = aux;
}

void destroy_graph(graph *g) {
    for(int i = 0; i < g->size; i++) {
        edge *head = g->vertices[i].head;
        while(head) {
            edge *aux = head;
            head = head->next;
            free(aux);
        }
    }
    free(g->vertices);
    free(g);
}

void sort_box(box *b) {
    short temp;
    if (b->lowest > b->middle) {
        temp = b->lowest;
        b->lowest = b->middle;
        b->middle = temp;
    }
    if (b->middle > b->biggest) {
        temp = b->middle;
        b->middle = b->biggest;
        b->biggest = temp;
    }
    if (b->lowest > b->middle) {
        temp = b->lowest;
        b->lowest = b->middle;
        b->middle = temp;
    }
}

bool box_fits_into(box* a, box* b) {
    return (a->lowest < b->lowest && a->middle < b->middle && a->biggest < b->biggest); 
}

int compare_boxes(const void *a, const void *b) {
    vertex *vertexA = (vertex *)a;
    vertex *vertexB = (vertex *)b;
    return (vertexA->b.lowest * vertexA->b.middle * vertexA->b.biggest) - (vertexB->b.lowest * vertexB->b.middle * vertexB->b.biggest);
}

void sort_boxes_by_volume(vertex *vertices, int size) {
    qsort(vertices, size, sizeof(vertex), compare_boxes);
}

int longest_nesting(graph *g) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int *maxDepth = malloc(g->size * sizeof(int));
    for (int i = 0; i < g->size; i++) {
        maxDepth[i] = 1;
    }

    for(int i = 0; i < g->size; i++) {
        edge *e = g->vertices[i].head;
        while (e) {
            int u = e->dest->index;
            if (maxDepth[u] < maxDepth[i] + 1) {
                maxDepth[u] = maxDepth[i] + 1;
            }
            e = e->next;
        }
    }
    int max = 0;
    for (int i = 0; i < g->size; i++) {
        if (maxDepth[i] > max) {
            max = maxDepth[i];
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("It took me %f seconds to find the longest path in this graph.\n", cpu_time_used);

    free(maxDepth);
    return max;
}

void print_graph(graph *g) {
    for(int i = 0; i < g->size; i++) {
        printf("%hd %hd %hd -> ", g->vertices[i].b.lowest, g->vertices[i].b.middle, g->vertices[i].b.biggest);
        edge *head = g->vertices[i].head;
        while(head) {
            printf("%hd %hd %hd -> ", head->dest->b.lowest, head->dest->b.middle, head->dest->b.biggest);
            head = head->next;
        }
        printf("NULL\n");
    }
}

void print_dot(graph *g) {
    printf("digraph G {\n");
    printf("\t// Declaring the nodes with unique aliases\n");
    for(int i = 0; i < g->size; i++) {
        printf("\t\"%p\" [label=\"%hd %hd %hd\"];\n", &g->vertices[i], g->vertices[i].b.lowest, g->vertices[i].b.middle, g->vertices[i].b.biggest);
    }
    printf("\n\t//Specifying the connections (edges)\n");
    for(int i = 0; i < g->size; i++) {
        vertex *curr = &g->vertices[i];
        edge *aux = curr->head;
        while(aux) {
            printf("\t\"%p\" -> \"%p\"\n", curr, aux->dest);
            aux = aux->next;
        }
    }
    printf("}\n");
}