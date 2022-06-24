#pragma once			//�����̃t�@�C������include����Ă���d��`��j�~�ł���
#ifndef _CREATE_H		//ifndef �� _METHOD_H�̒�`���Ȃ����endif�܂ł��`����
#define _CREATE_H		//_METHOD_H���`�����̂Ŏ���Method.h���Ă΂ꂽ�ۂɃX�L�b�v����B

/* �yCreate.h�z��include�����t�@�C���͈ȉ��̐錾��錾�����Ɏg�p�ł��� */

#include <stdio.h>
#include <time.h>

#define TITLEMAX 100				//�\���̃����o title������̔z��
#define DATEMAX 100					//�\���̃����o date������̔z��
#define SUBJECTMAX 200				//�\���̃����o subObject������̔z��
#define TASKMAX 10					//Task�^ task�ϐ��̔z��
#define LINEMAX 100					//���[�U���͂̍ۂ̓��͗e��

typedef struct {
	int id;							//�v���C�}���[�L�[�i�K�{�j
	char title[TITLEMAX];			//�薼
	char date[DATEMAX];				//�o�^��
	char deadLine[DATEMAX];			//����
	char mainSubject[SUBJECTMAX];	//�T�v
}Task;

Task task[TASKMAX];					//�^�X�N�̗v�f�� 10��


time_t t;			//<time.h>��time_t�^���猻�ݓ������擾����
FILE* fp;			//�t�@�C���Ăяo�����߂̕ϐ�

char line[LINEMAX];		//sscanf�œǂݍ��ނ��߂̕ϐ�
int selectC;		//confirmation���̑I��ԍ�

char f_line[LINEMAX];

void create(Task*);					//���̃t�@�C����include�����ۂɃ��\�b�h���Q�Ƃł���悤�ɂ���


#endif // !_CREATE_H