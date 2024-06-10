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

  printf("\nLongest nesting: %d\n\n", longest_nesting(g));
  // print_graph(g);
  // print_dot(g);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Total execution time: %f seconds\n\n", cpu_time_used);

  destroy_graph(g);
  exit(EXIT_SUCCESS);
}

// int main() {
//     srand(time(NULL));
//     FILE *file = fopen("boxes.txt", "w");

//     if (file == NULL) {
//         printf("Error opening file!\n");
//         return 1;
//     }

//     for (int i = 0; i < 20000; i++) {
//         for (int j = 0; j < 3; j++) {
//             int dimension = rand() % 999 + 1;
//             fprintf(file, "%03d ", dimension);
//         }
//         fprintf(file, "\n");
//     }

//     fclose(file);
//     return 0;
// }