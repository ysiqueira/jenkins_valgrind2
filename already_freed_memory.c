/* Example program which access memory that was already freed */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 80

#define TEST_STRING "A test?"

/* ------------------------------------------------------------------------ */

static void
access_already_freed_memory_copy_1_byte (void)
{
  char *s = malloc (BUFFER_SIZE);
  assert (strlen (TEST_STRING) < BUFFER_SIZE);
  strcpy (s, TEST_STRING);
  assert (!strcmp (s, TEST_STRING));
  free ((void *) s);
  strcpy (s, "");               /* Assigning 1 byte to already freed memory */
}

/* ------------------------------------------------------------------------ */

static void
access_already_freed_memory_full_strcpy (void)
{
  char *s = malloc (BUFFER_SIZE);
  assert (strlen (TEST_STRING) < BUFFER_SIZE);
  strcpy (s, TEST_STRING);
  assert (!strcmp (s, TEST_STRING));
  free ((void *) s);
  strcpy (s, TEST_STRING);      /* Assigning to already freed memory */
}

/* ------------------------------------------------------------------------ */

static void
access_already_freed_memory_memcpy (void)
{
  char *s = malloc (BUFFER_SIZE);
  assert (strlen (TEST_STRING) < BUFFER_SIZE);
  strcpy (s, TEST_STRING);
  assert (!strcmp (s, TEST_STRING));
  free ((void *) s);
  memcpy (s + 1, TEST_STRING, 5);       /* Assigning to already freed memory */
}

/* ------------------------------------------------------------------------ */

int
main (void)
{
  access_already_freed_memory_copy_1_byte ();
  access_already_freed_memory_full_strcpy ();
  access_already_freed_memory_memcpy ();
  return 0;
}

