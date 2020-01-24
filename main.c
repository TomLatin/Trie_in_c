#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Trie.h"

int main(int argc,char* argv[]) {

    boolean revers=FALSE ,flag=FALSE;
    char * key=(char*)malloc (sizeof(char)*300);
    int sizeKey=300 ,count=0;
    char currentCh=getchar();
    node * root=getNode();
    char * temp=null;

    //insertion to trie
    while (currentCh!=EOF || (currentCh==EOF && flag!=TRUE)) {
        if (currentCh >= 'A' && currentCh <= 'Z') {
            currentCh = currentCh + ('a' - currentCh);
        }

        if (currentCh >= 'a' && currentCh <= 'z' && currentCh != ' ' && currentCh != '\n' && currentCh != '\0' && currentCh != '\t') {
            if (count == sizeKey) {
                temp = (char *) realloc(key, sizeof(char) * (sizeKey + TO_ADD));
                sizeKey = sizeKey + TO_ADD;
                if (temp == null && key != null) //the realloc didnt succeed
                {
                    free(key);
                    return -1;
                }
            }
            key = (*char)calloc(sizeKey, sizeof(char));
            strcpy(key, temp);
            free(temp);
        }

        key[count] = currentCh;
        count++;

        else if (currentCh != EOF && (currentCh == ' ' && currentCh == '\n' && currentCh == '\0' && currentCh == '\t')) {
            key[count] = '\0';
            if (key[0] != ' ' && count >= 1) {
                insert(&root, key);
            }
            count = 0;
        }

        else if (currentCh == EOF) {
            flag = TRUE;
        }
        currentCh = getchar();
    }

    //Checks whether to print reverse or normal
    if(argc==2 && strcmp(argv[1],"r")==0)
    {
        revers=TRUE;
    }

    if(revers)
    {
        printReverse(&root,key,0);
    }

    else
    {
        print(&root,key,0);
    }

    //free all the malloc we do in the program
    freeAllTrie(&root);
    free(key);

    return 0;
}
