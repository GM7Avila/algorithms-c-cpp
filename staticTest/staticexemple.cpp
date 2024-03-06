#import <stdio.h>

int main(void)
{
	void teste(void);
	
	teste();
	teste();
	teste();
	
	return 0;
}

void teste(void)
{

	int variaveLocalAutomatica = 2;
	variavelLocalAutomatica *= 2;

	static int variavelLocalEstatica = 2;
	variavelLocalEstatistica *=2;
	
	printf("Local Automatica = %i\n", variavelLocalAutomatica);
	printf("Local Automatica = %i\n", variavelLocalEstatica);

}
