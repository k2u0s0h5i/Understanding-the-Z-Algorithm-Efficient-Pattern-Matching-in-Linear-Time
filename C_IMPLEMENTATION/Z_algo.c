#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

void getZarr(const char *str,int *z) {
    int n=strlen(str);
    int l=0,r=0,k=0;
    int i;
    for(i=1;i<n;++i) {
        if(i>r)
        {
            l=r=i;
            while(r<n && str[r-l] == str[r])
                r++;
            z[i]=r-l;
            r--;
        } 
        else
        {
            k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else
            {
                l=i;
                while(r<n && str[r-l] == str[r])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }
}

void search(const char *text,const char *pattern) {
    int textLength=strlen(text);
    int patternLength=strlen(pattern);
    char concat[textLength+patternLength+2];
     // '+2' for '$' and null terminator
     if (patternLength==0) {
        printf("Empty pattern\n");
        return;
    }
    if(patternLength>textLength){
    	printf("Pattern Not Found");
	}

    strcpy(concat,pattern);
    strcat(concat,"$");
    strcat(concat,text);
    int l=strlen(concat);
    int z[l];
    getZarr(concat,z);
    int i;
    int patternfound=0;
    for (i=0;i<l;++i) {
        if (z[i] == patternLength){
		printf("Pattern found at index: %d\n", i-patternLength-1);
           patternfound=1; 
       }
    }
     if(patternfound==0) {
        printf("Pattern Not Found\n");
    }
}

int main() 
{
    char filename[MAX_LENGTH],pattern[MAX_LENGTH],text[MAX_LENGTH];
    FILE *file;

    printf("Enter the filename: ");
    fgets(filename,sizeof(filename),stdin);
    filename[strcspn(filename,"\n")]='\0'; // Remove trailing newline

    file=fopen(filename,"r"); // Open the file in read mode
    if(file==NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the pattern: ");
    
    fgets(pattern,sizeof(pattern),stdin);
    if(sizeof(pattern)==NULL){
    	printf("Empty Pattern");
	}
    pattern[strcspn(pattern,"\n")]='\0'; // Remove trailing newline

    // Read the text from the file
    if (fgets(text,sizeof(text),file)==NULL) 
    {
        printf("Error reading from file.\n");
        fclose(file);
        return 1;
    }

    search(text,pattern);
    fclose(file);
    return 0;
}
