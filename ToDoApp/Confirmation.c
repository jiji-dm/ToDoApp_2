#define _CRT_SECURE_NO_WARNINGS	
#include "Confirmation.h"

/*
* task_ptr��task[num2]�̃|�C���^�ϐ�
*/

void confirmation(Task* task_ptr, int num) {

	while (1) {

		printf("ID = %d\n�^�C�g�� = %s\n�o�^�� = %s\n������ = %s\n�T�v = %s\n",
			task_ptr->id, task_ptr->title, task_ptr->date, task_ptr->deadLine, task_ptr->mainSubject);

		printf("[1:�ҏW] [2:�폜] [3:�߂�] \n");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &selectC);

		
		switch (selectC)
		{
		case 1:
			printf("�ҏW���܂�\n");
			update(&task, &task[num]);
			continue;

		case 2:
			delete(&task, &task[num]);
			break;

		case 3:
			break;

		default:
			printf("�������I������Ă��܂���\n");
			continue;
		}
		break;
	}
};