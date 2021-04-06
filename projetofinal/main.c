#include <stdio.h>
#include "file.c"
#include "person.c"

void printMenu();

int main(int argc, char const *argv[])
{
  PersonData data = loadFromFile();

  int response;

  do
  {
    printMenu();
    scanf("%d", &response);

    switch (response)
    {
    case 1:
    {
      printAll(&data);
      break;
    }

    case 2:
    {
      int id;
      printf("Digite o id da pessoa:\n");
      scanf("%d", &id);

      printPerson(&data, id);

      break;
    }

    case 3:
    {
      char name[55];
      printf("Digite o nome da pessoa:\n");
      scanf("%*c");
      scanf("%[^\n]", name);

      addPerson(&data, name);
      break;
    }

    case 4:
    {
      Telephone tel;

      printf("Digite o id da pessoa a qual deseja atribuir este telefone:\n");
      scanf("%d", &tel.personId);
      printf("Digite o telefone:\n");
      scanf("%*c");
      scanf("%[^\n]", tel.telephone);

      addTelephone(&data, &tel);
      break;
    }

    case 5:
    {
      Email email;

      printf("Digite o id da pessoa a qual deseja atribuir este email:\n");
      scanf("%d", &email.personId);
      printf("Digite o email:\n");
      scanf("%*c");
      scanf("%[^\n]", email.email);

      addEmail(&data, &email);
      break;
    }

    case 6:
    {
      Person person;

      printf("Digite o id da pessoa a alterar:\n");
      scanf("%d", &person.id);
      printf("Digite o nome da pessoa, deixe vazio caso não queira alterar:\n");
      scanf("%*c");
      scanf("%[^\n]", person.name);

      editPerson(&data, &person);
      break;
    }

    case 7:
    {
      Telephone t;
      printf("Digite o id do telefone que deseja alterar:\n");
      scanf("%d", &t.id);
      printf("Digite o id da pessoa, caso queira atribuir a outra pessoa este telefone, senão digite -1:\n");
      scanf("%d", &t.personId);
      printf("Digite o telefone:\n");
      scanf("%*c");
      scanf("%[^\n]", t.telephone);

      editTelephone(&data, &t);
      break;
    }

    case 8:
    {
      Email e;
      printf("Digite o id do email que deseja alterar:\n");
      scanf("%d", &e.id);
      printf("Digite o id da pessoa, caso queira atribuir a outra pessoa este email, senão digite -1:\n");
      scanf("%d", &e.personId);
      printf("Digite o email:\n");
      scanf("%*c");
      scanf("%[^\n]", e.email);

      editEmail(&data, &e);
      break;
    }

    case 9:
    {
      int id;
      printf("Digite o id da pessoa:\n");
      scanf("%d", &id);

      removePerson(&data, id);

      break;
    }

    case 10:
    {
      int id;
      printf("Digite o id do telefone:\n");
      scanf("%d", &id);

      removeTelephone(&data, id);

      break;
    }

    case 11:
    {
      int id;
      printf("Digite o id do email:\n");
      scanf("%d", &id);

      removeEmail(&data, id);

      break;
    }

    default:
      break;
    }
  } while (response != 0);

  writeToFile(&data);

  return 0;
}

void printMenu()
{
  printf("Ações:\n");
  printf("\t0 - Sair\n");
  printf("\t1 - Ver Tudo\n");
  printf("\t2 - Ver Pessoa\n");
  printf("\t3 - Adicionar Pessoa\n");
  printf("\t4 - Adicionar Telefone\n");
  printf("\t5 - Adicionar Email\n");
  printf("\t6 - Editar Pessoa\n");
  printf("\t7 - Editar Telefone\n");
  printf("\t8 - Editar Email\n");
  printf("\t9 - Excluir Pessoa\n");
  printf("\t10 - Excluir Telefone\n");
  printf("\t11 - Excluir Email\n");
}
