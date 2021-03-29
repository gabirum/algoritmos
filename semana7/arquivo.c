#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_PATH "pessoas.txt"

typedef struct p
{
  int id;
  char name[55];
  char telephone[12];
  char email[255];
  char dateOfBirth[11];
  char gender[10];
} Person;

void printMenu();

void addPerson(Person **people, Person *person);
Person *findPersonById(size_t id, Person *people);
void editPerson(Person *people, Person *person);
void removePerson(size_t id, Person **people);

void loadFromFile(Person **people);
void writeToFile(Person *people);

int isValid(Person *person);
void copyTo(Person *destination, Person *source);

size_t lastId = 0;
size_t counter = 0;

int main(int argc, char const *argv[])
{
  Person *people = malloc(sizeof(Person));

  loadFromFile(&people);

  int response = 0;

  do
  {
    printMenu();
    scanf("%d", &response);

    switch (response)
    {
    case 1:
    {
      Person person;
      memset(&person, 0, sizeof(Person));

      printf("Digite o nome:\n");
      scanf("%s", person.name);
      printf("Digite o telefone:\n");
      scanf("%s", person.telephone);
      printf("Digite o email:\n");
      scanf("%s", person.email);
      printf("Digite a data de nascimento:\n");
      scanf("%s", person.dateOfBirth);
      printf("Digite o genero:\n");
      scanf("%s", person.gender);

      addPerson(&people, &person);
      break;
    }

    case 2:
    {
      Person person;
      memset(&person, 0, sizeof(Person));

      printf("Digite o id:\n");
      scanf("%d", &person.id);
      printf("Digite o nome:\n");
      scanf("%s", person.name);
      printf("Digite o telefone:\n");
      scanf("%s", person.telephone);
      printf("Digite o email:\n");
      scanf("%s", person.email);
      printf("Digite a data de nascimento:\n");
      scanf("%s", person.dateOfBirth);
      printf("Digite o genero:\n");
      scanf("%s", person.gender);

      editPerson(people, &person);
      break;
    }

    case 3:
    {
      int id = 0;
      printf("Digite o id\n");
      scanf("%d", &id);

      Person *p = findPersonById(id, people);

      if (p == NULL)
      {
        printf("Não existe pessoa com esse id\n");
        break;
      }

      printf("id: %d\n", p->id);
      printf("nome: %s\n", p->name);
      printf("telefone: %s\n", p->telephone);
      printf("email: %s\n", p->email);
      printf("data de nascimento: %s\n", p->dateOfBirth);
      printf("gênero: %s\n", p->gender);

      break;
    }

    case 4:
    {
      int id = 0;
      printf("Digite o id\n");
      scanf("%d", &id);

      removePerson(id, &people);
    }

    default:
      break;
    }
  } while (response != 5);

  writeToFile(people);

  return 0;
}

void printMenu()
{
  printf("1 - Adicionar\n");
  printf("2 - Editar\n");
  printf("3 - Ver\n");
  printf("4 - Excluir\n");
  printf("5 - Sair\n");
}

void addPerson(Person **people, Person *person)
{
  *people = realloc(*people, sizeof(Person) * (counter + 1));
  memset(&((*people)[counter]), 0, sizeof(Person));

  (*people)[counter].id = ++lastId;
  copyTo(&((*people)[counter]), person);

  counter++;
}

Person *findPersonById(size_t id, Person *people)
{
  for (size_t i = 0; i < counter; i++)
  {
    if (people[i].id == id)
    {
      return &people[i];
    }
  }

  return NULL;
}

void editPerson(Person *people, Person *person)
{
  Person *toEdit = findPersonById(person->id, people);

  if (toEdit == NULL)
  {
    printf("Não existe pessoa com este id\n");
  }
  else
  {
    copyTo(toEdit, person);
  }
}

void removePerson(size_t id, Person **people)
{
  for (size_t i = 0; i < counter; i++)
  {
    if (id == (*people)[i].id)
    {
      for (size_t j = i + 1; j < counter; j++)
        (*people)[j - 1] = (*people)[j];

      counter--;
      *people = realloc(*people, sizeof(Person) * counter);

      return;
    }
  }

  printf("Não existe pessoa com esse id\n");
}

void loadFromFile(Person **people)
{
  FILE *file = fopen(FILE_PATH, "r");

  if (file != NULL)
  {
    Person person;

    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &person.id, person.name, person.telephone, person.email, person.dateOfBirth, person.gender) != EOF)
    {
      lastId = person.id;
      (*people)[counter] = person;

      counter++;

      if (!feof(file))
      {
        *people = realloc(*people, sizeof(Person) * (counter + 1));
        memset(&person, 0, sizeof(Person));
      }
    }

    fclose(file);
  }
}

void writeToFile(Person *people)
{
  FILE *file = fopen(FILE_PATH, "w");

  if (file == NULL)
  {
    printf("Ocorreu um erro ao escrever no arquivo\n");
    exit(1);
  }

  for (size_t i = 0; i < counter; i++)
  {
    fprintf(file, "%d;%s;%s;%s;%s;%s\n", people[i].id, people[i].name, people[i].telephone, people[i].email, people[i].dateOfBirth, people[i].gender);
  }

  fclose(file);
}

void copyTo(Person *destination, Person *source)
{
  strcpy(destination->name, source->name);
  strcpy(destination->email, source->email);
  strcpy(destination->telephone, source->telephone);
  strcpy(destination->dateOfBirth, source->dateOfBirth);
  strcpy(destination->gender, source->gender);
}

int isValid(Person *person)
{
  int nameLen = strlen(person->name);
  int telLen = strlen(person->telephone);
  int mailLen = strlen(person->email);
  int isValidGender = strcmp(person->gender, "masculino") || strcmp(person->gender, "feminino");

  return nameLen > 2 && telLen >= 10 && telLen <= 11 && mailLen > 10 && isValidGender;
}
