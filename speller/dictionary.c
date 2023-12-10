// Implements a dictionary's functionality
#include<stdio.h>
#include<math.h>
#include <ctype.h>
#include <stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<strings.h>
unsigned int Letter_size = 0;
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *point = table[index];
    while(point !=  NULL)
    {
        if(strcasecmp(point-> word,word) == 0)
        {
            return true;
        }
        point = point->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int value = 0;
    unsigned int key_len = strlen(word);
    for(int i = 0; i < key_len;i++)
    {
        value = value + 37 * tolower(word[1]);


    }
    value = value % N;
        return value;

    // TODO: Improve this hash function

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *open_dictionary = fopen(dictionary,"r");
    if(open_dictionary == NULL)
{
    return false;
}
char Typeword[LENGTH + 1];
while(fscanf(open_dictionary, "%s",Typeword) != EOF)
{
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL)
    {
        return false;
    }
    strcpy(newNode -> word, Typeword);
    newNode -> next = NULL;
    int index = hash(Typeword);

    if(table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        newNode -> next = table[index];
        table[index] = newNode;
    }
    Letter_size++;
}
fclose(open_dictionary);
return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return Letter_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    while(table[i] != NULL)
    {
        node *tmp = table[i]-> next;
        free(table[i]);
        table[i]= tmp;
    }
    return true;
}
