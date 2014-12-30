/* Example program which copies overlapping memory regions with memcpy */

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------ */

#define REGION_SIZE 37

static void
overlapping_copy (void)
{
  void *a1 = malloc (REGION_SIZE);
  void *a2 = a1 + 7;
  int i;
  memset (a1, 0, REGION_SIZE);  /* Initialize source region */
  for (i = 0; i < 8; i++)
    {
      memcpy (a1, a2, 10 + i);  /* Source and destination regions overlap */
    }
  free (a1);
}

/* ------------------------------------------------------------------------ */

static void
overlapping_copy_a (void)
{
  void *a1 = malloc (REGION_SIZE);
  void *a2 = a1;
  memset (a1, 0, REGION_SIZE);  /* Initialize source region */
  memcpy (a1, a2, REGION_SIZE); /* Source and destination are the same */
  free (a1);
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  overlapping_copy ();
  overlapping_copy_a ();
  return 0;
}


