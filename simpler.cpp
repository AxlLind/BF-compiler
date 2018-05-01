#include <algorithm>

unsigned char tape[500] = {0}, *p = tape;
char in[500], *e = in;

void loop();
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

void loop() {
    char *start = e;
    while (*p != 0) {
        char *start = e;
        while (*e != ']')
            exec(*e);
        e = start;
    }
    int depth = 0;
    while (*e != ']' || depth > 0) { // find end of loop
        if (*e == '[') ++depth;
        if (*e == ']') --depth;
        ++e;
    }
    ++e; // skip the ']'
    return;
}

int main() {
    while ((*e = getchar()) != EOF)
        ++e; // read all into 'in'
    e = in;
    while (*e != EOF)
        exec(*e);
}
