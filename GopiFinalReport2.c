#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
void *MiceEating();
void *CatsEating();
int NumCats,NumBowl,NumMice,total_Cats,total_Bowl,total_Mice;
sem_t MiceEat;
sem_t CatsEat;
void *MiceEating()
{
if(NumMice!=0 && NumBowl!=0)
{
sem_wait(&MiceEat);
NumBowl--;
NumMice--;
printf("\n Mice %d has eating the bowl %d", total_Mice-NumMice,total_Bowl-NumBowl);
sem_post(&MiceEat);
}
}
void *CatsEating()
{
if(NumCats!=0 && NumBowl!=0)
{
sem_wait(&MiceEat);
NumBowl--;
NumCats--;
printf("\n Cat %d has eating the bowl %d", total_Cats-NumCats,total_Bowl-NumBowl);
sem_post(&MiceEat);
}
}
int main()
{
pthread_t th,th1;
printf("\n Enter the number of Cats:");
scanf("%d", &NumCats);
printf("\n Enter the number of Mice:");
scanf("%d", &NumMice);
printf("\n Enter the number of Food in Bowls:");
scanf("%d", &NumBowl);
total_Cats=NumCats;
total_Mice=NumMice;
total_Bowl=NumBowl;
sem_init(&MiceEat,0,1);
sem_init(&CatsEat,0,1);
while((NumBowl!=0) && (NumCats!=0 || NumMice!=0) && (NumCats>=0 && NumMice>=0 && NumBowl>=0))
{
pthread_create(&th,NULL,CatsEating,NULL);
pthread_create(&th1,NULL,MiceEating,NULL);
}
while((NumBowl!=0) && (NumCats!=0 || NumMice!=0))
{
pthread_join(th,NULL);
pthread_join(th1,NULL);
}
}

