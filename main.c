#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char *argv[])
{
	// i wish there waqs a better way of doing this (there probably is)
	if(argc > 2)
	{
		if(strcmp(argv[1], "-c") == 0)
		{
			CreateCProject(argv[2]);
		}
		else if(strcmp(argv[1], "-py") == 0)
		{
			CreatePythonProject(argv[2]);
		}
		else if(strcmp(argv[1], "-web") == 0)
		{
			CreateWebProject(argv[2]);
		}
	}
	else
	{
		printf("kin 2021\n\n-c [project name]\tC Project\n-py [project name]\tPython Project\n-web [project name]\tWeb Project");
	}
}