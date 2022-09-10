#include <stdio.h>
#include "main.h"
#include "sublib1/sublib1.h"
#include "sublib2/sublib2.h"

int main(void)
{
	printf("%s",MAIN_INFO);
	sublib1_print();
	sublib2_print();
	return 0;
}
