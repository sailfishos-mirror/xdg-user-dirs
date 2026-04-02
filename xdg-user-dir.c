#include "xdg-user-dir-lookup.c"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  char *dir;
  dir = xdg_user_dir_lookup (argc >= 2 ? argv[1] : "");
  if (dir != NULL)
    {
      printf ("%s\n", dir);
      free (dir);
      return 0;
    }
  return 1;
}
