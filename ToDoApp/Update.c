#define _CRT_SECURE_NO_WARNINGS	
#include "Update.h"

void update(Task* p_task, Task* task_ptr) {

	while (1) {
		
		printf("�^�X�N�̃^�C�g������͂��Ă�������(�K�{)\n");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%s", task_ptr->title);

		if (task_ptr->title[0] == '\0') {
			printf("title�͕K���L�����Ă�������");
			continue;
		}
		else {
			break;
		}
	}

	printf("�^�X�N�̊�������͂��Ă�������\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr->deadLine);

	printf("�^�X�N�̊T�v������΋L�����Ă�������\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr->mainSubject);

	//���ݓ����E�������擾
	t = time(NULL);
	struct tm* local = localtime(&t);

	strftime(task_ptr->date, sizeof(task_ptr->date), "%Y/%m/%d %a %H:%M:%S %A", local);

	//�ҏW�O��txt�t�@�C���ɕҏW���e���㏑������

	fopen_s(&fp, "tasklist.txt", "w");
	int u;

	for (u = 0; u < TASKMAX; u++) {
		if ((p_task + u)->id != 0) {
			
			fprintf(fp, "%d %s, %s, %s, %s\n",
				(p_task + u)->id, (p_task + u)->title, (p_task + u)->deadLine, (p_task + u)->mainSubject, (p_task + u)->date);
		}
	}
	fclose(fp);
}


