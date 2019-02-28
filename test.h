#ifndef __TEST_H__
#define __TEST_H__

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define VALIDATE(func) if (func != E_OK) \
		printf(KYEL "Error in line: %d\n" KNRM, __LINE__);

#endif
