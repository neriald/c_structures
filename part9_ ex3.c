#include <stdio.h>

typedef struct participant
{
    char name[20];
    int task1;
    int task2;
    int task3;
    int sum;
}part;

void addParticipant(part *x)
{
    printf("name= ");
    scanf("%s", x->name);
    printf("points of task1= ");
    scanf("%d", &x->task1);
    printf("points of task2= ");
    scanf("%d", &x->task2);
    printf("points of task3= ");
    scanf("%d", &x->task3);
    x->sum = x->task1 + x->task2 + x->task3;
}

void participantPrint(part x)
{
    printf("%s task1=%d task2=%d task3=%d sum=%d\n", x.name, x.task1, x.task2, x.task3, x.sum);
}


int main()
{
    printf("How many participants do we have?: ");
    int n;
    scanf("%d", &n);
    if (n<1)
    {
        printf("whops what did you do nvm bye bye...");
        return 1;
    }
    part A[n];
    printf("Tell us about participants\n");
    int i;
    for(i=0; i<n; ++i)
    {
        addParticipant(&A[i]);
    }
    for(i=0; i<n; ++i)
    {
        participantPrint(A[i]);
    }
    float average=0;
    for(i=0; i<n; ++i)
    {
        average = average + A[i].sum;
    }
    average = average / i;
    printf("average sum = %f\n", average);
    printf("\nParticipants who proceeded to next stage:\n");
    for (i=0; i<n; ++i)
    {
        if(A[i].sum>=average)
            participantPrint(A[i]);
    }

    return 0;
}
