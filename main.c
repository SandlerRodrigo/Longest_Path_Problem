#include "boxes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Available functions:
 *  graph *init_graph(char *filename);
 *  void destroy_graph(graph *g);
 *  int longest_nesting(graph *g);
 *  void print_graph(graph *g);
 *  void print_dot(graph *g);
 */

int main(int argc, char *argv[]) {
  clock_t start, end;
  double cpu_time_used;
  start = clock();

  if (argc < 2) {
    printf("Run main with boxes file's name.\n");
    exit(EXIT_FAILURE);
  }
  graph *g = init_graph(argv[1]);

  // printf("\nLongest nesting: %d\n\n", longest_nesting(g));
  print_graph(g);
  // print_dot(g);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  // printf("Total execution time: %f seconds\n\n", cpu_time_used);

  destroy_graph(g);
  exit(EXIT_SUCCESS);
}