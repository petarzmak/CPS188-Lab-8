#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure that contains variables for each part of the IP address
typedef struct
address_t{
	
	int one;
	int two;
	int three;
	int four;
	char name[15];
	
}address;

//Checks to see if two addresses are on the same network
int
localnet(address addr1, address addr2){
	
	int i;
	if (addr1.one == addr2.one && addr1.two == addr2.two && strcmp(addr1.name, addr2.name) != 0)
		i = 1;
	else
		i = 0;
	
	return (i);
}

int
main(void)
{
	int i, j, l, k, t;
	int  array_size;
	char same_net[15][15];
	
	//Reads all addresses and names from the File
	FILE *in;
	
	in = fopen("L8_ip.txt", "r");
	
	address ad[300];
	
	i = 0;
	while(!feof(in)){
			
		fscanf(in, "%d%*c", &ad[i].one); // <- note usage of "*c" to skip the "." in the file
		fscanf(in, "%d%*c", &ad[i].two);
		fscanf(in, "%d%*c", &ad[i].three);
		fscanf(in, "%d%*c", &ad[i].four);
		fscanf(in, "%s", ad[i].name);
			
		//Defines the array size as one less than the location of the sentinel	
		if(ad[i].one == 0 && ad[i].two == 0 && ad[i].three == 0 && ad[i].four == 0 && strcmp(ad[i].name, "sentinel") == 0)
			array_size = i;
			
		i++;
	}
	fclose(in);
		
	int local[array_size];
	
	//Passes each address one at a time into function "localnet"
	//Recrods the addresses where the ip's are the same
	for(i = 0; i < array_size; i++){
		for (j = 0; j < array_size; j++){
			t = localnet(ad[i], ad[j]);
			if (t == 1){
				local[l] = j;
				l++;
			}
		}
	}
	
	//Copys the names of the computers depending on which address they are located at
	for (k = 0; k < (array_size/2); k++) // <- Note: loop stops at array_size/2 since each result is repeated twice (always an even number of parings)
		strcpy(same_net[k], ad[local[k]].name);
		
	//Prints which names are the on the same net
	for (i = 0; i < (array_size/2); i++)
		printf("Servers %s and %s are on the same local network\n", ad[i].name, same_net[i]);
	
	//Prints all ip's and names
	for (i = 0; i < array_size; i++)
		printf("\n%d.%d.%d.%d %s", ad[i].one, ad[i].two, ad[i].three, ad[i].four, ad[i].name);
	
	return 0;
}

