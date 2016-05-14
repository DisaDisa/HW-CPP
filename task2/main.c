#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
	int id;
	char *number;
	char *name;
} contact;

char *filename;

char *read_string(FILE *in) {
	char c;
	int sz = 1;
	char *ans;
	ans = (char *) malloc(sizeof(char));
	do {
		c = fgetc(in);
	}while(c == EOF || c == ' ' || c == '\n' || c == '\0');
	while (c != EOF && c != ' ' && c != '\n' && c != '\0') {
		ans = (char *) realloc(ans, (++sz) * sizeof(char));
		ans[sz - 2] = c;
		c = fgetc(in);
	}
	return ans;
}	


void read_contact(FILE *in, contact *now) {
	fscanf(in, "%d", &(now->id));
	char *name = read_string(in);
	char *number = read_string(in);
	now->name = (char *) malloc(strlen(name) + 1);
	now->number = (char *) malloc(strlen(number) + 1);
	strcpy(now->name, name);
	strcpy(now->number, number);
	free(name);
	free(number);
}	

void print_contact(contact *a) {
	printf("%d %s %s\n", a->id, a->name, a->number);
	fflush(stdout);
}	

bool substring(char *str, char *substr) {
	if(strlen(substr) == 0) return true;
	for(int i = 0; i < strlen(str); i++) {
		int j = 0;
		while(i + j < strlen(str) && tolower(str[i + j]) == tolower(substr[j])) {
			j++;
			if(j == strlen(substr)) return true;
		}
	}
	return false;
}	

char *normal_number(char *s) {
	char *ans;
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			ans = (char *) realloc(ans, (strlen(ans) + 1) * sizeof(char));
			ans[strlen(ans) - 1] = s[i];
		}
    }
    return ans;
}

void find(char *str) {
	FILE *f;
	f = fopen(filename, "r");
	while(!feof(f)) {
		contact *now;
		read_contact(f, now);
		if(substring(now->name, str) ||
		 substring(normal_number(now->number), normal_number(str)))
			print_contact(now);
		free(now);
	}
	fclose(f);
}	


void create() {
	contact *new_con = (contact *) malloc(sizeof(contact));
	char *name = read_string(stdin);
	char *number = read_string(stdin);
	new_con->name = (char *) malloc(strlen(name) + 1);
	new_con->number = (char *) malloc(strlen(number) + 1);
	strcpy(new_con->name, name);
	strcpy(new_con->number, number);
	free(name);
	free(number);
	FILE *f;
	int id = 0;
	f = fopen(filename, "r");
	while(!feof(f)) {
		contact now;
		read_contact(f, &now);
		if(id < now.id)
			id = now.id;
	}
	fclose(f);
	f = fopen(filename, "a");
	printf("%d %s %s\n", id + 1, new_con->name, new_con->number);
	fclose(f);
	free(new_con->name);
	free(new_con->number);
	free(new_con);
}	

int count() {
	FILE *f;
	int ans = 0;
	f = fopen(filename, "r");
	while(!feof(f)) {
		contact *now;
		read_contact(f, now);
		free(now);
		ans++;
	}
	fclose(f);
	return ans;
}


void delete(int id) {
	int cnt = count();
	FILE *f;
	f = fopen(filename, "r");
	contact **contacts = (contact **) malloc(cnt * sizeof(contact *));
	for(int i = 0; i < cnt; i++) {
		contacts[i] = (contact *) malloc(sizeof(contact));
		read_contact(f, contacts[i]);
	}
	fclose(f);
	f = fopen(filename, "w");
	for(int i = 0; i < cnt; i++) {
		if(contacts[i]->id == id) continue;
		print_contact(contacts[i]);
		free(contacts[i]->name);
		free(contacts[i]->number);
		free(contacts[i]);
	}
	free(contacts);
	fclose(f);
}	


void change_number(int id, char *number) {
	int cnt = count();
	FILE *f;
	f = fopen(filename, "r");
	contact **contacts = (contact **) malloc(cnt * sizeof(contact *));
	for(int i = 0; i < cnt; i++) {
		contacts[i] = (contact *) malloc(sizeof(contact));
		read_contact(f, contacts[i]);
	}
	fclose(f);
	f = fopen(filename, "w");
	for(int i = 0; i < cnt; i++) {
		if(contacts[i]->id == id) {
			contacts[i]->number = (char *) realloc(contacts[i]->number, strlen(number) + 1);
			strcpy(contacts[i]->number, number);
		}	
		print_contact(contacts[i]);
		free(contacts[i]->name);
		free(contacts[i]->number);
		free(contacts[i]);
	}
	free(contacts);
	fclose(f);
}

void change_name(int id, char *name) {
	int cnt = count();
	FILE *f;
	f = fopen(filename, "r");
	contact **contacts = (contact **) malloc(cnt * sizeof(contact *));
	for(int i = 0; i < cnt; i++) {
		contacts[i] = (contact *) malloc(sizeof(contact));
		read_contact(f, contacts[i]);
	}
	fclose(f);
	f = fopen(filename, "w");
	for(int i = 0; i < cnt; i++) {
		if(contacts[i]->id == id) {
			contacts[i]->name = (char *) realloc(contacts[i]->name, strlen(name) + 1);
			strcpy(contacts[i]->name, name);
		}	
		print_contact(contacts[i]);
		free(contacts[i]->name);
		free(contacts[i]->number);
		free(contacts[i]);
	}
	free(contacts);
	fclose(f);
}


int main(int argc, char *argv[]) {
	filename = argv[1];
	while(0 == 0) {
		char *now = read_string(stdin);
		if(!strcmp(now, "find")) {
			char *need = read_string(stdin);
			find(need);
			free(need);
		}
		if(!strcmp(now, "create")) {
			create();
		}
		if(!strcmp(now, "delete")) {
			int id;
			scanf("%d", id);
			delete(id);
		}
		if(!strcmp(now, "change")) {
			int id;
			scanf("%d", id);
			char *s = read_string(stdin);
			if(!strcmp(s, "number")) {
				change_number(id, read_string(stdin));
			}
			if(!strcmp(s, "name")) {
				change_name(id, read_string(stdin));
			}	
			free(s);
		}
		if(!strcmp(now, "exit")) {
		    free(now);
			break;
		}
		free(now);
	}
	return 0;
}

	