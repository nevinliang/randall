#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "options.h"

void readopt(int argc, char **argv, struct opts* opts) {
    opts->valid = false;
    // get the options
    int c;
    while ((c = getopt(argc, argv, ":i:o:")) != -1) {
        switch(c) {
            case 'i':
                if (strcmp("rdrand", optarg) == 0)
                    opts->input = RDRAND;
                else if (strcmp("mrand48_r", optarg) == 0)
                    opts->input = MRAND48_R;
                else if ('/' == optarg[0]) {
                    opts->input = SLASH_F;
                    opts->r_src = optarg;
                }
                else
                    return;
                opts->valid = true;
                break;
            case 'o':
                if (strcmp("stdout", optarg) == 0)
                    opts->output = STDOUT;
                else {
                    opts->output = N;
                    opts->block_size = atoi(optarg);
                    if (opts->block_size == 0) {
                        fprintf (stderr,
                                "Option -o N requires a valid block size\n");
                        return;
                    }
                }
                opts->valid = true;
                break;
            case ':':
                fprintf (stderr, "Option -%c requires an operand\n", optopt);
                return;
            case '?':
                fprintf (stderr, "Unrecognized option: '-%c'\n", optopt);
                return;
        }
    }

    if (optind >= argc)
        return;

    opts->nbytes = atol(argv[optind]);
    if (opts->nbytes >= 0)
        opts->valid = true;
}
