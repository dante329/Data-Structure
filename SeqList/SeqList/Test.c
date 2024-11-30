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
	printf("��������Ҫ���еĲ�����");
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
		//����scanf("%d", &option);��scanf("%d ", &option);
		/*�ӿո��Ч��
		1.�����%d ��Ϊ��
			��ȡһ���������������������ַ�ʱֹͣ�������ո���з�����
		2."%d "�����ո񣩵���Ϊ��
			��ȡһ���������������пհ��ַ��������ո��Ʊ���ͻ��з��ȣ��������ȴ����룬ֱ������һ���ǿհ��ַ�Ϊֹ��
			���û�зǿհ��ַ���scanf ���������ȴ��û����롣
		3.Ϊʲô������ȫ�����������
			���ո�� %d ��������ʽ�����������������ͨ��ƥ��ķ�ʽ�����հ��ַ���
			���������������뻺�����зǿհ��ַ��ĸ��š����磬���������������ĸ����ţ�������Ȼ�ᱣ����
		4.�ܽ�
			�� scanf �ĸ�ʽ˵�����мӿո��� "%d "�����������հ��ַ����������з������������ǿɿ��Ļ�������������
			�Ƽ�ʹ�� getchar ѭ������ʽ��ջ�������ȷ�������߼��Ľ�׳�Ժͼ����ԡ�
		*/
		switch (option)
		{
		case 1:
			break;
		case 2:
			//�״�㣺
			//int c = 0;�����int�ᱨ����
			//�� case ������������ʱ������ʹ�ô����ţ�����������Ϊ��Щ�������� case ��ǩͬ���ġ����ڱ�׼���ǲ�������ġ�
			//��ǩ���� case �� default��������ֻ�ǳ�����ת��Ŀ�꣬��������������Ҫ����ռ�ͳ�ʼ���Ĳ�����ֱ���ڱ�ǩ���������������׵����߼��ϵĻ��ң���˱�׼��ֹ������д����
			//��Ҫ�ô����� {} �� case �Ĵ������������ʹ�����������ڿ��������ڣ�����
		{
			int c = 0;
			while ((c = getchar()) != '\n' && c != EOF);
			//getchar();������Ч����ͬ������stdin�е�\n����Ϊscanf�Ƕ�ȡ����\n��
			//��һ����������󻺳����в����˻��з���'\n'�������� fgets ֱ�Ӷ�ȡ������з������������������֮ǰʹ���� scanf ��ȡ���룬scanf ����������뻺�����еĻ��з���
			printf("��������Ҫβ������֣�\n");
			if (fgets(buffer, sizeof(buffer), stdin)) {
				char* current = buffer;
				int value, offset;

				// ʹ�� sscanf ѭ�������������еĶ������
				while (sscanf(current, "%d%n", &value, &offset) == 1) {
					SeqListPushBack(&s1, value); // ����˳���
					current += offset;            // ����ָ��λ��
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