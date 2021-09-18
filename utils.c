#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// destroy c project
void DestroyCProject(CProject* cp)
{
    free(cp->c_file);
    free(cp->h_file);
    free(cp->build_file);
}

// destroy python project
void DestroyPythonProject(PythonProject* pp)
{
    free(pp->python_file);
}

// destroy web project
void DestroyWebProject(WebProject* wp)
{
    free(wp->html_file);
    free(wp->css_file);
    free(wp->js_file);
}

// simple write file method
void WriteFile(FILE* file, char* path, char* text)
{
    file = fopen(path, "w");
    fprintf(file, text);
    fclose(file);

    printf("[+] Added %s...\n", path);
}

// c project
void CreateCProject(char* name)
{
    printf("[*] Initializing Project Directory...\n");
    mkdir(name, 0700);
    printf("Done!\n\n");

    printf("[*] Initializing Project Structure...\n");
    CProject* cproj = (CProject*) malloc(sizeof(CProject));
    printf("Done!\n\n");

    printf("[*] Initializing File Paths...\n");
    char c_path[32];
    char h_path[32];
    char build_path[32];

    snprintf(c_path, sizeof(c_path), "%s/main.c", name);
    snprintf(h_path, sizeof(h_path), "%s/main.h", name);
    snprintf(build_path, sizeof(build_path), "%s/build.bat", name);
    printf("Done!\n\n");

    WriteFile(cproj->c_file, c_path, "#include \"main.h\"\n\n#include <stdio.h>\n\nvoid PrintHello()\n{\n\tprintf(\"hello\");\n}\n\nint main(int argc, char** argv)\n{\n\tPrintHello();\n}");
    WriteFile(cproj->h_file, h_path, "#ifndef MAIN_H\n\n#define MAIN_H\n\nvoid PrintHello();\n\n#endif");
    WriteFile(cproj->build_file, build_path, "gcc -Wall -c main.c\ngcc -o main main.o");
    printf("Done!\n");
    
    DestroyCProject(cproj);
    free(cproj);
}

// python project
void CreatePythonProject(char* name)
{
    printf("[*] Initializing Project Directory...\n");
    mkdir(name, 0700);
    printf("Done!\n\n");

    printf("[*] Initializing Project Structure...\n");
    PythonProject* pythonproj = (PythonProject*) malloc(sizeof(PythonProject));
    printf("Done!\n\n");

    printf("[*] Initializing File Paths...\n");
    char python_path[32];

    snprintf(python_path, sizeof(python_path), "%s/main.py", name);
    printf("Done!\n\n");

    WriteFile(pythonproj->python_file, python_path, "print(\"hello\")");
    printf("Done!\n");
    
    DestroyPythonProject(pythonproj);
    free(pythonproj);
}

// web project
void CreateWebProject(char* name)
{
    printf("[*] Initializing Project Directory...\n");
    mkdir(name, 0700);
    printf("Done!\n\n");

    printf("[*] Initializing Project Structure...\n");
    WebProject* webproj = (WebProject*) malloc(sizeof(WebProject));
    printf("Done!\n\n");

    printf("[*] Initializing File Paths...\n");
    char html_path[32];
    char css_path[32];
    char js_path[32];

    snprintf(html_path, sizeof(html_path), "%s/index.html", name);
    snprintf(css_path, sizeof(css_path), "%s/index.css", name);
    snprintf(js_path, sizeof(js_path), "%s/index.js", name);
    printf("Done!\n\n");

    WriteFile(webproj->html_file, html_path, "<html>\n\t<head>\n\t\t<link rel=\"stylesheet\" href=\"index.css\">\n\t</head>\n\t<body>\n\t\t<script src=\"index.js\"></script>\n\t</body>\n</html>");
    WriteFile(webproj->css_file, css_path, "body\n{\n\tbackground-color: black;\n\tcolor: white;\n}");
    WriteFile(webproj->js_file, js_path, "document.write(\"hello world\");");
    printf("Done!\n");
    
    DestroyWebProject(webproj);
    free(webproj);
}