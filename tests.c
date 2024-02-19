#include "rsa.h"

unsigned char cipher_key128_ex[16] = {0x2B,0x7E,0x15,0x16,0x28,0xAE,0xD2,0xA6,0xAB,0xF7,0x15,0x88,0x09,0xCF,0x4F,0x3C};





int* str_to_int(char* string, int len){
	int* tab = malloc(sizeof(int)*len);
	for (int i = 0; i<len; i++)
		tab[i] = (int)string[i];
	return tab;
}

void print_tab(int* tab, int len){
	for (int i = 0; i<len; i++)
		printf("%d ",tab[i]);
	printf("\n");
}


char * int_to_str(int* tab, int len){
	char* string = malloc(sizeof(char)*len);
	for (int i = 0; i<len; i++)
		string[i] = (char)tab[i];
	return string;
}



int main( int argc, char* argv[]){
	
	int p = atoi(argv[1]); //6599
	int q = atoi(argv[2]); //6143
	int n = p*q;
	int phi_n = (q-1)*(p-1);

	int _e = e(phi_n);
	//int _e = 257;
	int _d = d(_e,phi_n);
	int m = atoi(argv[3]);
	int mc;
	int md;
 

	printf("p = %d\n", p);
	printf("q = %d\n", q);
	printf("n = p*q = %d\n", n);
	printf("phi_n = (p-1)*(q-1) = %d\n", phi_n);
	
	printf("e = %d, avec PGCD(e, phi_n) = 1 \n", _e);
	printf("d = %d, avec d*e = 1 mod phi_n\n", _d);
	//printf("size_bloc = %d\n", size_bloc(n));

	mc = rsa_cipher_bloc(m, _e, n);
	md = rsa_decipher_bloc(mc,_d,n);

	printf("m = %d\n", m);
	printf("mc = m^e mod n = %d\n", mc);
	printf("m = mc^d mod n =%d\n", m);
	/*
	int _e = e(phi_n);
	//int _e = 257;
	int _d = d(_e,phi_n);
	int m =101;



	printf("phi_n = %d\n", phi_n);
	printf("n = %d\n", n);
	printf("e = %d\n", _e);
	printf("d = %d\n", _d);
	printf("size_bloc = %d\n", size_bloc(n));
	printf("m = %d\n", m);
	m = rsa_cipher_bloc(m, _e, n);
	printf("mc = %d\n", m);
	m = rsa_decipher_bloc(m,_d,n);
	printf("m = %d\n", m);
    
    
	printf("cle publique : (%d, %d)\n", n, _e);
	printf("cle privee : (%d, %d)\n", n, _d);
	
	char str[14] = "Texte en clair";
	printf("str : %s\n", str);
	int * message = str_to_int(str, 14);
	print_tab(message, 14);
	
	rsa_c(message, 14, _e, n);
	print_tab(message, 14);
	strcpy(str, int_to_str(message, 14));
	printf("str chiff : %s\n", str);
	
	rsa_c_d(message, 14, _d, n);
	print_tab(message, 14);
	strcpy(str, int_to_str(message, 14));
	printf("str chiff : %s\n", str);

	*/
	
	
	


	
	
	


    return 0;

}

