#define _CRT_SECURE_NO_WARNINGS		//VS��C++�R���p�C���̌x�����������

#include <stdio.h>
#include "Create.h"		
#include "Confirmation.h"
#include "Delete.h"
#include "MethodSelect.h"
#include "Update.h"

extern FILE* fp;				//�t�@�C���Ăяo�����߂̕ϐ�

extern char line[LINEMAX];		//sscanf�œǂݍ��ނ��߂̕ϐ�
extern char f_line[LINEMAX];

int main(void) {

	//������ɂ͏I����I���őI��
	while (1) {

		/*�e�L�X�g�t�@�C������f�[�^��ǂݍ��݁A
		�\���̕ϐ��Ɋi�[���Ă���id���P���珇�̔ԍ��ɂ��A
		���Ԃ���ёւ��邽�߂ɍX�V����
		*/

		/*** �t�@�C���̓ǂݍ��� ***/	
		//�t�@�C����ǂݍ��݃��[�h�ŊJ��
		fopen_s(&fp, "tasklist.txt", "r");

		int plus = 0;	//�\���̔z��̗v�f�ԍ��̏�����

		//�t�@�C���̒��g����s���\���̃����o�ϐ��ɑ�����Ă���
		while (fgets(f_line, LINEMAX, fp) != NULL){
			sscanf(f_line, "%d %[^,], %[^,], %[^,], %[^\n]",
				&task[plus].id, &task[plus].title, &task[plus].deadLine, &task[plus].mainSubject, &task[plus].date);
				
			//�^�X�NID�����Ԓʂ�ɂ���i�z��̗v�f�ԍ��ɂ����ID��ύX����)
			task[plus].id = plus + 1;
				
			plus++;
		}
		fclose(fp);

		/*** �t�@�C���̍X�V ***/		
		fopen_s(&fp, "tasklist.txt", "w");
		int m;
		#define M_TASK ()
		for (m = 0; m < TASKMAX; m++) {
			if (task[m].id != 0) {
				fprintf(fp, "%d %s, %s, %s, %s\n",
					task[m].id, task[m].title, task[m].deadLine, task[m].mainSubject, task[m].date);
			}
		}
		fclose(fp);

		/***�Ăяo�����\���̂��^�X�N�ꗗ�ɕ\�� (id + title + ����) ***/
		int i;	//�^�X�N�v�f�ԍ��̐錾
		printf("| TaskID | Title | ����  \n");

		for (i = 0; i < 10; i++)
		{
			if (task[i].id != 0) {
				printf("�E  %d  /  %s  /  %s   \n", task[i].id, task[i].title, task[i].deadLine);
			};
		};

		/***�^�X�N����̑I��***/
		printf("�^�X�N����𑀍�A�ԍ�����͂��Ă�������\n");
		printf("[1:�V�K�o�^] [2:�ڍ�] [3:�폜] [4:�I��] ");
		
		int select;			//�ŏ��̑I��ԍ�

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &select);

		//�I�����ꂽ�ԍ�(select)�ŏ�������
		switch (select)
		{
		case 1:
			create(&task);
			continue;

		case 2:
			printf("�ڍׂ�\������^�X�NID����͂��Ă�������\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%d", &select);

			methodSelect(0, select);
			continue;

		case 3:
			printf("�폜����^�X�NID����͂��Ă�������\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%d", &select);

			methodSelect(1, select);
			continue;

		case 4:
			printf("�I�����܂�\n");
			break;

		default:
			printf("���������l�����͂���Ă��܂���\n");
			continue;
		};

		break;
	};

	return 0;
};

