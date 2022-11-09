#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

struct registerElemt { 
char namex[100];
char info[100];

};

typedef struct registerElemt regis;

struct nodo { 
regis reg;
struct nodo *a, *s; 
};

typedef struct nodo nodo;

nodo *tabla[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL}; 
char read_chart(void);
void add_register(void);
void search_register(void);

int main(int argc, char **args){ 
	char option; 
	do{ 
		printf("a- Add register :D\n");
		printf("b- Search register O.o\n");
		printf("d- Exit :c\n"); 
		printf("Option :)\n"); 
		option = read_chart();
		
		switch (option) {
			case 'a': 
				add_register(); 
				break; 
			case 'b':
				search_register();
				break;
			case 's':
				break; 
			default: break; 
		}
	}while (option != 's');
	return 0; 
}

int hashFunction(char *); 

void order(regis r, int key);

void add_register(void){ 
	regis r;
	int key = hashFunction(r.namex);
	
	printf("Give me the name: ");
	fgets(r.namex, 100, stdin);
	
	printf("Give me the info: ");
	fgets(r.info, 100, stdin);
	
	printf("Key: %d: %s", key, r.namex);
	order(r, key);
}

nodo *search(char *name, int key);
void show_register(regis r); 

void search_register(void){ 
	char name[100]; 
	int key = hashFunction(name);
	
	printf("Give me the name: ");
	fgets(name, 100, stdin);
		
	printf("key %d: %s:", key, name);
	
	nodo *result = search(name, key);
	
	if(result){ 
		show_register(result-> reg); 
	}else{
		printf("Doesn't exist the element"); 
	}
}

void order(regis r, int key){
	nodo *newN = malloc(sizeof(nodo)); 
	newN ->reg = r;
	newN ->a = NULL; 
	newN ->s = tabla[key]; 
	tabla[key] = newN; 
} 

nodo *search(char *name, int key){

	nodo *p = tabla[key]; 
	while (p) { 
		if(strcmp(p->reg.namex, name)==0){ 
		return p; }
		p= p-> s; 
	}
	return NULL; 

}

void show_register(regis r){
	printf("Person name: %s",r.namex); 
	printf(" \n"); 
	printf("Information: %s", r.info);

}

int hashFunction(char *key){ 
	int longit = strlen(key) - 1;
	int sum = 0; 
	
	for(int i=0; i<longit; i++) 
		sum += key[i];
	
	return sum % 7; 
}

char read_chart(void){
	char c = getchar();
	getchar();
	return c;
}
