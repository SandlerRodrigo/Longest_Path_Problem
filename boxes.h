#ifndef BOXES_H_
#define BOXES_H_

#include <stdbool.h>

/**
 * @file boxes.h
 * @brief Header file for managing a graph of boxes, including functions for
 * creating, manipulating, and destroying the graph, as well as sorting and
 * comparing boxes.
 */

/**
 * @brief A structure representing a box with three dimensions.
 */
typedef struct box {
  short lowest;  ///< The lowest dimension of the box.
  short middle;  ///< The middle dimension of the box.
  short biggest; ///< The biggest dimension of the box.
} box;

/**
 * @brief A structure representing an edge in the graph.
 */
typedef struct edge {
  struct vertex *dest; ///< The destination vertex of the edge.
  struct edge *next;   ///< The next edge in the adjacency list.
} edge;

/**
 * @brief A structure representing a vertex in the graph.
 */
typedef struct vertex {
  struct box b;      ///< The box associated with this vertex.
  struct edge *head; ///< The head of the adjacency list for this vertex.
  int index; ///< The index of the vertex in the graph. (used for solving the
             ///< Longest Path problem)
} vertex;

/**
 * @brief A structure representing the graph.
 */
typedef struct graph {
  int size;                ///< The number of vertices in the graph.
  struct vertex *vertices; ///< The array of vertices in the graph.
} graph;

/**
 * @brief Initializes a graph from a file.
 *
 * @param filename The name of the file containing graph data.
 * @return A pointer to the initialized graph.
 */
graph *init_graph(char *filename);

/**
 * @brief Creates vertices from a file.
 *
 * @param filename The name of the file containing vertex data.
 * @param count A pointer to an integer to store the number of vertices created.
 * @return A pointer to the array of created vertices.
 */
vertex *create_vertices(const char *filename, int *count);

/**
 * @brief Initializes a new empty edge.
 *
 * @return A pointer to the initialized edge.
 */
edge *init_edge();

/**
 * @brief Adds all the edges to the graph, once all vertices are already
 * created.
 *
 * @param g A pointer to the graph.
 */
void add_edges(graph *g);

/**
 * @brief Adds an edge between two vertices.
 *
 * @param a A pointer to the source vertex.
 * @param b A pointer to the destination vertex.
 */
void add_edge(vertex *a, vertex *b);

/**
 * @brief Destroys the graph and frees all associated memory.
 *
 * @param g A pointer to the graph to be destroyed.
 */
void destroy_graph(graph *g);

/**
 * @brief Sorts the dimensions of a box in ascending order.
 *
 * @param b A pointer to the box to be sorted.
 */
void sort_box(box *b);

/**
 * @brief Checks if one box can fit into another.
 *
 * @param a A pointer to the first box.
 * @param b A pointer to the second box.
 * @return true if box a fits into box b, false otherwise.
 */
bool box_fits_into(box *a, box *b);

/**
 * @brief Compares two boxes by their dimensions. (used as parameter for C's
 * default qsort method)
 *
 * @param a A pointer to the first box.
 * @param b A pointer to the second box.
 * @return A negative value if a < b, zero if a == b, a positive value if a > b.
 */
int compare_boxes(const void *a, const void *b);

/**
 * @brief Sorts an array of vertices by the volume of their associated boxes.
 *
 * This is done using C's qsort function. Note that we do not use volume as a
 * way to check if a box fits into another, as that is not proof of fitting. We
 * sort our vertices array by their box's volume so that when finding the
 * longest path, the array is already sorted in topological order.
 *
 * @param vertices A pointer to the array of vertices.
 * @param size The number of vertices in the array.
 */
void sort_boxes_by_volume(vertex *vertices, int size);

/**
 * @brief Finds the longest nesting sequence of boxes in the graph.
 *
 * @param g A pointer to the graph.
 * @return The length of the longest nesting sequence.
 */
int longest_nesting(graph *g);

/**
 * @brief Prints the graph to the standard output.
 *
 * @param g A pointer to the graph.
 */
void print_graph(graph *g);

/**
 * @brief Prints the graph in DOT format for visualization.
 *
 * @param g A pointer to the graph.
 */
void print_dot(graph *g);

#endif // BOXES_H_