/* Return true if the CPU supports the RDRAND instruction.  */
_Bool rdrand_supported (void);

/* Initialize the hardware rand64 implementation.  */
void hardware_rand64_init (void);

/* Return a random value, using hardware operations.  */
unsigned long long hardware_rand64 ();

unsigned long long hardware_mrand48 ();

/* Finalize the hardware rand64 implementation.  */
void hardware_rand64_fini (void);
