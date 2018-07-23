#include "vector.h"
#include <stdlib.h>


vector_t * createVector(int initialSize)
{
     vector_t * vector = malloc(sizeof(vector_t));
     vector->array = (int *)malloc(initialSize*sizeof(int*));
     vector->maxSize = initialSize;
     vector->size = 0;

 return vector;
}

void destroyVector(vector_t * vector)
{
free(vector->array);
free(vector);
}

void resize(vector_t * vector)
{
 
vector->array = (int *)realloc(vector->array,(vector->maxSize*2)*sizeof(int*));
vector->maxSize = ((vector->maxSize) * 2 );
}

void push_back(vector_t * vector, int element)
{
int i;
int value = element;
int counter;
for(i = 0; i < vector->size; i++)
   {
     if(vector->size == vector->maxSize)
       {
        vector->array = (int *)realloc(vector->array, (vector->maxSize*2)*sizeof(int*));
        vector->array[i] = value;
        counter++;
        vector->size = counter;
        vector->maxSize = (vector->maxSize * 2);
       }
     else
       {
         vector->array[i] = value;
         counter++;
         vector->size = counter;
       }
    }
}

int pop_back(vector_t * vector)
{
 int i;
 if(vector->size == 0)
 {
  return 0;
 }
 for(i = 0; (vector + i)->array != '\0'; i++)
 {

 }
 vector->size -= 1;
 return vector->array[--i];

}

int access(vector_t * vector, int index)
{
 if((index > vector->maxSize) || (index < 0))
   {
    return 0;
   }
 else
   {
    return vector->array[index];
   }
}
