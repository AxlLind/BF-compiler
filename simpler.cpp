#include <cstdio>
#include <cstdlib>

unsigned char tape[500] = {0}, *p = tape;
char in[500], *e = in;

char* find_end() {
    char *end = e;
    int depth = 0;
    while (*end != ']' || depth > 0) {
        if (*end == '[') ++depth;
        if (*end == ']') --depth;
        ++end;
    }
    return ++end; // skip the ']'
}

void exec(char c); // forw decl
void loop() {
    char *start = e;
    while (*p != 0) {
        while (*e != ']')
            exec(*e);
        e = start;
    }
    e = find_end();
}

void exec(char c) {
    ++e;
    switch(c) {
        case '>': ++p;            break;
        case '<': --p;            break;
        case '+': ++*p;           break;
        case '-': --*p;           break;
        case '[': loop();         break;
        case ']': exit(1);        break;
        case '.': putchar(*p);    break;
        case ',': *p = getchar(); break;
    }
}

int main() {
    while ((*e = getchar()) != EOF)
        ++e; // read all into 'in'
    e = in;
    while (*e != EOF)
        exec(*e);
}
