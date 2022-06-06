#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

typedef struct {
	int id;					//�v���C�}���[�L�[�i�K�{�j
	char title[100];		//�薼�i�K�{�j
	char date[100];			//�o�^���i�K�{�j
	char deadLine[100];		//����
	char mainSubject[200];	//�T�v
}Task;

Task task[10];		//�^�X�N�̐��P�O��
//Task* task_ptr;		//task[0]�̃|�C���^�ϐ�


void create(Task *task_ptr);									//�V�K�o�^
void confirmation(Task* task_ptr);				//���e�m�F(�ҏW/�폜)
void delete(Task* task_ptr);					//�폜
void update(Task* task_ptr);			//�ҏW����User���͂������o�ϐ��Ɋi�[���郁�\�b�h
void methodSelect(int selectNum, int taskNum);	//�ύX/�폜������^�X�N��id�ƁA�g�p���郁�\�b�h����������ɂ�蓮��

time_t t;			//<time.h>��time_t�^���猻�ݓ������擾����


char line[100];		//sscanf�œǂݍ��ނ��߂̕ϐ�
int selectC;		//confirmation���̑I��ԍ�



int main(void) {
	
	

	//������ɂ͏I����I���őI��
	while (1) {

		//�^�X�N�ꗗ��\��������(id + title)
		int i;

		printf("| TaskID | Title | ����  \n");
		for (i = 0; i < 10; i++)
		{
			if (task[i].id != 0) {
				printf("�E  %d  /  %s  /  %s   \n", task[i].id, task[i].title, task[i].deadLine);
			};
		};

		//�I���t�F�[�Y
		printf("�^�X�N����𑀍�A�ԍ�����͂��Ă�������\n");
		printf("[1:�V�K�o�^] [2:�ڍ�] [3:�폜] [4:�I��] ");
		
		int select;			//�ŏ��̑I��ԍ�

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &select);

		//�I�����ꂽ�ԍ�(select)����������
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




void methodSelect(int selectNum, int taskNum) {
	
	//���͂��ꂽ�^�X�N�ԍ�(taskNum)�����邩�𔻒肵�A�ҏW���폜(selectNum)�Ń��\�b�h�̏��������s����
	int num1;
	
	for (num1 = 0; num1 < sizeof(task); num1++) {
		
		if (taskNum == task[taskNum - 1].id) {
			
			switch(selectNum)
			{
			case 0:
				confirmation(&task[taskNum - 1]);
				break;

			case 1:
				delete(&task[taskNum - 1]);
				break;

			default:
				break;
			}
			break;
		}else {
			printf("���͂��ꂽID��������܂���");
		}
	}
		
}

void create(Task *task_ptr) {
	printf("�V�K�o�^���܂�\n�\�����ꂽ���ڂ���͂��Ă�������\n");
	int num2;
	for (num2 = 0; num2 < sizeof(task_ptr); num2++) {
		if ((task_ptr + num2)->id == 0)
		{
			//id���ݒ肳��Ă��Ȃ�(id = 0)�z����g�p��,����id��z��ԍ��ɂ���Č��߂�
			(task_ptr + num2)->id = num2 + 1;
			
			printf("�^�X�N�̃^�C�g������͂��Ă�������(�K�{)\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->title);

			printf("�^�X�N�̊�������͂��Ă�������\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->deadLine);

			printf("�^�X�N�̊T�v������΋L�����Ă�������\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->mainSubject);

			//���ݓ����E�������擾
			t = time(NULL);
			struct tm* local = localtime(&t);

			strftime((task_ptr + num2)->date, sizeof((task_ptr + num2)->date), "%Y/%m/%d %a %H:%M:%S %A", local);
			
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

void confirmation(Task *task_ptr) {
	
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
			update(task_ptr);
			continue;

		case 2:
			delete(task_ptr);
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

void delete(Task* task_ptr) {
	memset(task_ptr, 0, sizeof(task));
	printf("�^�X�N���폜���܂���\n");
};

void update(Task* task_ptr) {

	printf("�^�X�N�̃^�C�g������͂��Ă�������(�K�{)\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr -> title);
	
	printf("�^�X�N�̊�������͂��Ă�������\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr -> deadLine);

	printf("�^�X�N�̊T�v������΋L�����Ă�������\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr -> mainSubject);

	//���ݓ����E�������擾
	t = time(NULL);
	struct tm* local = localtime(&t);

	strftime(task_ptr->date, sizeof(task_ptr ->date), "%Y/%m/%d %a %H:%M:%S %A", local);
}
