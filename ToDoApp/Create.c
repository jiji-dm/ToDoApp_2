#define _CRT_SECURE_NO_WARNINGS	

#include "Create.h"

void create(Task *task_ptr) {
	printf("�V�K�o�^���܂�\n�\�����ꂽ���ڂ���͂��Ă�������\n");
	int num2;
	for (num2 = 0; num2 < TASKMAX; num2++) {

		//����������Ă��Ȃ��\���̂̔z���T���Aid = 0�iint�������l�j�̏ꏊ�ɏ���������
		if ((task_ptr + num2)->id == 0)
		{
			//id���ݒ肳��Ă��Ȃ�(id = 0)�z����g�p��,����id��z��ԍ��ɂ���Č��߂�
			(task_ptr + num2)->id = num2 + 1;
			
			while (1) {
				printf("�^�X�N�̃^�C�g������͂��Ă�������(�K�{)\n");
				fgets(line, sizeof(line), stdin);
				sscanf(line, "%s", (task_ptr + num2)->title);

				if ((task_ptr + num2)->title[0] == '\0') {
					printf("title�͕K���L�����Ă�������");
					continue;
				}else {
					break;
				}
			}

			printf("�^�X�N�̊�������͂��Ă�������\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->deadLine);

			printf("�^�X�N�̊T�v������΋L�����Ă�������\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->mainSubject);

			//���ݓ����E�������擾
			t = time(NULL);
			struct tm* local = localtime(&t);

			strftime((task_ptr + num2)->date, sizeof((task_ptr + num2)->date), "%Y/%m/%d %a %H:%M:%S", local);

			#define C_TASK (task_ptr + num2)

			fopen_s(&fp, "tasklist.txt", "a");
			fprintf(fp, "%d, %s, %s, %s, %s\n",
				C_TASK->id, C_TASK->title, C_TASK->deadLine, C_TASK->mainSubject, C_TASK->date);
			fclose(fp);
			
			break;
		}
		else 
		{	
			if (num2 == 9) {
				printf("�^�X�N���ő匏���ł��邽�߁A�V�K�o�^����ɂ̓^�X�N���폜���Ă�������\n");
				break;
			}
			//id���ݒ肳��Ă���ꍇ�́A�X�L�b�v����
			continue;
		}
	}
};