/* Example program which allocates memory and fails to free it */

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------ */

static void
illegal_free_from_stack (void)
{
  char *s = "A string on the stack";
  free (s);                     /* Freeing a string on the stack */
}

/* ------------------------------------------------------------------------ */

static void
illegal_free_from_heap_inside_allocated_region (void)
{
  void *p = malloc (1 + rand () % 127); /* Allocate a randomly sized region up to 128 bytes */
  free (p + 8);                 /* Freeing an address inside an allocated region */
  free (p);                     /* Free the correct address */
}

/* ------------------------------------------------------------------------ */

static void
illegal_free_from_heap_outside_allocated_region (void)
{
  void *p = malloc (1 + rand () % 321); /* Allocate a randomly sized region up to 322 bytes */
  free (p - 4);                 /* Freeing an address outside an allocated region */
  free (p);                     /* Free the correct address */
}

/* ------------------------------------------------------------------------ */

struct misc
{
  double d;
  float f;
  int i;
  char s[3];
};

static void
leak_memory (void)
{
  char *s = malloc (80);
  double *d_ptr = malloc (sizeof (double));
  float *f_ptr = malloc (sizeof (float));
  int *i_ptr = malloc (sizeof (int));
  struct misc *misc_ptr = malloc (sizeof (struct misc));
  *d_ptr = 1.234e-5;
  *f_ptr = 0.12e1;
  *i_ptr = 1234;
  strcpy (s, "leak_memory function wrote this");
  /* Memory allocated in this function is not freed before function exit */
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  illegal_free_from_stack ();
  illegal_free_from_heap_inside_allocated_region ();
  illegal_free_from_heap_outside_allocated_region ();
  leak_memory ();
  return 0;
}

