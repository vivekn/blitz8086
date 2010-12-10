/* Symbol Table for 8086 Assembler

(C) Vivek Narayanan 2010

*/

#include<stdlib.h>
#include<string.h>

struct symrec
{
	char *name; /* name of symbol */
	int value;
	struct symrec *next; /* link field */
};


typedef struct symrec symrec;
symrec *sym_table = (symrec *)0;

symrec *getsym (char *);

symrec * putsym ( char *sym_name )
{
	symrec *ptr;
	ptr = (symrec *) malloc (sizeof(symrec));
	ptr->name = (char *) malloc (strlen(sym_name)+1);
	strcpy (ptr->name,sym_name);

	ptr->next = (struct symrec *)sym_table;
	sym_table = ptr;
	return ptr;
}


symrec * iputsym ( char *sym_name,int ival )
{
	symrec *ptr;
	ptr = (symrec *) malloc (sizeof(symrec));
	ptr->name = (char *) malloc (strlen(sym_name)+1);
	strcpy (ptr->name,sym_name);
	ptr->value = ival;
	ptr->next = (struct symrec *)sym_table;
	sym_table = ptr;
	return ptr;
}


symrec * getsym ( char *sym_name )
{
	symrec *ptr;
	for (ptr = sym_table; ptr != (symrec *) 0;
		ptr = (symrec *)ptr->next)
	if (strcmp (ptr->name,sym_name) == 0)
		return ptr;
	return 0;
}

