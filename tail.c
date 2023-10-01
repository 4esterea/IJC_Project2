// tail.c
// Řešení IJC-DU2, příklad a), 15.4.2023
// Autor: Zhdanovich Iaroslav, FIT
// Přeloženo: gcc 9.4.0

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 4095+1

typedef struct Line{
    struct Line *previous;
    struct Line *next;
    char *content;
} Line;

typedef struct CB{
    struct Line *first;
    struct Line *last;
    int tailSize;
    int current;
} CB ;

void printError(int errorcode){
    switch(errorcode)
    {
        case 1:
            fprintf(stderr, "Wrong number of arguments\n");
            break;
        case 2:
            fprintf(stderr, "Number of lines provided incorrectly\n");
            break;
        case 3:
            fprintf(stderr, "File cannot be opened\n");
            break;
        case 4:
            fprintf(stderr, "Memory allocation error\n");
            break;
    }
    exit(1);
}

void deallocLine(Line *line){
    line->next = NULL;
    line->previous = NULL;
    free(line->content);
    free(line);
}

Line *allocLine(){
    Line *line = malloc(sizeof(Line));
    if (!line) printError(4);
    line->next = NULL;
    line->previous = NULL;
    line->content = malloc(sizeof(char) * MAX_CHARS);
    if (!(line->content)) printError(4);
    return line;
}

CB *cb_create(int count){
    CB *circBuffer = malloc(sizeof(CB));
    if (!circBuffer) printError(4);
    circBuffer->first = NULL;
    circBuffer->last = NULL;
    circBuffer->tailSize = count;
    circBuffer->current = 0;
    return circBuffer;
}

void cb_put(CB *tail, char *content){
    Line *line = allocLine();
    strcpy(line->content, content);
    Line *temp;
    if (tail->first == NULL){
        tail->first = line;
        tail->last = line;
        tail->current = 1;
        return;
    } else if (tail->tailSize > tail->current) {
        temp = tail->first;
        tail->first = line;
        tail->first->next = temp;
        temp->previous = tail->first;
        tail->current = tail->current + 1;
    } else {
        temp = tail->first;
        tail->first = line;
        tail->first->next = temp;
        temp->previous = tail->first;
        temp = tail->last;
        tail->last = temp->previous;
        tail->last->next = NULL;
        deallocLine(temp);
    }
}

void cb_get(CB *cb) {
    Line *line = cb->last;
    while (line != NULL) {
        printf("%s", line->content);
        if (!(strchr(line->content, '\n'))) puts("");
        line = line->previous;
    }
}

void cb_free(CB *cb) {
    Line *current = cb->first;
    while (current != NULL) {
        Line *next = current->next;
        deallocLine(current);
        current = next;
    }
    free(cb);
}


int checkArgs( int argc, char *argv[], int *linesToType){
    int index = -1;
    if (argc == 1) return index;
    if (argc > 4 || argc < 1) printError(1);
    for (int i = 1; i < argc; i++){
        if (!(strcmp("-n", argv[i]))){
            if (i + 1 >= argc) printError(2);
            *linesToType = atoi(argv[i + 1]);
            if (*linesToType <= 0) printError(2);
            i++;
        } else {
            index = i;
        }
    }
    return index;
}

int main( int argc, char *argv[]){
    FILE *input = stdin;
    int linesToType = 10;
    int index = checkArgs(argc, argv, &linesToType);
    CB *tail = cb_create(linesToType);
    char newLine[MAX_CHARS];
    if (index != -1){
        input = fopen(argv[index], "r");
        if (!(input)) printError(3);
    }
    bool overflowFlag = false;
    int lineNumber = 1;
    while((fgets(newLine, MAX_CHARS, input))){
        cb_put(tail, newLine);
        char c;
        if (strlen(newLine) == MAX_CHARS - 1){
            while ((c = fgetc(input)) != EOF && c != '\n'){
                if (overflowFlag == false){
                    fprintf(stderr, "Line %i exceeds maximum length of characters\n", lineNumber);
                    overflowFlag = true;
                }
            }
        }
        lineNumber++;
    }
    cb_get(tail);
    cb_free(tail);
    fclose(input);
    return 0;
}