/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

int words_count = 0;
bool loaded = false;

typedef struct node
{
    char spelling[LENGTH+1];
    struct node *next;
}node;

//hash function 'djb2' via the website http://www.cse.yorku.ca/~oz/hash.html
int hashing(char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    
    int h = hash % TABLE_SIZE;
    return h;
}

node *hashtable[TABLE_SIZE];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //printf("here ");
    int l = strlen(word);
    
    char copy[l+1];
    int i;
    
    for(i = 0; i < l; i++)
        copy[i] = tolower(word[i]);
    
    copy[i]='\0';
    
    //printf("1%s ",copy);
    int hash = hashing(copy);
    
    //printf("2%s ",copy);
    node *head = hashtable[hash];
    
    while(head != NULL)
    {
        if(strcmp(head->spelling, copy)==0)
            return true;
        else
            head = head->next;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int i;
    FILE *dict = fopen(dictionary,"r");
    
    if(dict == NULL)
        fprintf(stderr, "Couldn't load dictioanry\n");
    
    for(i = 0; i < TABLE_SIZE; i++)
        hashtable[i] = NULL;
    
    while(true)
    {
        node *word = malloc(sizeof(node));
        
        if(word == NULL)
            fprintf(stderr, "Can't malloc space\n");
        
        if(fscanf(dict, "%s", word->spelling) == EOF)
        {
            free(word);
            break;
        }
        
        words_count++;
        
        word->next = NULL;
        int hash = hashing(word->spelling);
        
        if(hashtable[hash] == NULL)
            hashtable[hash] = word;
        
        else
        {
            word->next = hashtable[hash];
            hashtable[hash] = word;
        }
    }
    loaded = true;
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(loaded == true)
        return words_count;
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        node *head = hashtable[i];
        while(head != NULL)
        {
            node *list_head = head;
            head = head->next;
            free(list_head);
        }
    }
    loaded = false;
    return true;
}
