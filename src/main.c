#include <clap/clap.h>

// The purpose of this file is to check that all headers compile
int main(int argc, char **argv) {
   clap_version_t m = CLAP_VERSION;
   return !clap_version_is_compatible(m);
}