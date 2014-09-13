/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USET, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menuAdv1.c                                                           */
/*  PRINCIPAL AUTHOR      :  GuanLei                                                              */
/*  SUBSYSTEM NAME        :  menuAdv1                                                             */
/*  MODULE NAME           :  menuAdv1                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIST RELEASE  :  2014/09/13                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*revision log:
 *This is the 3th revision.
 *Created by GuanLei, 2014/09/13
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define DESC_LEN 	1024
#define CMD_NUM		10
#define CMD_MAX_LEN 10

int Help();

typedef struct DataNode
{
	char*	cmd;
	char*	desc;
	int     (* handler)();
	struct  DataNode *next;
} tDataNode;

static tDataNode head[] = 
{
	{"help","This is help cmd!", Help, &head[1]},
	{"version","menu program v1.0",NULL,NULL}
};

main()
{
	printf("menu list:\n");
	tDataNode *p = head;
	while(p != NULL)
	{
		printf("%s - %s\n", p ->cmd, p->desc);
		p = p->next;
	}
	
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("input a cmd number :");
		scanf("%s", cmd);
		tDataNode *p = head;
		p = head;
		while(p != NULL)
		{
			if(!strcmp(p->cmd, cmd))
			{
				printf("%s - %s\n",p->cmd,  p->desc);
				if(p->handler != NULL)
				{
					p->handler();
                }		
				break;
			}
			p = p->next;
		}
		if(p ==NULL)
		{
			printf("this is a wrong cmd\n");
		}
	}
}

int Help()
{
	printf("menu list:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p ->cmd, p->desc);
        p = p->next;
    }
	return 0;
} 

