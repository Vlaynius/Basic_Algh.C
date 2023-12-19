#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 31
#define MAX_NAME 50

typedef struct User
{
    char *username;
    int deleted;
} User;

typedef struct
{
    User *table[TABLE_SIZE];
} Hashtable;

void initializeHashtable(Hashtable *ht)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }
}

int hornerRule(char *userName)
{
    int hashVal = 0;
    int i;
    int length = strlen(userName);
    for (i = 0; i < length; i++)
    {
        int letter = (int)(userName[i]);
        hashVal = (hashVal * 31 + letter) % TABLE_SIZE;
    }
    return hashVal;
}

int hash1(int key)
{
    return key % TABLE_SIZE;
}

int hash2(int key)
{
    int M2 = TABLE_SIZE - 2;
    return 1 + (key % M2);
}

int hash(char *userName, int i)
{
    int key = hornerRule(userName);
    return (hash1(key) + i * hash2(key)) % TABLE_SIZE;
}

void insert(Hashtable *ht, char *newbie)
{
    int i = 0;
    unsigned int index = hash(newbie, i);

    while (ht->table[index] != NULL && strcmp(ht->table[index]->username, newbie) != 0)
    {
        i++;
        index = hash(newbie, i);
    }

    if (ht->table[index] != NULL && strcmp(ht->table[index]->username, newbie) == 0)
    {
        if (ht->table[index]->deleted == 0)
        {
            printf("\nThis user already signed...");
        }
        else
        {
            ht->table[index]->deleted = 0;
            printf("\nUser signed again...");
        }
        return;
    }

    // Create a new entry
    User *newUser = (User *)malloc(sizeof(User));
    newUser->username = strdup(newbie);
    newUser->deleted = 0;

    // Insert the entry into the hashtable
    ht->table[index] = newUser;
    printf("\nUser signed...");
}

int search(Hashtable *ht, char *key)
{
    int i = 0;
    unsigned int index = hash(key, i);

    while (ht->table[index] != NULL)
    {
        if (strcmp(ht->table[index]->username, key) == 0)
        {
            if (ht->table[index]->deleted == 0)
            {
                printf("\nUser found in %d. line...", index);
                return index;
            }
            else
            {
                printf("\nUser found in %d. line but already deleted...", index);
                return -2;
            }
        }
        i++;
        index = hash(key, i);
    }
    // Key not found
    printf("\nUser not found...");
    return -1;
}

void deleteUser(Hashtable *ht, char *key)
{
    unsigned int found = search(ht, key);
    if (found < 0 || ht->table[found] == NULL)
    {
        return;
    }
    ht->table[found]->deleted = 1;
    printf("\nUser deleted...");
}

void printHashtable(Hashtable *ht)
{
    printf("Hashtable Contents:\n");
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (ht->table[i] != NULL && ht->table[i]->deleted == 0)
        {
            printf("[%d] username: %s\n", i, ht->table[i]->username);
        }
        else
        {
            printf("[%d] Empty\n", i);
        }
    }
}

void freeHashtable(Hashtable *ht)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (ht->table[i] != NULL)
        {
            free(ht->table[i]->username);
            free(ht->table[i]);
        }
    }
}

int main()
{
    Hashtable myHashtable;
    initializeHashtable(&myHashtable);

    insert(&myHashtable, "one");
    insert(&myHashtable, "two");
    insert(&myHashtable, "three");

    search(&myHashtable, "two");

    deleteUser(&myHashtable, "two");

    search(&myHashtable, "two");

    freeHashtable(&myHashtable);
    return 0;
}

