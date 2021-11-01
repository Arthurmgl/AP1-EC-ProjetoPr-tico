#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

void Clientes (void);
void Contas (void);
int CadastroClientes (void);
void listarclientes (void);
int Cadastroconta (void);
void listacontas (void);
int acharcliente (void);
void buscarcliente (void);
void buscarconta (void);
int contarfinal (char a[]);
int validacaocliente (char a[]);
int validacaoconta (char a[], char b[]);
void alterarcliente (void);
int acharconta (void);
int saque (int a, int b);
void saqueconclusao (int s, char *c);
int deposito (int a, int b, int c);
void depositoconclusao (int s, char *c);
void buscarc (char c[]);
int acharc (char c[]);
void extratos (void);
void listartransacoes (char d[], char a[]);
void depositotransfer (int s, char *c, char *d, char *n);
void saquetransfer (int s, char *c, char *d, char *n);
void redirecionarsaque(int a, char *b, int c);
void redirecionardeposito(int a, char *b, int c);
int transferencia (void);
void removercliente(void);
void acharremover(char *a);
int acharlimitecliente(void);
int acharlimiteconta(void);
int acharlimitetransacao(void);

struct Cliente {
	char codigo[50];
	char nome[50];
	char cpf[15];
	char telefone[50];
	char endereco[50];	
};

struct Conta {
	char cliente[50];
	char agencia[50];
	char numeroconta[50];
	char saldo[50];
};

struct Transacao {
    char data[20];
    char tipo[20];
    char valor[30];
    char conta[50];
    char descricao[100];
};


int main()
{
	FILE *fp;   
	fp= fopen("trabalhoarthur.dat", "a+"); 
	fclose(fp);
	fp= fopen("trabalhoarthurconta.dat", "a+");
	fclose(fp);
	fp= fopen("trabalhoarthurtransacao.dat", "a+");
	fclose(fp);
	 char primeirocomando;
	 int i=0;
	 while(i<1){
	 
	 
	 printf("=============== Bem vindo! =================\nDigite um comando para prosseguir:\nC - Gerenciar Clientes\nT - Gerenciar Contas\nS - Sair\n");   
     scanf("%s", &primeirocomando);
     
     if(strcmp(&primeirocomando, "S") == 0){
     	i=1;
     	
	 }else{
	 	if(strcmp(&primeirocomando, "C") == 0){
	 		Clientes();
	 		
	 	}else{
	 		if(strcmp(&primeirocomando, "T") == 0){
	 		  Contas();
		}
	   }
	  }  
     }
    }
    
    
void Clientes (void)
{
  char primeirocomando;
	 int i=0, limite=0;
	 printf("\n");
	 while(i<1){
	 
	 
	 printf("============ Gerenciar Clientes ============\nDigite um comando para prosseguir:\nC - Cadastrar um cliente\nL - Listar todos os clientes cadastrados\nB - Buscar cliente ja cadastrado\nA - Atualizar um cliente cadastrado\nE - Excluir um cliente cadastrado\nS - Sair\n");   
     scanf("%s", &primeirocomando);
     
     if(strcmp(&primeirocomando, "S") == 0){
     	i=1;
     	
	 }else{
	 	if(strcmp(&primeirocomando, "C") == 0){
	 		
	     	if(limite<100){
		        limite += CadastroClientes();
	 	   }else{
		    	printf("\nLimite de cadastro alcancado\n");
		   }
	
	 	}else{
	 		if(strcmp(&primeirocomando, "L") == 0){
	 		listarclientes();
		}else{	
              if(strcmp(&primeirocomando, "B") == 0){
	 		 buscarcliente();
		}else{
			    if(strcmp(&primeirocomando, "A") == 0){
	 		alterarcliente();
		}else{
			     if(strcmp(&primeirocomando, "E") == 0){
	 		removercliente();
		
			
	   }
	  }  
     }	 
    }
   }
  }  
 }
 printf("\n");
}


void Contas (void)
{
	char primeirocomando;
	 int i=0, limite=0, limitet=0, o=-1;
	 limite = acharlimiteconta();
	 limitet = acharlimitetransacao();
	 printf("%d--%d", limite, limitet);
	 while(i<1){
	 printf("\n");
	 printf("Digite um comando para prosseguir:\nR - Listagem de todas as contas cadastradas.\nC - Cadastrar uma conta para um cliente.\nL - Listar todas as contas de um cliente.\nW - Realizar um saque em uma conta.\nD - Realizar um deposito em uma conta.\nT - Realizar transferencia entre contas.\nE - Exibir extrato de uma conta.\nS - Sair\n");   
     scanf("%s", &primeirocomando);
    
     if(strcmp(&primeirocomando, "S") == 0){
     	i=1;
     	
	 }else{
	 	if(strcmp(&primeirocomando, "C") == 0){
	 		
		 if(limite<200){
			 Cadastroconta();
		}else{
			printf("\nLimite de cadastro alcancado\n");
		}
	 		
	 	}else{
	 		if(strcmp(&primeirocomando, "L") == 0){
	 		buscarconta();
		}else{	
              if(strcmp(&primeirocomando, "W") == 0){
            if(limitet<1000){
            saque(o, o);	
			}else{
				printf("\nLimite de transacoes alcancado\n");
			} 
			 	
	 		
		}else{
			    if(strcmp(&primeirocomando, "D") == 0){
	 		   if(limitet<1000){
            deposito(o, o, o);	
			}else{
				printf("\nLimite de transacoes alcancado\n");
			} 
		}else{
			     if(strcmp(&primeirocomando, "T") == 0){
	 		     if(limitet<1000){
            transferencia();	
			}else{
				printf("\nLimite de transacoes alcancado\n");
			} 
		}else{
			     if(strcmp(&primeirocomando, "E") == 0){
			     	extratos();
			     	
	  	}else{
			     if(strcmp(&primeirocomando, "R") == 0){
			      	listacontas();
		 
		 
	     }
        }
	   }
	  }  
     }	 
    }
   }
  }
 }
 printf("\n");
}
    
int CadastroClientes (void)
{    
  int i=0, l=55, f=0, local=0;
  char ler[50];
  struct Cliente cadastro;	
   getchar();
  printf("Informe os seguintes valores a serem cadastrados\n");
  printf("Codigo:");
  gets(cadastro.codigo);
  printf("Nome:");
  gets(cadastro.nome);
  printf("CPF/CNPJ:");
  gets(cadastro.cpf);
  printf("Telefone:");
  gets(cadastro.telefone);
  printf("Endereco:");
  gets(cadastro.endereco);
    FILE *fp;   
	fp= fopen("trabalhoarthur.dat", "r+b"); 
    if (fp == NULL){
     printf("Impossivel abrir arquivo!");
    }else{
     i = validacaocliente(cadastro.codigo);
     if(i==0){
     	i = validacaocliente(cadastro.cpf);
	 }
	 
    if(i==0){
        local = acharlimitecliente();
    	if(local<100){
    	fp = fopen("trabalhoarthur.dat", "a+");    
        fwrite(&cadastro,sizeof(struct Cliente),1,fp);   
    	fclose(fp);
    	printf("\n");
    	return(1);
	}else{
		printf("\nLimite de Clientes alcançado\n");
		fclose(fp);
		return(0);
	} 
	
	}else{
		printf("\nCliente ja cadastrado\n");
		printf("\n");
		return(0);
	}
}
}
       
void removercliente(){
    FILE* primeiro = fopen("trabalhoarthur.dat", "r+b");
    FILE* segundo = fopen("trabalhoarthurnovo.dat", "wb");
    char c[50], outro[50], confirmar[2];
    struct Cliente cadastro;
    int i;
    printf("Digite o codigo do cliente a ser excluido: ");
    scanf("%s", c);
    i = validacaocliente(c);
     
	 
    if(i==0){
    	printf("\nCliente nao encontrado\n");
	}else{
		
		acharremover(c);
	printf("\nConfirmar: Y/N\n");
    scanf("%s", confirmar);
        if((strcmp(confirmar, "Y")==0)){
		
		 while(!feof(primeiro)){
        fread(&cadastro, sizeof(cadastro), 1, primeiro);
        if((strcmp(c, cadastro.codigo)!=0)&&(strcmp(outro, cadastro.codigo)!=0)){
        	strcpy(outro, cadastro.codigo);
            fwrite(&cadastro, sizeof(cadastro), 1, segundo);
        }}
     fclose(segundo);
    fclose(primeiro);
    remove("trabalhoarthur.dat");
    rename("trabalhoarthurnovo.dat", "trabalhoarthur.dat");
    printf("\nProcesso aceito!\n");
	}else{
    	printf("\nProcesso nao aceito\n");
	}
  
     
	}

}
   
void listarclientes()
{   
    int outro;
    struct Cliente cadastro;
    FILE * fp;
    if ((fp = fopen("trabalhoarthur.dat","r+b")) == NULL)
    {
                 printf(" \n Arquivo não existe !");
                
    }else{
	
    printf("\nLista de Clientes Cadastrados:\n");
    outro = fread(&cadastro,sizeof(struct Cliente),1,fp);
    if(outro == 0){
    	printf("\n");
    	printf("Nenhum cliente cadastrado");
    	printf("\n");
	}else{
	
 while (outro == 1) 
 {
      printf("\nCodigo: %s",cadastro.codigo);
      printf("\nNome: %s",cadastro.nome);
      printf("\nCPF/CNPJ: %s",cadastro.cpf);
      printf("\nTelefone: %s",cadastro.telefone);
      printf("\nEndereco: %s\n",cadastro.endereco);
      outro = fread(&cadastro,sizeof(struct Cliente),1,fp);
 }
} }
      fclose (fp);
      printf("\n");
      printf("\n");
}

int validacaocliente(char a[50]){
	struct Cliente cadastro;
	FILE *fp;
	char ler[50];
	int i=0, l=55, outro;   
	fp= fopen("trabalhoarthur.dat", "r+b"); 
	if (fp == NULL){
     printf("Impossivel abrir arquivo!");
     return(1);
    }else{
         outro = fread(&cadastro,sizeof(struct Cliente),1,fp);
    if(outro == 0){
    	//printf("Nenhuma conta cadastrado\n");
	}else{
 while (outro == 1) 
 { 
 
        if(l==0){
          		i=1;
			  }
          
          	l = strcmp(a, cadastro.codigo);
          	if(l==0){
          		i=1;
			  }
			l = strcmp(a, cadastro.cpf);
          	
        outro = fread(&cadastro,sizeof(struct Cliente),1,fp);
		} 	
	  }          
    
    fclose(fp);
    
    if(i==1){
    	return(1);
	}else{
		return(0);
	}
}
}

int validacaoconta(char a[50], char b[50]){
	struct Conta cadastro;
	FILE *fp;
	char ler[50];
	int i=0, l=55, outro;   
	fp= fopen("trabalhoarthurconta.dat", "r+b"); 
	if (fp == NULL){
     printf("Impossivel abrir arquivo!");
     return(1);
    }else{
        outro = fread(&cadastro,sizeof(struct Conta),1,fp);
    if(outro == 0){
    	printf("Nenhuma conta cadastrado\n");
	}else{
 while (outro == 1) 
 {
        
          
          	l = strcmp(a, cadastro.agencia);
          	if(l==0){
          		i=1;
			  }
			l = strcmp(b, cadastro.numeroconta);
          	if(l==0){
          		i=1;
			  }
        outro = fread(&cadastro,sizeof(struct Conta),1,fp);
		} 	
	  }          
    
    fclose(fp);
    
    if(i==1){
    	return(1);
	}else{
		return(0);
	}
	
}}


int Cadastroconta(void) {
  int i=0, l=55, outro=-1;
  char ler[50];
  
  struct Conta criar;	
   getchar();
  printf("Informe os valores para criar a conta\n");
  printf("Codigo ou CPF do cliente:");
  gets(criar.cliente);
    
   i=validacaocliente(criar.cliente);  
       
   if(i==1){
   	printf("Agencia:");
    gets(criar.agencia);
   	printf("Numero da conta:");
    gets(criar.numeroconta);
    strcpy(criar.saldo, "0");
    
    l=validacaoconta(criar.agencia, criar.numeroconta);
    
    if(l==1){
    	  printf("\nConta ja existente\n");
    	  printf("\n");
		return(0);  			
	}else{
		FILE *fp;
		fp = fopen("trabalhoarthurconta.dat", "a+");    
        fwrite(&criar,sizeof(struct Conta),1,fp);   
    	fclose(fp);
    	printf("\n");
    	return(1);
		}
   }else{
   	printf("\nCliente nao existe\n");
   	printf("\n");
   	return(0);
   }
   
}



void listacontas()
{   
    int outro;
    struct Conta cadastro;
    FILE * fp;
    if ((fp = fopen("trabalhoarthurconta.dat","r+b")) == NULL)
    {
       printf(" \n Arquivo nao existe !");
       getch();
    }
    printf("\nLista de Contas Cadastrados:\n");
    outro = fread(&cadastro,sizeof(struct Conta),1,fp);
    if(outro == 0){
    	printf("Nenhuma conta cadastrado\n");
	}else{
 while (outro == 1) 
 {
 	  printf("\nCliente: %s",cadastro.cliente); 
      printf("\nAgencia: %s",cadastro.agencia);  
      printf("\nNumero da conta: %s",cadastro.numeroconta);
      printf("\nsaldo: %s",cadastro.saldo);
      outro = fread(&cadastro,sizeof(struct Conta),1,fp);
      printf("\n");
      printf("\n");
 }
}
      
      fclose (fp);
      
}

int acharlimitecliente()
{
    int local=0;
    char achar[50];
    int f= 0;
    struct Cliente cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthur.dat","r+b");
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Cliente),1,fp);
        if(!feof(fp)){
            if(strlen(cadastro.codigo)==0){
                f=1;
            }else{
            	local++;
			}
			
		 
        }
		else
		local=-1;
    }
    fclose(fp);
    return(local);
}

int acharlimiteconta()
{
    int local=0;
    char achar[50];
    int f= 0;
    struct Conta cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthurconta.dat","r+b");
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Conta),1,fp);
        if(!feof(fp)){
            if(strlen(cadastro.cliente)==0){
                f=1;
            }else{
            	local++;
			}
			
		 
        }
		else
		local=-1;
    }
    fclose(fp);
    return(local);
}

int acharlimitetransacao()
{
    int local=0;
    char achar[50];
    int f= 0;
    struct Transacao cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthurtransacao.dat","r+b");
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Transacao),1,fp);
        if(!feof(fp)){
            if(strlen(cadastro.data)==0){
                f=1;
            }else{
            	local++;
			}
			
		 
        }
		else
		local=-1;
    }
    fclose(fp);
    return(local);
}
int acharcliente()
{
    int local=0;
    char achar[50];
    int f= 0;
    struct Cliente cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthur.dat","r+b");
    getchar();
    printf("\nInforme o codigo ou o CPF/CNPJ do cliente a ser pesquisado:");
     gets(achar);
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Cliente),1,fp);
        if(!feof(fp)){
            if(strcmp(achar,cadastro.codigo)==0){
                f=1;
            }else{
			if(strcmp(achar,cadastro.cpf)==0){
                f=1;
            }
			else 
			local++;
		 }
        }
		else
		local=-1;
    }
    fclose(fp);
    return(local);
}

void acharremover(char *a)
{
    int local=0;
    char achar[50];
    int f= 0;
    struct Cliente cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthur.dat","r+b");
    
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Cliente),1,fp);
        if(!feof(fp)){
            if(strcmp(a,cadastro.codigo)==0){
                f=1;
            }else{
			if(strcmp(a,cadastro.cpf)==0){
                f=1;
            }
			else 
			local++;
		 }
        }
		else
		local=-1;
    }
    fseek(fp,local*sizeof(struct Cliente),SEEK_SET);
            fread(&cadastro,sizeof(struct Cliente),1,fp);
            printf("\nCliente buscado: ");
            printf("\n\nCodigo: %s",cadastro.codigo);
            printf("\nNome: %s",cadastro.nome);
            printf("\nCPF/CNPJ: %s",cadastro.cpf);
            printf("\nTelefone: %s",cadastro.telefone);
            printf("\nEndereco: %s\n\n",cadastro.endereco);
    fclose(fp);
    
    
}

void buscarcliente()
{
    struct Cliente cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthur.dat","r+b");
    int pesquisa=0;
    pesquisa=acharcliente();
    
    if(pesquisa==-1){
        printf("\nErro! Cliente nao encontrado!");
        getchar();
    }else{
            fseek(fp,pesquisa*sizeof(struct Cliente),SEEK_SET);
            fread(&cadastro,sizeof(struct Cliente),1,fp);
            printf("\nCliente buscado: ");
            printf("\n\nCodigo: %s",cadastro.codigo);
            printf("\nNome: %s",cadastro.nome);
            printf("\nCPF/CNPJ: %s",cadastro.cpf);
            printf("\nTelefone: %s",cadastro.telefone);
            printf("\nEndereco: %s\n\n",cadastro.endereco);
        }
    fclose(fp);
}

int acharc(char c[50])
{
    int local=0;
    
    int f= 0;
    struct Cliente cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthur.dat","r+b");
    
    
     
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Cliente),1,fp);
        if(!feof(fp)){
            if(strcmp(c,cadastro.codigo)==0){
                f=1;
            }else{
			if(strcmp(c,cadastro.cpf)==0){
                f=1;
            }
			else 
			local++;
		 }
        }
		else
		local=-1;
    }
    fclose(fp);
    return(local);
}

void buscarc(char c[50])
{
    struct Cliente cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthur.dat","r+b");
    int pesquisa=0;
    pesquisa=acharc(c);
    
    if(pesquisa==-1){
        printf("\nErro! Cliente nao encontrado!");
        getchar();
    }else{
            fseek(fp,pesquisa*sizeof(struct Cliente),SEEK_SET);
            fread(&cadastro,sizeof(struct Cliente),1,fp);
            printf("\nCliente buscado: ");
            printf("\n\nCodigo: %s",cadastro.codigo);
            printf("\nNome: %s",cadastro.nome);
            printf("\nCPF/CNPJ: %s",cadastro.cpf);
            printf("\nTelefone: %s",cadastro.telefone);
            printf("\nEndereco: %s\n",cadastro.endereco);
        }
    fclose(fp);
}

int contarfinal(char a[50]){
	struct Conta cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthurconta.dat","r+b");
    int f=0;
	 while (!feof(fp)) 
    {
        fread(&cadastro,sizeof(struct Conta),1,fp);
        
            if(strcmp(a,cadastro.cliente)==0){
                f++;	  
            }
	 
	}
	
	return(f);
	
}


void buscarconta()
{
    struct Conta cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthurconta.dat","r+b");
    int f=0, nada=0, local=0, final=0, outrofinal=0, i=1;
    char achar[50], comparar[50];
   
    getchar();
    printf("\nInforme o codigo do cliente com as contas a serem pesquisadas:");
     gets(achar);
     
      final = contarfinal(achar);
            
     printf("\nContas encontradas:");
      rewind(fp);
      
    while ((!feof(fp))&&(outrofinal<final)) 
    {
        fread(&cadastro,sizeof(struct Conta),1,fp);
        
            if(strcmp(achar,cadastro.cliente)==0){
                f=1;
				nada=1;
				outrofinal++;
							
			fseek(fp,local*sizeof(struct Conta),SEEK_SET);
            fread(&cadastro,sizeof(struct Conta),1,fp);
            if(strcmp(comparar,cadastro.agencia)!=0){
			printf("\n\nCodigo do Cliente: %s",cadastro.cliente);
            printf("\nAgencia: %s",cadastro.agencia);
            printf("\nNumero da conta: %s",cadastro.numeroconta);
            printf("\nSaldo: %s",cadastro.saldo); 
			printf("\n");
			strcpy(comparar, cadastro.agencia);
		    }
			    if(outrofinal>0){
				   local++;
			     }
			     
            }
			else{
			local++;
			f=0; 
		    }
			
           
	}
    
    if(nada==0){
        printf("\nNenhuma conta cadastrada");
        printf("\n");
       
    }
    printf("\n");
    fclose(fp);
}


void alterarcliente()
{
  FILE *fp;
  fp = fopen("trabalhoarthur.dat","rb+");  
  struct Cliente cadastro;        
  int i;
    i=acharcliente();
    if(i==-1){
        printf("\nCliente nao encontrado\n");
        getch();
    }
    else{
            fseek(fp,i*sizeof(struct Cliente),SEEK_CUR);
            fread(&cadastro,sizeof(struct Cliente),1,fp);
            printf("\nCliente a ser alterado: ");
            printf("\n\nCodigo: %s",cadastro.codigo);
            printf("\nNome: %s",cadastro.nome);
            printf("\nCPF/CPNJ %s",cadastro.cpf);
            printf("\nTelefone %s",cadastro.telefone);
            printf("\nEndereco %s",cadastro.endereco);
        }
        printf("\n\nAlterar o codigo para: "); 
        gets(cadastro.codigo);
        printf("Alterar o nome para: ");
        gets(cadastro.nome);
        printf("Alterar o CPF/CNPJ para: ");
        gets(cadastro.cpf);
        printf("Alterar o telefone para: "); 
        gets(cadastro.telefone);
        printf("Alterar o endereco para: "); 
        gets(cadastro.endereco);
        fseek(fp,i*sizeof(struct Cliente),SEEK_SET);
        if(fwrite(&cadastro,sizeof(struct Cliente),1,fp)!=1)
        {
            printf("Erro na alteracao");
        }
        else{
            printf("\nAlteracao ocorrida com sucesso\n");
        }
        fclose(fp);
    }
    
    
int acharconta()
{
    int local=0;
    char agemcia[50], numeroconta[50];
    int f= 0;
    struct Conta cadastro;
    FILE *fp;
    fp = fopen("trabalhoarthurconta.dat","r+b");
    getchar();
    printf("\nInforme a agencia da conta:");
     gets(agemcia);
     printf("\nInforme o numero da conta:");
     gets(numeroconta);
    rewind(fp);
    while ((!feof(fp))&&(f==0))
    {
        fread(&cadastro,sizeof(struct Conta),1,fp);
        if(!feof(fp)){
            if(strcmp(agemcia,cadastro.agencia)==0){
                if(strcmp(numeroconta,cadastro.numeroconta)==0){
                f=1;
            }else
             local++;
            }
			else
            local++;
			} 
		else
		local=-1;
	}
    
    fclose(fp);
    return(local);
}
    
void saqueconclusao(int s, char *c){
  FILE *fp;
  fp = fopen("trabalhoarthurtransacao.dat","a+"); 
  struct Transacao cadastro;
  char descrica[100], valores[50];
  int duzentos=0, cem=0, cinquenta=0, vinte=0, dez=0, cinco=0, dois=0, tempo=0;
  	itoa(s, valores, 10);
  	struct tm *p;
    time_t seconds;
    char temposs[12];
    time(&seconds);
    p = localtime(&seconds);

    sprintf(temposs, "%2d/%2d/%4d",
          p->tm_mday,
          p->tm_mon + 1,
          p->tm_year + 1900);
printf("\nInforme uma descricao dessa transacao:");
     gets(descrica);
     strcpy(cadastro.data, temposs);
     strcpy(cadastro.conta, c);
     strcpy(cadastro.tipo, "DEBITO");
     strcpy(cadastro.valor, valores);
     strcpy(cadastro.descricao, descrica);
	fwrite(&cadastro,sizeof(struct Transacao),1,fp);   
	printf("\n");
	fclose(fp);
    	while(s>1){
	
	if(s%200==0){
		duzentos++;
		s = s-200;
	}else{
	   	 if(s%100==0){
		cem++;
		s = s-100;
	  }else{
	      if(s%50==0){
		cinquenta++;
		s = s-50;
	}else{
	      if(s%20==0){
		vinte++;
		s = s-20;
	  }else{
	    
		 if(s%10==0){
		dez++;
		s = s-10;
	}else{
	   
	  if(s%5==0){
	   cinco++;
		s = s-5;
	  }else{
	     if(s%2==0){
		dois++;
		s = s-2; 
        }else{
               s = s-1;
	    }
        }
       }
      }
	 }
    }
   }
  }
  printf("Retiradas: ");
  if(duzentos>0){
  	 if(duzentos==1)
  	printf(" %d nota de duzentos  ", duzentos);
  	else 
  	printf(" %d notas de duzentos  ", duzentos);
  }
  
  if(cem>0){
  	if(cem==1)
  	printf(" %d nota de cem  ", cem);
  	else
  	printf(" %d notas de cem  ", cem);
  }
  
  if(cinquenta>0){
  	if(cinquenta==1)
  	 printf(" %d nota de cinquenta  ", cinquenta);
  	 else
  	 printf(" %d notas de cinquenta  ", cinquenta);
  }
  
  if(vinte>0){
  	if(vinte==1)
  	printf(" %d nota de vinte ", vinte);
  	else
  	printf(" %d notas de vinte ", vinte);
  }
  
  if(dez>0){
  	if(dez==1)
  	 printf(" %d nota de dez ", dez);
  	 else
  	 printf(" %d notas de dez ", dez);
  }
  
  if(cinco>0){
  	if(cinco==1)
  	printf(" %d nota de cinco ", cinco);
  	else
  	printf(" %d notas de cinco ", cinco);
  }
  
  if(dois>0){
  	if(dois==1)
  		printf(" %d nota de dois ", dois);
		  else
		   printf(" %d notas de dois ", dois);  
  }
  printf("\n");
  printf("\n");
  
  }
 
 void depositoconclusao(int s, char c[])
 {
  FILE *fp;
  fp = fopen("trabalhoarthurtransacao.dat","a+"); 
  struct Transacao cadastro;
  char descrica[100], valores[50];
  int duzentos=0, cem=0, cinquenta=0, vinte=0, dez=0, cinco=0, dois=0, tempo=0;
  	itoa(s, valores, 10);
  	struct tm *p;
    time_t seconds;
    char temposs[12];
    time(&seconds);
    p = localtime(&seconds);

    sprintf(temposs, "%2d/%2d/%4d",
          p->tm_mday,
          p->tm_mon + 1,
          p->tm_year + 1900);
printf("\nInforme uma descricao dessa transacao:");
     gets(descrica);
     strcpy(cadastro.data, temposs);
     strcpy(cadastro.conta, c);
     strcpy(cadastro.tipo, "CREDITO");
     strcpy(cadastro.valor, valores);
     strcpy(cadastro.descricao, descrica);
	fwrite(&cadastro,sizeof(struct Transacao),1,fp);   
	printf("\n");
	fclose(fp);

}
	
 
	 
int saque(int a, int b)
{
  FILE *fp;
  fp = fopen("trabalhoarthurconta.dat","rb+");  
  struct Conta cadastro;        
  int i, sacar=0, final=0, original=0;
  char saque[50], numconta[50];
  
  if(a==-256)
  {
  
   
    i=acharconta();
    
    if(i==-1){
        printf("\nConta nao encontrado\n\n");
        return (0);
         getch();
    }
    else{
            fseek(fp,i*sizeof(struct Conta),SEEK_CUR);
            fread(&cadastro,sizeof(struct Conta),1,fp);
            printf("\nDados Clientes: ");
            printf("\n");
            buscarc(cadastro.cliente);
            printf("\n\nCodigo do Cliente: %s",cadastro.cliente);
            printf("\nAgencia: %s",cadastro.agencia);
            printf("\nNumero da Conta: %s",cadastro.numeroconta);
            printf("\nSaldo: %s",cadastro.saldo);
            original =atoi(cadastro.saldo);
		} 
        printf("\n\nValor do Saque: "); 
        gets(saque);
        sacar = atoi(saque); 
         if(sacar>original){
         		printf("Valor ultrapassa seu saldo!");
				 printf("\n");
				 fclose(fp);
         		return(0);
		 }else{
         final = original - sacar;
		 itoa(final, saque, 10);  
        strcpy(cadastro.saldo, saque);
        fseek(fp,i*sizeof(struct Conta),SEEK_SET);
        fwrite(&cadastro,sizeof(struct Conta),1,fp);
         fclose(fp);
         fseek(fp,i*sizeof(struct Conta),SEEK_SET);
         
        	saqueconclusao(sacar, cadastro.numeroconta);
            printf("\nTransacao ocorrida com sucesso\n");
            printf("\n");
            return(1);
        }
  }else{
  	
  	if(a==6663){
  		i=acharconta();
  	if(i==-1){
        printf("\nConta nao encontrado\n\n");
        return (-1);
         getch();
    }
    else{
          
		  
		    fseek(fp,i*sizeof(struct Conta),SEEK_CUR);
            fread(&cadastro,sizeof(struct Conta),1,fp);
            printf("\nDados Clientes: ");
            printf("\n");
            buscarc(cadastro.cliente);
            printf("\n\nCodigo do Cliente: %s",cadastro.cliente);
            printf("\nAgencia: %s",cadastro.agencia);
            printf("\nNumero da Conta: %s",cadastro.numeroconta);
            printf("\nSaldo: %s",cadastro.saldo);
            fclose(fp);
            return (i);
            
		} 
     }else{     
  		fseek(fp,a*sizeof(struct Conta),SEEK_CUR);
        fread(&cadastro,sizeof(struct Conta),1,fp);
        
  		printf("\n\nValor do Saque: "); 
  		fflush(stdin);  
        gets(saque);
        
        original =atoi(cadastro.saldo);
        sacar = atoi(saque); 
         if(sacar>original){
         		printf("Valor ultrapassa seu saldo!");
				 printf("\n");
				 fclose(fp);
         		return(-1);
		 }else{
         final = original - sacar;
		 itoa(final, saque, 10);  
        strcpy(cadastro.saldo, saque);
        strcpy(numconta, cadastro.numeroconta);
        fseek(fp,a*sizeof(struct Conta),SEEK_SET);
        fwrite(&cadastro,sizeof(struct Conta),1,fp);
         fclose(fp);
           redirecionarsaque(b, numconta, sacar);
         
            
            printf("\n");
            return(sacar);
	  }
    }
  }
      

}
    
void redirecionarsaque(int a, char *b, int c){
	FILE *fp;
  fp = fopen("trabalhoarthurconta.dat","rb+");  
  struct Conta cadastro; 
	fseek(fp,a*sizeof(struct Conta),SEEK_SET);
         fread(&cadastro,sizeof(struct Conta),1,fp);
         
         
        	saquetransfer(c, b, cadastro.agencia, cadastro.numeroconta);
	fclose(fp);

}

void redirecionardeposito(int a, char *b, int c){
	FILE *fp;
  fp = fopen("trabalhoarthurconta.dat","rb+");  
  struct Conta cadastro; 
	fseek(fp,a*sizeof(struct Conta),SEEK_SET);
         fread(&cadastro,sizeof(struct Conta),1,fp);
         
         
    depositotransfer(c, b, cadastro.agencia, cadastro.numeroconta);
	fclose(fp);

}    
    
 int deposito(int a, int b, int c)
{
  FILE *fp;
  fp = fopen("trabalhoarthurconta.dat","rb+");  
  struct Conta cadastro;        
  int i, depositos=0, final=0, original=0;
  char deposito[50], numconta[50];
   
  
  if(a==-256)
  {
    i=acharconta();
    if(i==-1){
        printf("\nConta nao encontrado\n\n");
        return (0);
         getch();
    }
    else{
            fseek(fp,i*sizeof(struct Conta),SEEK_CUR);
            fread(&cadastro,sizeof(struct Conta),1,fp);
            printf("\nDeus dados: ");
            printf("\n");
            buscarc(cadastro.cliente);
            printf("\n\nCodigo do Cliente: %s",cadastro.cliente);
            printf("\nAgencia: %s",cadastro.agencia);
            printf("\nNumero da Conta: %s",cadastro.numeroconta);
            
            original =atoi(cadastro.saldo);
		}
        
        printf("\n\nValor do deposito: "); 
        gets(deposito);
        depositos = atoi(deposito);
  
         final = original + depositos;
		 itoa(final, deposito, 10);
		 
        strcpy(cadastro.saldo, deposito);   
        fseek(fp,i*sizeof(struct Conta),SEEK_SET);
        if(fwrite(&cadastro,sizeof(struct Conta),1,fp)!=1)
        {
            printf("Erro na transacao");
            printf("\n");
            fclose(fp);
            return(0);
            
        }
        else{
        	depositoconclusao(depositos, cadastro.numeroconta);
            printf("\nTransacao ocorrida com sucesso\n");
            printf("\n");
            fclose(fp);
            return(1);
        }
        
        
    }else{
    	
    	if(a==6663){
    	i=acharconta();
    if(i==-1){
        printf("\nConta nao encontrado\n\n");
        return (-1);
         getch();
    }
    else{
            fseek(fp,i*sizeof(struct Conta),SEEK_CUR);
            fread(&cadastro,sizeof(struct Conta),1,fp);
            printf("\nDeus dados: ");
            printf("\n");
            buscarc(cadastro.cliente);
            printf("\n\nCodigo do Cliente: %s",cadastro.cliente);
            printf("\nAgencia: %s",cadastro.agencia);
            printf("\nNumero da Conta: %s",cadastro.numeroconta);
            fclose(fp);
    	    return(i); 
			 }}  	
	  else{
		fseek(fp,a*sizeof(struct Conta),SEEK_CUR);
        fread(&cadastro,sizeof(struct Conta),1,fp);
        original =atoi(cadastro.saldo);
         final = original + b;
		 itoa(final, deposito, 10);
		 
        strcpy(cadastro.saldo, deposito); 
		strcpy(numconta, cadastro.numeroconta);    
        fseek(fp,a*sizeof(struct Conta),SEEK_SET);
        if(fwrite(&cadastro,sizeof(struct Conta),1,fp)!=1)
        {
            printf("Erro na transacao");
            printf("\n");
            fclose(fp);
            return(0);
            
        }
        else{
        	fclose(fp);
        	redirecionardeposito(c, numconta, b);
            
            printf("\n");
            fclose(fp);
            return(3);
        }
		
	}
	
    
    }
}
    
void listatransacoes(char d[50], char a[20] )
{   
    int outro, checar=0;
    
   
    struct Transacao cadastro;
    FILE * fp;
    if ((fp = fopen("trabalhoarthurtransacao.dat","r+b")) == NULL)
    {
       printf(" \n Arquivo nao existe !");
       getch();
    }
    
    
    outro = fread(&cadastro,sizeof(struct Transacao),1,fp);
    if(outro == 0){
    	printf("Nenhum extrato encontrado\n");
    	
	}else{
 while (outro == 1) 
 {
 	  if((strcmp(cadastro.data, a) == 0)&&(strcmp(cadastro.conta, d) == 0)){
	   
 	  printf("\nData: %s",cadastro.data); 
      printf("\nTipo: %s",cadastro.tipo);  
      printf("\nValor: %s",cadastro.valor);
      printf("\nConta: %s",cadastro.conta);
      printf("\nDescricao: %s",cadastro.descricao);
      checar++;
      }
      outro = fread(&cadastro,sizeof(struct Transacao),1,fp);
      printf("\n");
      printf("\n");
 }
     if(checar==0){
      	printf("\nNenhum extrato encontrado na data: %s\n", a);
	  }
}
    
      fclose (fp);
      
}
    
void extratos(){
    	FILE *fp;
  fp = fopen("trabalhoarthurconta.dat","rb+");  
  struct Conta cadastro;        
  int i, dias=0, t=1, me=0;
  char extra[20];
    i=acharconta();
    if(i==-1){
        printf("\nConta nao encontrado\n\n");
         
    }
    else{
            fseek(fp,i*sizeof(struct Conta),SEEK_CUR);
            fread(&cadastro,sizeof(struct Conta),1,fp);
            printf("\nDeus dados: ");
            printf("\n");
            buscarc(cadastro.cliente);
            printf("\n\nCodigo do Cliente: %s",cadastro.cliente);
            printf("\nAgencia: %s",cadastro.agencia);
            printf("\nNumero da Conta: %s",cadastro.numeroconta);
            
       printf("\nInforme a quantidade de dias para exibir no extrato: ");
       scanf("%d", &dias); 
        struct tm *p;
    time_t seconds;
    char temposs[12];
    time(&seconds);
    p = localtime(&seconds);
    int l=0, b=0, final=0, m=1, an=0;
    if((p->tm_mon+1==2)||(p->tm_mon+1==4)||(p->tm_mon+1==6)||(p->tm_mon+1==8)||(p->tm_mon+1==9)||(p->tm_mon+1==11)||(p->tm_mon+1==1)){
          
           b=1;
       }
    if((p->tm_mon+1==3)||(p->tm_mon+1==5)||(p->tm_mon+1==7)||(p->tm_mon+1==10)){
          
           b=2;
       }   
    if(p->tm_mon+1==3){
           
		   b=3;	
       }    
       m=dias/30;
        while(dias>-1){
       
      if((p->tm_mday-dias)<1){
      	
      
      	
      	if((final==0)&&(b==1)){
      		l=31-(dias%31);
      		final=1;
		  }
		 if((final==0)&&(b==2)){
      		l=1+30-(dias%30);
      		final=1;
		  } 
		  
		  
		  if((l%30==1)&&(b==1)){
		  	m--;
		  	l=31-(dias%31);
		  }
		  
		  if((l%31==1)&&(b==2)){
		  	m--;
		  	l=1+30-(dias%30);
		  }
	   
      	  sprintf(extra, "%2d/%2d/%4d",
          l,
          p->tm_mon + 1-m,
          p->tm_year + 1900 );
      
          l++;
      	
	  }else{   
         sprintf(extra, "%2d/%2d/%4d",
          p->tm_mday-dias,
          p->tm_mon + 1,
          p->tm_year + 1900);
    	
    }
    	
     
     listatransacoes(cadastro.numeroconta, extra);
	 dias--; 
	}}
    	fclose(fp);
	}
    
    
    
int transferencia(){
    int cont=6663, i=0, j=0, final=0;
	
		i=saque(cont, cont);
		if(i==-1){
			printf("\nConta nao existe!\n");
			return(0);
		}else{
		   j=deposito(cont, cont, cont);
		   
		   	if(j==-1){
			printf("\nConta nao existe!\n");
			return(0);
		  }else{
		  	
			cont=saque(i, j);
			if(cont==-1){
				return(0);
			}else{
			
		   	final=deposito(j, cont, i);
		   	if(final==3){
		   		 printf("\nTransacao ocorrida com sucesso\n");
		   		 return(1);
			   }else{
			   	printf("\nTransacao ocorrida sem sucesso\n");
			   	return(0);
			   }
		   }
		}
    }
	}
    
void depositotransfer(int s, char *c, char *d, char *n)
 {
  FILE *fp;
  fp = fopen("trabalhoarthurtransacao.dat","a+"); 
  struct Transacao cadastro;
  char descrica[100], valores[50];
 
  	itoa(s, valores, 10);
  	struct tm *p;
    time_t seconds;
    char temposs[12];
    time(&seconds);
    p = localtime(&seconds);
    sprintf(descrica, "Transferencia de conta: %s-%s", d, n);
     
    sprintf(temposs, "%2d/%2d/%4d",
          p->tm_mday,
          p->tm_mon + 1,
          p->tm_year + 1900);

     strcpy(cadastro.data, temposs);
     strcpy(cadastro.conta, c);
     strcpy(cadastro.tipo, "CREDITO");
     strcpy(cadastro.valor, valores);
     strcpy(cadastro.descricao, descrica);
	fwrite(&cadastro,sizeof(struct Transacao),1,fp);   
	printf("\n");
	fclose(fp);

}

void saquetransfer(int s, char *c, char *d, char *n){
  FILE *fp;
  fp = fopen("trabalhoarthurtransacao.dat","a+"); 
  struct Transacao cadastro;
  char descrica[100], valores[50];
  
  	itoa(s, valores, 10);
  	struct tm *p;
    time_t seconds;
    char temposs[12];
    time(&seconds);
    p = localtime(&seconds);

    sprintf(temposs, "%2d/%2d/%4d",
          p->tm_mday,
          p->tm_mon + 1,
          p->tm_year + 1900);
sprintf(descrica, "Transferencia para conta: %s-%s", d, n);
     strcpy(cadastro.data, temposs);
     strcpy(cadastro.conta, c);
     strcpy(cadastro.tipo, "DEBITO");
     strcpy(cadastro.valor, valores);
     strcpy(cadastro.descricao, descrica);
	fwrite(&cadastro,sizeof(struct Transacao),1,fp);   
	printf("\n");
	fclose(fp);
	
}
