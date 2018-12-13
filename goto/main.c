#include<stdio.h>
#include<unistd.h>

void* _func1;
void func1(void)
{
	_func1 = && func1_label;
	int i=0;
	switch(i)
	{
		case 0:
			{
				printf("This is func1 case 0.\n");
			};
			break;
		case 1:
			{
				while(1)
				{
					printf("This is func1 label.\n");
					func1_label:;
					usleep(1000000);
				}
			};
			break;
	}
	i=1;
}

int main(int argc,char* argv[])
{
	func1();

	goto *_func1;
    return 0;
}
