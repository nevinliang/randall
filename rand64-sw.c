#include <stdio.h>
#include <stdlib.h>

#include "rand64-sw.h"

/* Software implementation.  */

/* Input stream containing random bytes.  */
FILE *urandstream;

void initfile (char* file)
{
    urandstream = fopen (file, "r");
    if (! urandstream) {
        fprintf (stderr, "Invalid file: %s\n", file);
        abort ();
    }
}

/* Initialize the software rand64 implementation.  */
void software_rand64_init (void)
{
    if (urandstream == NULL)
        initfile("/dev/random");
}

/* Return a random value, using software operations.  */
unsigned long long software_rand64 (void)
{
    unsigned long long int x;
    if (fread (&x, sizeof x, 1, urandstream) != 1)
        abort ();
    return x;
}

/* Finalize the software rand64 implementation.  */
void software_rand64_fini (void)
{
    fclose (urandstream);
}
