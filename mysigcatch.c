#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * Interrupt handler when SIGINT is caught
 *
 * @param signum The signal number received
 */
void sigintHandler(int signum) {
    fprintf(stdout, "\nSIGINT signal (%d) detected...\nTerminating...\n", signum);
    exit(EXIT_SUCCESS);
}

/**
 * This function sets up a signal handler for SIGINT,
 * provides information about handling SIGINT,
 * and waits indefinitely.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 *
 * @return Exit status
 */
int main(int argc, char** argv) {
    /// Indicate the custom handler for SIGINT
    if (signal(SIGINT, sigintHandler) == SIG_ERR) {
        fprintf(stderr, "Unable to catch SIGINT\n");
        return EXIT_FAILURE;
    }

    /// Wait for the signal to be generated
    fprintf(stdout, "Waiting to catch a SIGINT signal...\n");
    while (1);

    return 0;
}

