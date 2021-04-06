#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PersonData loadFromFile()
{
  FILE *personFile = fopen(PERSON_FILE, "r");
  FILE *telephoneFile = fopen(TELEPHONE_FILE, "r");
  FILE *emailFile = fopen(EMAIL_FILE, "r");

  PersonData personData;

  personData.peopleLength = 0;
  personData.emailLength = 0;
  personData.telephoneLength = 0;
  personData.lastPersonId = 0;
  personData.lastTelephoneId = 0;
  personData.lastEmailId = 0;
  personData.people = malloc(sizeof(Person));
  personData.emails = malloc(sizeof(Email));
  personData.telephones = malloc(sizeof(Telephone));

  if (personFile == NULL || telephoneFile == NULL || emailFile == NULL)
  {
    printf("O arquivo não existe, ele será criado no final da execução do programa\n\n");
  }
  else
  {
    Person person;
    memset(&person, 0, sizeof(Person));

    while (fscanf(personFile, "%d;%[^\n]\n", &person.id, person.name) != EOF)
    {
      personData.lastPersonId = person.id;
      personData.people[personData.peopleLength] = person;

      personData.peopleLength++;

      if (!feof(personFile))
      {
        personData.people = realloc(personData.people, sizeof(Person) * (personData.peopleLength + 1));
        memset(&person, 0, sizeof(Person));
      }
    }

    Telephone tel;

    while (fscanf(telephoneFile, "%d;%d;%[^\n]\n", &tel.id, &tel.personId, tel.telephone) != EOF)
    {
      personData.lastTelephoneId = tel.id;
      personData.telephones[personData.telephoneLength] = tel;

      personData.telephoneLength++;

      if (!feof(telephoneFile))
      {
        personData.telephones = realloc(personData.telephones, sizeof(Telephone) * (personData.telephoneLength + 1));
        memset(&tel, 0, sizeof(Telephone));
      }
    }

    Email email;

    while (fscanf(emailFile, "%d;%d;%[^\n]\n", &email.id, &email.personId, email.email) != EOF)
    {
      personData.lastEmailId = email.id;
      personData.emails[personData.emailLength] = email;

      personData.emailLength++;

      if (!feof(emailFile))
      {
        personData.emails = realloc(personData.emails, sizeof(Email) * (personData.emailLength + 1));
        memset(&email, 0, sizeof(Email));
      }
    }

    fclose(personFile);
    fclose(telephoneFile);
    fclose(emailFile);
  }

  return personData;
}

void writeToFile(PersonData *_data)
{
  FILE *personFile = fopen(PERSON_FILE, "w");
  FILE *telephoneFile = fopen(TELEPHONE_FILE, "w");
  FILE *emailFile = fopen(EMAIL_FILE, "w");

  if (personFile == NULL || telephoneFile == NULL || emailFile == NULL)
  {
    printf("Ocorreu um erro ao escrever nos arquivos\n");
    exit(1);
  }

  for (size_t i = 0; i < _data->peopleLength; i++)
  {
    fprintf(personFile, "%d;%s\n", _data->people[i].id, _data->people[i].name);
  }

  for (size_t i = 0; i < _data->telephoneLength; i++)
  {
    fprintf(telephoneFile, "%d;%d;%s\n", _data->telephones[i].id, _data->telephones[i].personId, _data->telephones[i].telephone);
  }

  for (size_t i = 0; i < _data->emailLength; i++)
  {
    fprintf(emailFile, "%d;%d;%s\n", _data->emails[i].id, _data->emails[i].personId, _data->emails[i].email);
  }

  fclose(personFile);
  fclose(telephoneFile);
  fclose(emailFile);
}
