#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0

#define PERSON_FILE "person.txt"
#define EMAIL_FILE "email.txt"
#define TELEPHONE_FILE "telephone.txt"

typedef struct email
{
  int id;
  int personId;
  char email[255];
} Email;

typedef struct tel
{
  int id;
  int personId;
  char telephone[12];
} Telephone;

typedef struct person
{
  int id;
  char name[55];
} Person;

typedef struct data
{
  Person *people;
  Email *emails;
  Telephone *telephones;
  int peopleLength;
  int emailLength;
  int telephoneLength;
  int lastPersonId;
  int lastTelephoneId;
  int lastEmailId;
} PersonData;

// persistance
void writeToFile(PersonData *_data);
PersonData loadFromFile();

// handling data functions
void printAll(PersonData *_data);
void printPerson(PersonData *_data, int _id);
// create
void addPerson(PersonData *_data, char *_name);
void addTelephone(PersonData *_data, Telephone *_telephone);
void addEmail(PersonData *_data, Email *_email);
// edit
void editPerson(PersonData *_data, Person *_person);
void editTelephone(PersonData *_data, Telephone *_telephone);
void editEmail(PersonData *_data, Email *_email);
// remove
void removePerson(PersonData *_data, int _id);
void removeTelephone(PersonData *_data, int _id);
void removeEmail(PersonData *_data, int _id);

#endif
