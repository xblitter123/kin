#ifndef UTILS_H

#define UTILS_H

#include <stdio.h>

typedef struct
{
    FILE* c_file;
    FILE* h_file;
    FILE* build_file;
} CProject;

typedef struct
{
    FILE *python_file;
} PythonProject;

typedef struct
{
    FILE* html_file;
    FILE* css_file;
    FILE* js_file;
} WebProject;

// c project
void CreateCProject(char name[]);

// python project
void CreatePythonProject(char name[]);

// web project
void CreateWebProject(char name[]);

#endif