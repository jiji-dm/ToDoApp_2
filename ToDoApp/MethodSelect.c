#define _CRT_SECURE_NO_WARNINGS	
#include "MethodSelect.h"


void methodSelect(int selectNum, int taskNum) {

	//���͂��ꂽ�^�X�N�ԍ�(taskNum)�����邩�𔻒肵�A�ҏW���폜(selectNum)�Ń��\�b�h�̏��������s����
	int num1;
	int num2 = taskNum - 1;

	for (num1 = 0; num1 < TASKMAX; num1++) {

		if (taskNum == task[num2].id) {

			switch (selectNum)
			{
			case 0:
				confirmation(&task[num2], num2);
				break;

			case 1:
				delete(&task, &task[num2]);
				break;

			default:
				break;
			}
			break;
		}
		else {
			printf("���͂��ꂽID��������܂���");
		}
	}

}