#ifndef UTILS_H

#define UTILS_H

#include <stdio.h>

struct CProject
{
    FILE *c_file;
    FILE *h_file;
    FILE *build_file;
};

struct PythonProject
{
    FILE *python_file;
};

struct WebProject
{
    FILE *html_file;
    FILE *css_file;
    FILE *js_file;
};

// c project
void CreateCProject(char name[]);

// python project
void CreatePythonProject(char name[]);

// web project
void CreateWebProject(char name[]);

#endif