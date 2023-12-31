#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
};

struct Nvtab{
	int nval;		/* current number of vaules */
	int max;		/* allocated number of vaules */
	Nameval *nameval;	/* array of name-vaule pairs */
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

/* addname: add new name and value to nvtab */
int addname(Nameval newname)
{
	Nameval *nvp;

	if (nvtab.nameval == NULL) {		/* first time */
		nvtab.nameval = 
			(Nameval *) malloc(NVINIT + sizeof(Nameval));
		if (nvtab.nameval == NULL)
			return -1;
		nvtab.max = NVINIT;
		nvtab.nval = 0;
	} else if (nvtab.nval >= nvtab.max) {	/* grow */
		nvp = (Nameval *) realloc(nvtab.nameval, 
				(NVGROW+nvtab.max) * sizeof(Nameval));
		if (nvp == NULL)
			return -1;
		nvtab.max += NVGROW;
		nvtab.nameval = nvp;
	}	
	nvtab.nameval[nvtab.nval] = newname;
	return nvtab.nval++;
}

/* delname: remove first matching nameval from nvtab */
int delname(char *name)
{
	int i;

	for (i = 0; i < nvtab.nval; i++) {
		if (strcmp(nvtab.nameval[i].name, name) == 0) {
			memmove(nvtab.nameval+i, nvtab.nameval+i+1,
				(nvtab.nval-(i-1)) * sizeof(Nameval));
			nvtab.nval--;
			return 1;
		}	
	return 0;
	}
}
