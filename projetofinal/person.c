#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAll(PersonData *_data)
{
  for (size_t i = 0; i < _data->peopleLength; i++)
  {
    int personId = _data->people[i].id;

    printf("Pessoa %d:\n", _data->people[i].id);
    printf("\tNome: %s\n", _data->people[i].name);
    printf("\tTelefones:\n");

    for (size_t j = 0; j < _data->telephoneLength; j++)
    {
      if (_data->telephones[j].personId == personId)
      {
        printf("\t\tTelefone %d: %s\n", _data->telephones[j].id, _data->telephones[j].telephone);
      }
    }

    printf("\tEmails:\n");

    for (size_t j = 0; j < _data->telephoneLength; j++)
    {
      if (_data->emails[j].personId == personId)
      {
        printf("\t\tEmail %d: %s\n", _data->emails[j].id, _data->emails[j].email);
      }
    }
    printf("\n\n");
  }
}

void printPerson(PersonData *_data, int _id)
{
  for (size_t i = 0; i < _data->peopleLength; i++)
  {
    if (_data->people[i].id == _id)
    {
      printf("Pessoa %d:\n", _data->people[i].id);
      printf("\tNome: %s\n", _data->people[i].name);
      printf("\tTelefones:\n");

      for (size_t j = 0; j < _data->telephoneLength; j++)
      {
        if (_data->telephones[j].personId == _data->people[i].id)
        {
          printf("\t\tTelefone %d: %s\n", _data->telephones[j].id, _data->telephones[j].telephone);
        }
      }

      printf("\tEmails:\n");

      for (size_t j = 0; j < _data->telephoneLength; j++)
      {
        if (_data->emails[j].personId == _data->people[i].id)
        {
          printf("\t\tEmail %d: %s\n", _data->emails[j].id, _data->emails[j].email);
        }
      }

      return;
    }
  }

  printf("Não existe pessoa com esse id\n");
}

void addPerson(PersonData *_data, char *_name)
{
  _data->people = realloc(_data->people, sizeof(Person) * (_data->peopleLength + 1));
  _data->people[_data->peopleLength].id = ++_data->lastPersonId;

  strcpy(_data->people[_data->peopleLength].name, _name);

  _data->peopleLength++;
}

int personExists(PersonData *_data, int _id)
{
  for (size_t i = 0; i < _data->peopleLength; i++)
    if (_data->people[i].id == _id)
      return TRUE;

  return FALSE;
}

void addTelephone(PersonData *_data, Telephone *_telephone)
{
  if (!personExists(_data, _telephone->personId))
  {
    printf("A pessoa na qual deseja atribuir este telefone não existe\n");
    return;
  }

  _data->telephones = realloc(_data->telephones, sizeof(Telephone) * (_data->telephoneLength + 1));
  _data->telephones[_data->telephoneLength].id = ++_data->lastTelephoneId;

  _data->telephones[_data->telephoneLength].personId = _telephone->personId;
  strcpy(_data->telephones[_data->telephoneLength].telephone, _telephone->telephone);

  _data->telephoneLength++;
}

void addEmail(PersonData *_data, Email *_email)
{
  if (!personExists(_data, _email->personId))
  {
    printf("A pessoa na qual deseja atribuir este email não existe\n");
    return;
  }

  _data->emails = realloc(_data->emails, sizeof(Email) * (_data->emailLength + 1));
  _data->emails[_data->emailLength].id = ++_data->lastEmailId;

  _data->emails[_data->emailLength].personId = _email->personId;
  strcpy(_data->emails[_data->emailLength].email, _email->email);

  _data->emailLength++;
}

void editPerson(PersonData *_data, Person *_person)
{
  for (size_t i = 0; i < _data->peopleLength; i++)
  {
    if (_data->people[i].id == _person->id)
    {
      if (strlen(_person->name) > 0)
      {
        strcpy(_data->people[i].name, _person->name);
      }

      return;
    }
  }

  printf("Não existe pessoa com este id\n");
}

void editTelephone(PersonData *_data, Telephone *_telephone)
{
  for (size_t i = 0; i < _data->telephoneLength; i++)
  {
    if (_data->telephones[i].id == _telephone->id)
    {
      if (strlen(_telephone->telephone) > 0)
      {
        strcpy(_data->telephones[i].telephone, _telephone->telephone);
      }

      if (_telephone->personId > 0 && personExists(_data, _telephone->personId))
      {
        _data->telephones[i].personId = _telephone->personId;
      }

      return;
    }
  }

  printf("Não existe telefone com este id\n");
}

void editEmail(PersonData *_data, Email *_email)
{
  for (size_t i = 0; i < _data->emailLength; i++)
  {
    if (_data->emails[i].id == _email->id)
    {
      if (strlen(_email->email) > 0)
      {
        strcpy(_data->emails[i].email, _email->email);
      }

      if (_email->personId > 0 && personExists(_data, _email->personId))
      {
        _data->emails[i].personId = _email->personId;
      }

      return;
    }
  }

  printf("Não existe email com este id\n");
}

// esse aqui consome pouquissimo recurso
void removePerson(PersonData *_data, int _id)
{
  for (size_t i = 0; i < _data->peopleLength; i++)
  {
    if (_data->people[i].id == _id)
    {
      for (size_t j = i + 1; j < _data->peopleLength; j++)
        _data->people[j - 1] = _data->people[j];

      _data->peopleLength--;
      _data->people = realloc(_data->people, sizeof(Person) * _data->peopleLength);

      for (size_t j = 0; j < _data->telephoneLength; j++)
      {
        if (_data->telephones[j].personId == _id)
        {
          for (size_t k = j + 1; k < _data->telephoneLength; k++)
          {
            _data->telephones[k - 1] = _data->telephones[k];
          }

          _data->telephoneLength--;
          _data->telephones = realloc(_data->telephones, sizeof(Telephone) * _data->telephoneLength);
        }
      }

      for (size_t j = 0; j < _data->emailLength; j++)
      {
        if (_data->emails[j].personId == _id)
        {
          for (size_t k = j + 1; k < _data->emailLength; k++)
          {
            _data->emails[k - 1] = _data->emails[k];
          }

          _data->emailLength--;
          _data->emails = realloc(_data->emails, sizeof(Email) * _data->emailLength);
        }
      }

      return;
    }
  }

  printf("Não existe pessoa com este id\n");
}

// mais otimizado que isso, só dois disso
void removeTelephone(PersonData *_data, int _id)
{
  for (size_t i = 0; i < _data->telephoneLength; i++)
  {
    if (_data->telephones[i].id == _id)
    {
      for (size_t j = i + 1; j < _data->telephoneLength; j++)
        _data->telephones[j - 1] = _data->telephones[j];

      _data->telephoneLength--;
      _data->telephones = realloc(_data->telephones, sizeof(Telephone) * _data->telephoneLength);

      return;
    }
  }

  printf("Não existe telefone com este id\n");
}

// mais otimizado que isso, só dois disso
void removeEmail(PersonData *_data, int _id)
{
  for (size_t i = 0; i < _data->emailLength; i++)
  {
    if (_data->emails[i].id == _id)
    {
      for (size_t j = i + 1; j < _data->emailLength; j++)
        _data->emails[j - 1] = _data->emails[j];

      _data->emailLength--;
      _data->emails = realloc(_data->emails, sizeof(Email) * _data->emailLength);

      return;
    }
  }

  printf("Não existe telefone com este id\n");
}
