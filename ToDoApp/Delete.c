#define _CRT_SECURE_NO_WARNINGS	
#include "Delete.h"

/*
* p_task��task[0]�̃|�C���^�ϐ�
* task_ptr��task[num2]�̃|�C���^�ϐ�
*/

void delete(Task* p_task, Task* task_ptr) {
	
	//�I�΂ꂽ�z��ԍ��̍\���̂�������
	memset(task_ptr, 0, sizeof(task_ptr));
	printf("�^�X�N���폜���܂���");

	//�㏑�����[�h���g�p���A�t�@�C��������������B�i�O�̃t�@�C���͂Ȃ��Ȃ�j
	fopen_s(&fp, "tasklist.txt", "w");
	int d;

	for (d = 0; d < TASKMAX; d++) {
		if ((p_task + d)->id != 0) {
			fprintf(fp, "%d %s, %s, %s, %s\n",
				(p_task + d)->id, (p_task + d)->title, (p_task + d)->deadLine, (p_task + d)->mainSubject, (p_task + d)->date);
		}
	}
	fclose(fp);

	//�\���̂̔z��S�̂̏�����
	memset(p_task, 0, sizeof(task));

};