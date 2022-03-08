#include <stdio.h>
#include <stdlib.h>
#define less(a, b) (a < b)
#define exch(a, b) {job temp = a; a = b; b = temp;}

typedef struct job {
  char label[2];
  int initialTime;
  int finishTime;
}job;

int solutionSize = 1;

void merge(job *v, int l, int r1, int r2)
{
  job *v2 = (job *) malloc(sizeof(job)*(r2-l+1));
  int k = 0, i = l, j = r1+1;

  while(i <= r1 && j <= r2)
  {
    if (less(v[i].finishTime, v[j].finishTime))
      v2[k++] = v[i++];
    else
      v2[k++] = v[j++];
  }

  while(i <= r1)
    v2[k++] = v[i++];

  while(j <= r2)
    v2[k++] = v[j++];

  k = 0;

  for (i = l; i <= r2; i++)
    v[i] = v2[k++];

  free(v2);
}

void mergeSort(job *v, int l, int r)
{
  if (l >= r) return;
  int middle = (r+l)/2;

  mergeSort(v, l, middle);
  mergeSort(v, middle+1, r);
  merge(v, l, middle, r);
}

job* intervalScheduling(job *jobs, int tasksQtt) {
  job *solution = (job *) malloc(sizeof(job)*tasksQtt);

  //Initial conditions
  solution[0] = jobs[0];

  for (int j = 1; j < tasksQtt; j++) {
    if (jobs[j].initialTime >= solution[solutionSize-1].finishTime) {
      solution[solutionSize] = jobs[j];
      solutionSize++;
    }
  }
  return solution;
}

void printScheduling(job *solution, int size) {
  for (int j = 0; j < size; j++) {
    printf("Task %s: starts at %d, finishes at %d\n", solution[j].label, solution[j].initialTime, solution[j].finishTime);
  }
}

int main(void) {
  int tasks = -1;
  job *jobs;

  while(tasks) {
    printf("Digite o número de tarefas ou 0 para sair:\n>");
    scanf("%d", &tasks);

    jobs = (job*) malloc(sizeof(job)*10);
    for (int i = 0; i < tasks; i++) {
      printf("(Tarefa %d) Digite o nome e os tempos de início e fim:\n>", i+1);
      scanf("%s %d %d", &jobs[i].label, &jobs[i].initialTime, &jobs[i].finishTime);

    }
    mergeSort(jobs, 0, tasks-1);
    job *solution = intervalScheduling(jobs, tasks);
    printScheduling(solution, solutionSize);
    free(solution);
  }

  free(jobs);
  return 0;
}