/* Example program which copies overlapping memory regions with memcpy */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* ------------------------------------------------------------------------ */

static void
illegal_system_call (void)
{
  char *buf = malloc (50);
  write (1, buf, 4);            /* Error, uninitialized data */
  write (1, buf + 4, 4);        /* Error, uninitialized data */
  write (1, buf + 8, 4);        /* Error, uninitialized data */
  write (1, buf + 12, 4);       /* Error, uninitialized data */
  write (1, buf + 16, 4);       /* Error, uninitialized data */
  free (buf);
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  illegal_system_call ();
  return 0;
}


