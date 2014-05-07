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
//  題目
	int key[SIZE], cnt;
	for(cnt=0; cnt<SIZE; cnt++){
		key[cnt] = (rand()%10);
#if	SWITCH
		printf("%d", key[cnt]);
#endif
	}
//	printf("\n");
//  第一次解答 
	printf("******************************\n");
	printf( "*猜數字遊戲 Ver 1.1          *\n*作者 : Tony Chen            *\n"
	        "*----------------------------*\n"
	        "*這是一個平凡無奇的猜數字遊戲*\n*而且還是臨時起意寫的        *\n*"
	        "很多防呆都懶得加了          *\n*有什麼需要請直接連絡作者吧  *\n"
			"*請輕鬆的把提示拿到手吧 ~    *\n");
	printf("******************************\n\n");
	int sol[SIZE], sol_enter;
	printf("請輸入<%d>位數字 : ", SIZE);
	scanf("%d", &sol_enter);
	sol_generate(sol, sol_enter, SIZE);
#if	SWITCH
	for(cnt=0; cnt<SIZE; cnt++){
		printf("%d\n", sol[cnt]);
	}
#endif
//  驗證
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
			printf("%dA %dB  再猜一次吧 ~\n\n", a, b);
			printf("請輸入<%d>位數字 : ", SIZE);
			scanf("%d", &sol_enter);
	     	sol_generate(sol, sol_enter, SIZE);
			a=0;
			b=0;
		}
	}
	printf("\n\nCongratulation! 妳獲得了提示，txt檔已產生\n"); 
//  產生提示文件 
	FILE *fp = fopen("Hint.txt", "w");
    fprintf(fp,"光二1F入口左側  312信箱  內有解碼所需的另一部份紙片\n\n\n"
	           "如對遊戲有任何問題或指教，請連上 https://github.com/Visat/Others_2014\n\n"
			   "此程式已開放為Open Source，您可以自行修改發佈\n覺得6位數不夠過癮?  把SIZE改成100吧!\n");
    fclose(fp); 

	system("pause");	
	return 0;
}

// Function : 將輸入數字分位存進array 
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

// Function : 10的次方運算 
int ten_times(int times){
	int return_value=10, cnt;
	for(cnt=1; cnt<times; cnt++){
		return_value *= 10;
	}
	return return_value;
}

