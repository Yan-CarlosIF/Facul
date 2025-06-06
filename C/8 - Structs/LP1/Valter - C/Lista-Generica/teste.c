#include "./estruturas/lista-generica.c"

typedef struct Person {
  char name[50];
  int age;
  char occupation[50];
} Person;

void deleteEnter(char* str) { str[strcspn(str, "\n")] = '\0'; }

Person* personInput() {
  Person* person = (Person*)malloc(sizeof(Person));

  printf("Insira o nome da pessoa: ");
  fgets(person->name, 50, stdin);
  deleteEnter(person->name);

  printf("Insira a idade da pessoa: ");
  scanf("%d", &person->age);

  getchar();

  printf("Insira a profissao da pessoa: ");
  fgets(person->occupation, 50, stdin);
  deleteEnter(person->occupation);

  return person;
}

Person* buildPerson(char* name, int age, char* occupation) {
  Person* person = (Person*)malloc(sizeof(Person));

  strcpy(person->name, name);
  person->age = age;
  strcpy(person->occupation, occupation);

  return person;
}

int verifyPerson(void* person1, void* person2) {
  Person* obj1 = (Person*)person1;
  Person* obj2 = (Person*)person2;

  return obj1->age > obj2->age;
}

void printPerson(void* person) {
  Person* personParse = (Person*)person;

  printf("\nNome: %s", personParse->name);
  printf("\nIdade: %d", personParse->age);
  printf("\nProfissao: %s\n\n", personParse->occupation);
}

int findPersonPerName(void* obj1, void* name) {
  Person* person = (Person*)obj1;
  char* nameParse = (char*)name;

  return strcmp(nameParse, person->name) == 0 ? 1 : 0;
};

int filterPerAge(void* person) {
  Person* personParse = (Person*)person;

  return personParse->age > 18 ? 1 : 0;
}

char* writePersonInFile(void* person) {
  Person* personParse = (Person*)person;

  char age[3];

  sprintf(age, "%d", personParse->age);

  char* line = (char*)malloc(sizeof(char) * 104);

  sprintf(line, "%s,%s,%s\n", personParse->name, age, personParse->occupation);

  return line;
}

int main() {
  Node* list = initList();

  Person* person1 = buildPerson("Yan Carlos", 20, "Programador");
  Person* person2 = buildPerson("Luiz Dbx", 21, "MotoBoy");
  Person* person3 = buildPerson("Ermerson", 21, "Vagabundo");
  Person* person4 = buildPerson("Duda Amiga de Ermerson", 16, "Estudante");

  list = listInsert(list, (void*)person1, verifyPerson);
  list = listInsert(list, (void*)person2, verifyPerson);
  list = listInsert(list, (void*)person3, verifyPerson);
  list = listInsert(list, (void*)person4, verifyPerson);

  list = listRemove(list, (void*)"Luiz Dbx", findPersonPerName);

  listPrint(list, printPerson);

  void* person = listSearch(list, (void*)"Yan Carlos", findPersonPerName);

  if (person != NULL) printPerson(person);

  listMap(list, printPerson, filterPerAge);

  int itSaved = listFileSave(list, "./pessoas.csv", writePersonInFile);

  if (itSaved) printf("Arquivo salvo com sucesso!");

  freeList(list);

  return 0;
}