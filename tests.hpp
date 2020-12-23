#pragma once

#include <cstdio>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(TEXT) KRED TEXT RST
#define FGRN(TEXT) KGRN TEXT RST
#define FYEL(TEXT) KYEL TEXT RST
#define FBLU(TEXT) KBLU TEXT RST
#define FMAG(TEXT) KMAG TEXT RST
#define FCYN(TEXT) KCYN TEXT RST
#define FWHT(TEXT) KWHT TEXT RST

#define BOLD(TEXT) "\x1B[1m" TEXT RST
#define UNDL(TEXT) "\x1B[4m" TEXT RST

#define TEST_BEGIN(PROGRAM_NAME, PROGRAM_VERSION)                                   \
    printf("%s (%s)\n\n", UNDL(BOLD(PROGRAM_NAME)), UNDL(BOLD(PROGRAM_VERSION)));   \
    int exit_code = 0;

#define TEST_END() return exit_code;

#define TEST_SECTION(NAME) printf("SECTION (%d): %s\n", __COUNTER__, UNDL(FCYN(NAME))); 

#define TEST_ASSERT(NAME, CONDITION)        \
    if (!(CONDITION)) {                     \
        exit_code = 1;                      \
    }                                       \
    printf("  %s => %s - (%s)\n",           \
            ((CONDITION)                    \
             ? FGRN("passed")               \
             : FRED("failed")), FYEL(NAME), #CONDITION);


