#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 6
#define SWITCH 0

void sol_generate(int arr[], int num, int size);
int ten_times(int times);

int main(int argc, char* argv[])
{
	srand(time(NULL));
//  �D��
	int key[SIZE], cnt;
	for(cnt=0; cnt<SIZE; cnt++){
		key[cnt] = (rand()%10);
#if	SWITCH
		printf("%d", key[cnt]);
#endif
	}
//	printf("\n");
//  �Ĥ@���ѵ� 
	printf("******************************\n");
	printf( "*�q�Ʀr�C�� Ver 1.1          *\n*�@�� : Tony Chen            *\n"
	        "*----------------------------*\n"
	        "*�o�O�@�ӥ��Z�L�_���q�Ʀr�C��*\n*�ӥB�٬O�{�ɰ_�N�g��        *\n*"
	        "�ܦh���b���i�o�[�F          *\n*������ݭn�Ъ����s���@�̧a  *\n"
			"*�л��P���ⴣ�ܮ����a ~    *\n");
	printf("******************************\n\n");
	int sol[SIZE], sol_enter;
	printf("�п�J<%d>��Ʀr : ", SIZE);
	scanf("%d", &sol_enter);
	sol_generate(sol, sol_enter, SIZE);
#if	SWITCH
	for(cnt=0; cnt<SIZE; cnt++){
		printf("%d\n", sol[cnt]);
	}
#endif
//  ����
	int correct = 1;
	int a = 0, b = 0;
	while(correct){
		for(cnt=0; cnt<SIZE; cnt++){
			if(key[cnt] == sol[cnt]){
				a++;
			}else	b++;
		}
		
		if(a==SIZE){
			correct = 0;
		}else{
			correct = 1;
			printf("%dA %dB  �A�q�@���a ~\n\n", a, b);
			printf("�п�J<%d>��Ʀr : ", SIZE);
			scanf("%d", &sol_enter);
	     	sol_generate(sol, sol_enter, SIZE);
			a=0;
			b=0;
		}
	}
	printf("\n\nCongratulation! �p��o�F���ܡAtxt�ɤw����\n"); 
//  ���ʹ��ܤ�� 
	FILE *fp = fopen("Hint.txt", "w");
    fprintf(fp,"���G1F�J�f����  312�H�c  �����ѽX�һݪ��t�@�����Ȥ�\n\n\n"
	           "�p��C����������D�Ϋ��СA�гs�W https://github.com/Visat/Others_2014\n\n"
			   "���{���w�}��Open Source�A�z�i�H�ۦ�ק�o�G\nı�o6��Ƥ����L�}?  ��SIZE�令100�a!\n");
    fclose(fp); 

	system("pause");	
	return 0;
}

// Function : �N��J�Ʀr����s�iarray 
void sol_generate(int arr[], int num, int size)
{
	int cnt, cntArr = 0;
	for(cnt=size-1; cnt>0; cnt--){
		arr[cntArr] = num / ten_times(cnt);
		cntArr++;
	}
	arr[size-1] = num;

	for(cnt=size-1; cnt>0; cnt--){
		arr[cnt] = arr[cnt] - (arr[cnt-1]*10);
	}
}

// Function : 10������B�� 
int ten_times(int times){
	int return_value=10, cnt;
	for(cnt=1; cnt<times; cnt++){
		return_value *= 10;
	}
	return return_value;
}

