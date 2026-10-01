#include<stdio.h>
int Ackermann(int m, int n) {//Ackermann函數定義(可以使用堆疊)
	if (m == 0) {//如果m=0執行這段程式，如果不是就跳過不執行這段程式
		return n = n + 1;//執行n=n+1並把值傳回
	}
	else if (n == 0) {//如果n=0執行住段程式碼，如果不是就跳過不執行這段程式
		return Ackermann(m - 1, 1);//執行阿克曼函數
	}
	else {//上面兩點m!=0,n!=0的話，執行這段程式碼
		return Ackermann(m - 1, Ackermann(m, n - 1));//公式A(m-1,A(m,n-1))
	}
}
int Ackermannnonrecursive(int m, int n) {//Ackermannnonrecursive函數定義(不可以使用堆疊)
	int stack[1000];//因為不能使用堆疊，這裡用陣列來代替
	int top = 0;//設定現在計入位置是在最底層0
	stack[top] = m;//將輸入的m放入堆疊
	top++;//因為第一個位置被放入m了所以要把位置往下一格
	while (top > 0) {//堆疊裡面如果還有數字就要繼續執行
		top--;
		m = stack[top];
		if (m == 0) {
			n = n + 1;
		}
		else if (n == 0) {
			m = m - 1;
			n = 1;
			stack[top] = m;
			top++;
		}
		else {
			stack[top] = m-1;
			top++;
			stack[top] = m;
			top++;
			n = n - 1;
		}
	}
	return n;

}
int main() {
	int a, b;//宣告整數a,b
	scanf("%d %d",&a,&b);//輸入數值a,b
	printf("%d\n", Ackermann(a, b));//將輸入得數值a,b帶回Ackermann函數，最後把結果輸出
	printf("%d\n", Ackermannnonrecursive(a, b));
	return 0;
}