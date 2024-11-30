#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void TestSeqList()
{
	SL p;
	SeqListInit(&p);
	SeqListPushFront(&p, 1);
	SeqListPushFront(&p, 2);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 4);
	SeqListPushFront(&p, 5);
	SeqListPushFront(&p, 6);
	SeqListPushFront(&p, 7);
	SeqListPushFront(&p, 8);
	SeqListPushFront(&p, 9);
	SeqListPushFront(&p, 9);
	SeqListPushFront(&p, 9);
	SeqListPushFront(&p, 9);
	SeqListPrint(&p);
	SeqListPushBack(&p, 111);
	SeqListPrint(&p);


}

void menu()
{
	printf("********************************************\n");
	printf("1.SeqListPushFront         2.SeqListPushBack\n");
	printf("3.SeqListPopFront          4.SeqListPopBack \n");
	printf("5.SeqListInsert            6.SeqListErase   \n");
	printf("7.SeqListFind              8.SeqListModify  \n");
	printf("9.SeqListPrint             0.SeqListDestory\n");
	printf("********************************************\n");
	printf("请输入你要进行的操作：");
}

int main()
{
	//TestSeqList();
	SL s1;
	SeqListInit(&s1);
	int option = 0;
	int x = 0;
	char buffer[100];
	do
	{
		menu();
		scanf("%d", &option);
		//关于scanf("%d", &option);与scanf("%d ", &option);
		/*加空格的效果
		1.常规的%d 行为：
			读取一个整数，在遇到非数字字符时停止（包括空格或换行符）。
		2."%d "（带空格）的行为：
			读取一个整数后，跳过所有空白字符（包括空格、制表符和换行符等），继续等待输入，直到遇到一个非空白字符为止。
			如果没有非空白字符，scanf 会阻塞，等待用户输入。
		3.为什么不能完全清除缓冲区？
			带空格的 %d 并不是显式地清除缓冲区，而是通过匹配的方式跳过空白字符。
			它并不能消除输入缓冲区中非空白字符的干扰。例如，如果缓冲区中有字母或符号，它们仍然会保留。
		4.总结
			在 scanf 的格式说明符中加空格（如 "%d "）可以跳过空白字符（包括换行符），但并不是可靠的缓冲区清理方法。
			推荐使用 getchar 循环来显式清空缓冲区，确保输入逻辑的健壮性和兼容性。
		*/
		switch (option)
		{
		case 1:
			break;
		case 2:
			//易错点：
			//int c = 0;这里的int会报警告
			//在 case 块中声明变量时，若不使用大括号，编译器会认为这些声明是与 case 标签同级的。这在标准中是不被允许的。
			//标签（如 case 和 default）本质上只是程序跳转的目标，而变量声明是需要分配空间和初始化的操作。直接在标签后声明变量，容易导致逻辑上的混乱，因此标准禁止了这种写法。
			//需要用大括号 {} 将 case 的代码包裹起来，使变量声明处于块作用域内！！！
		{
			int c = 0;
			while ((c = getchar()) != '\n' && c != EOF);
			//getchar();与上面效果相同，消除stdin中的\n，因为scanf是读取不了\n的
			//上一次输入结束后缓冲区中残留了换行符（'\n'），导致 fgets 直接读取这个换行符。这种情况常见于你之前使用了 scanf 读取输入，scanf 不会清除输入缓冲区中的换行符。
			printf("请输入你要尾插的数字：\n");
			if (fgets(buffer, sizeof(buffer), stdin)) {
				char* current = buffer;
				int value, offset;

				// 使用 sscanf 循环解析输入行中的多个整数
				while (sscanf(current, "%d%n", &value, &offset) == 1) {
					SeqListPushBack(&s1, value); // 存入顺序表
					current += offset;            // 更新指针位置
				}
			}
		}
			break;
		case 3:
			break;
		case 9:
			SeqListPrint(&s1);
			break;
		}

	} while (option != 0);

	SeqListDestory(&s1);
	return 0;
}